//
//  PolnavManager.swift
//  Sunray
//
//  Created by LeviTsai on 2018/4/13.
//  Copyright © 2018年 Noodoe. All rights reserved.
//

import Foundation

open class _polnavViewController: PolnavViewController {
    
}

extension Notification.Name {
    static public let MapInstallFailedNotification  = Notification.Name( rawValue: "MapInstallFailed")
    static public let MapCCValueChangedNotification = Notification.Name( rawValue: "MapCCValueChanged")
}

public protocol PolnavManagerDataSource {
    func noodoeUUID() -> String
}

public class PolnavManager: NSObject {
    
    typealias polnavSDKShell = PolnavSDKShell
    
    private static var _installedObject: PolnavManager!
    public static var `default`: PolnavManager {
        return _installedObject
    }
    
    var datasource: PolnavManagerDataSource!
    
    public private(set) var navigationConfigure = NavigationConfigure()
    public private(set) var captureImageQueue: OperationQueue = {
        let queue = OperationQueue()
        queue.maxConcurrentOperationCount = 1
        return queue
    }()
    
    private(set) var queryFTSQueue = OperationQueue()
    public private(set) var mapCCValueHasChanged = false
    
    enum UpdateProductMapVoiceInfoStatus {
        case updating
        case stop
        case success
        case fail
    }
    
    private var updateProductMapVoiceInfoStatus: UpdateProductMapVoiceInfoStatus = .stop
    private var updateCondition = NSCondition()
    private var updatePredicate = true
    
    enum InstallLicenseKeyWithMapNameStatus {
        case updating
        case stop
        case success
        case fail
    }
    
    private var installLicenseKeyWithMapName: InstallLicenseKeyWithMapNameStatus = .stop
    private var installCondition = NSCondition()
    private var installPredicate = true
    
    private var apsFolder: URL {
        return URL(fileURLWithPath: (NSSearchPathForDirectoriesInDomains(.documentDirectory, .userDomainMask, true))[0])
    }
    
    var polnavMobileFolder: URL {
        var document = self.apsFolder
        document.appendPathComponent("PolnavMobile")
        return document
    }

    public var polnavMobileMapFolder: URL {
        return self.polnavMobileFolder.appendingPathComponent("Map")
    }
    
    public var polnavMobileSoundFolder: URL {
        return self.polnavMobileFolder.appendingPathComponent("Sound")
    }
    
    public var polnavServerProductInfoDataUrl: URL {
        return self.polnavMobileFolder.appendingPathComponent("polnavServerProductInfoData")
    }
    
    public var polnavServerMapInfoDataUrl: URL {
        return self.polnavMobileFolder.appendingPathComponent("PolnavServerMapInfoData")
    }

    public var mapInfoList: [PolnavServerMapInfoData] {
        return (NSKeyedUnarchiver.unarchiveObject(withFile: self.polnavServerMapInfoDataUrl.path) as? [PolnavServerMapInfoData]) ?? [PolnavServerMapInfoData]()
    }
    
    public var productInfoList: [PolnavServerProductInfoData] {
        return (NSKeyedUnarchiver.unarchiveObject(withFile: self.polnavServerProductInfoDataUrl.path) as? [PolnavServerProductInfoData]) ?? [PolnavServerProductInfoData]()
    }
    
    public var mapsExist: [String] {
        var maps = [String]()
        try? FileManager.default.contentsOfDirectory(at: self.polnavMobileMapFolder, includingPropertiesForKeys: [.isDirectoryKey], options: .skipsHiddenFiles).forEach { (url) in
            let attr = try! FileManager.default.attributesOfItem(atPath: url.path)
            let type = attr[.type] as! FileAttributeType
            if type == .typeDirectory {
                maps.append(url.lastPathComponent)
            }
        }
        return maps
    }
    
    public var voicesExist: [String] {
        var voices = [String]()
        try? FileManager.default.contentsOfDirectory(at: self.polnavMobileSoundFolder, includingPropertiesForKeys: [.isDirectoryKey], options: .skipsHiddenFiles).forEach { (url) in
            let attr = try! FileManager.default.attributesOfItem(atPath: url.path)
            let type = attr[.type] as! FileAttributeType
            if type == .typeDirectory {
                voices.append(url.lastPathComponent)
            }
        }
        return voices
    }

    private var keyValueObservations = [NSKeyValueObservation]()
    
    #if DEBUG
    var imageFolder: URL {
        return try! FileManager.default.url(for: FileManager.SearchPathDirectory.documentDirectory, in: FileManager.SearchPathDomainMask.userDomainMask, appropriateFor: nil, create: false).appendingPathComponent("ChinaTestImages")
    }
    #endif

    deinit {
        keyValueObservations.forEach { $0.invalidate()}
    }

    public class func install(with dataource: PolnavManagerDataSource){
        if self._installedObject == nil {
            self._installedObject = PolnavManager(with: dataource)
        }
    }
    
    private override init() {
    }
    
    private init(with _datasource: PolnavManagerDataSource) {
        Logger.info("")
        super.init()
        self.datasource = _datasource
        polnavSDKShell.add(self as PolnavLicenseDelegate)
        self.copyMapResourceFolder()
    }
    
    fileprivate func copyMapResourceFolder() {
        let filemanager = FileManager.default
        let soureUrl = Bundle(for: type(of: self)).url(forResource: "PolnavMobile", withExtension: nil)!
        let destination = self.polnavMobileFolder
        if !filemanager.fileExists(atPath: destination.path) {
            do {
                try filemanager.copyItem(at: soureUrl, to: destination)
            } catch  {
                print(error)
            }
        }
    }
    
    public func loadPolnavMobileFolder( product: [String: TimeInterval], displacement: UInt) {

        let phoneIDFV : String! = UIDevice.current.identifierForVendor!.uuidString
        let mapExpiredLists = NSMutableArray()
        product.forEach { (productName, timeinterval) in
            var mapExpiredData : MapWarrantyData
            let tomorrowExpiredDate = Date(timeIntervalSince1970: timeinterval )
            mapExpiredData = MapWarrantyData.init(mapName: productName, expiredDate: tomorrowExpiredDate)
            mapExpiredLists.add(mapExpiredData)
        }
        
        let s = datasource?.noodoeUUID().isEmpty ?? true ? "DefaultUUID" : datasource?.noodoeUUID()
        
        let sdkInitStatus = polnavSDKShell.start(withResourcePath: self.polnavMobileFolder.path + "/",
                                                 noodoeUUID:  s!,
                                                 phoneID: phoneIDFV!,
                                                 mapWarrantyList: mapExpiredLists,
                                                 motorCCValue: UInt(displacement))
 
        print("loadPolnavMobileFolder displacement:\(displacement) sdkInitStatus:\(sdkInitStatus.rawValue)")
        
        DispatchQueue.global().async {
            self.updateProductMapVoiceInfo()
        }
        
        self.polnavdefaultSetting()

        keyValueObservations.append(self.navigationConfigure.observe(\.dayNightMode,options: [.initial, .new, .old]) { (configure, change) in
            polnavSDKShell.configDayNightMode(self.navigationConfigure.dayNightMode)
            }
        )
        
        keyValueObservations.append( self.navigationConfigure.observe(\.routePriority,options: [.initial, .new, .old]) { (configure, change) in
            self.refreshRoutePlanOption()
            }
        )
        
        keyValueObservations.append( self.navigationConfigure.observe(\.avoidHighways,options: [.initial, .new, .old]) { (configure, change) in
            self.refreshRoutePlanOption()
            }
        )
        
        keyValueObservations.append( self.navigationConfigure.observe(\.avoidTolls,options: [.initial, .new, .old]) { (configure, change) in
            self.refreshRoutePlanOption()
            }
        )
        
        keyValueObservations.append( self.navigationConfigure.observe(\.avoidFerries,options: [.initial, .new, .old]) { (configure, change) in
            self.refreshRoutePlanOption()
            }
        )

    }
    
    fileprivate func polnavdefaultSetting() {
        polnavSDKShell.configVolumeMute(true)
        polnavSDKShell.configGPSEnable(false)
        polnavSDKShell.configSpeedCameraAleartDistance(.distanceAuto)
        polnavSDKShell.configMapDrawItinerary(withDrawStartPoint: false, drawWayPoint: false, drawDestination: false)
        polnavSDKShell.configRepeatSimulateNavi(false)
    }
    
    /*
     make sure call this function in second thread
     */
    public func updateProductMapVoiceInfo() {
        
        guard self.updateProductMapVoiceInfoStatus != .updating else {
            return
        }
        
        self.updateProductMapVoiceInfoStatus = .updating
        self.updatePredicate = true
        self.updateCondition.lock()
        DispatchQueue.main.sync {
            polnavSDKShell.updateProductMapVoiceInfo()
        }
        self.updateCondition.wait(until: Date(timeIntervalSinceNow: 10))
        self.updateCondition.unlock()
        
        if self.updateProductMapVoiceInfoStatus == .success {
            //keep PolnavServerProductInfoData
            var _products = [CustomPolnavServerProductInfoData]()
            var products: [PolnavServerProductInfoData]?
            DispatchQueue.main.sync {
                products = polnavSDKShell.polnavServerProductInfoDataList() as? [PolnavServerProductInfoData]
            }
            products?.forEach { (data) in
                _products.append(CustomPolnavServerProductInfoData(with: data))
            }
            NSKeyedArchiver.archiveRootObject(_products, toFile: self.polnavServerProductInfoDataUrl.path)
            //keep PolnavServerMapInfoData
            var _maps = [CustomPolnavServerMapInfoData]()
            var maps: [PolnavServerMapInfoData]?
            DispatchQueue.main.sync {
                maps = polnavSDKShell.polnavServerMapInfoDataList() as? [PolnavServerMapInfoData]
            }
            
            
            
            
            maps?.forEach { (data) in
                _maps.append(CustomPolnavServerMapInfoData(with: data))
            }
            NSKeyedArchiver.archiveRootObject(_maps, toFile: self.polnavServerMapInfoDataUrl.path)
        }
    }
    
    public func installLicenseKey(with mapName: String, mapCode: String, reason: String, productDisplayName: String, complete: @escaping () -> Void ) {
        let _mapInfoData = self.mapInfoList.first { return $0.mapName == mapName }
        
        guard false == _mapInfoData?.isKeyInstalled, let mapInfoData = _mapInfoData else {
            complete()
            return
        }
        
        if self.installLicenseKeyWithMapName != .updating {
            self.installLicenseKeyWithMapName = .updating
            self.installPredicate = true
            self.installCondition.lock()
            polnavSDKShell.installLicenseKey(withMapName: mapName, mapCode: mapCode, reason: reason, productName: productDisplayName)
            self.installCondition.wait(until: Date(timeIntervalSinceNow: 10))
            self.installCondition.unlock()
            if true == mapInfoData.isMapInstalled {
                NotificationCenter.default.post(name: NSNotification.Name.MapInstallFailedNotification, object: nil, userInfo:["MAP_NAME": mapInfoData.mapName])
            }
            complete()
        }
    }
    
    private func refreshRoutePlanOption(){
        polnavSDKShell.setRoutePlanOption(RoutePlanOptionData(routePriority: self.navigationConfigure.routePriority,
                                                              isAvoidHighway: self.navigationConfigure.avoidHighways,
                                                              isAvoidTollway: self.navigationConfigure.avoidTolls,
                                                              isAvoidTrail: true,
                                                              isAvoidFerry: self.navigationConfigure.avoidFerries))
    }
}

extension PolnavManager: PolnavLicenseDelegate {
    // MARK: - PolnavLicenseDelegate
    public func updateProductMapVoiceInfoSuccess() {
        //        print("\(#function)")
        self.updateCondition.lock()
        self.updateProductMapVoiceInfoStatus = .success
        self.updatePredicate = false
        self.updateCondition.signal()
        self.updateCondition.unlock()
    }
    
    public func updateProductMapVoiceInfoFailed() {
        //        print("\(#function)")
        self.updateCondition.lock()
        self.updateProductMapVoiceInfoStatus = .fail
        self.updatePredicate = false
        self.updateCondition.signal()
        self.updateCondition.unlock()
    }
    
    public func installLicenseKeySuccess(withMapName mapName: String!, mapCode: String!) {
        //        print("\(#function)")
        self.installCondition.lock()
        self.installLicenseKeyWithMapName = .success
        self.installPredicate = false
        self.installCondition.signal()
        self.installCondition.unlock()
    }
    
    public func installLicenseKeyFailed(withMapName mapName: String!, mapCode: String!) {
        //        print("\(#function)")
        self.installCondition.lock()
        self.installLicenseKeyWithMapName = .fail
        self.installPredicate = false
        self.installCondition.signal()
        self.installCondition.unlock()
    }
    
    public func mapCCValueChanged() {
        NotificationCenter.default.post(name: NSNotification.Name.MapCCValueChangedNotification, object: nil)
    }    
}
