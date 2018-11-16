//
//  PolWrapperDefine.swift
//  Sunray
//
//  Created by LeviTsai on 2017/8/15.
//  Copyright © 2017年 Noodoe. All rights reserved.
//

import Foundation
import MapKit

public struct JunctionInfo {
    public let turnsymbol: String
    public let signature: String
    public let streetName: String
    public let formatDistanceValue: String
    public let formatDistanceUnit: String
    public let distance: Int
    public let turnSymbolImage: UIImage?
}

public class PolnavWrapperPointRecord: NSObject, NSCoding {
    
    public let shownLocation: CLLocationCoordinate2D
    public let routedLocation: CLLocationCoordinate2D
    public let type: PolnavPointRecordType
    public let name: String
    public let countryName: String
    public let countryLocalName: String
    public let cityName: String
    public let phoneNumber: String?
    public let formatDistanceValue: String
    public let formatDistanceUnit: String
    public let distance: CGFloat
    public let directionToCarHead: CGFloat
    public let objectId = Date().timeIntervalSince1970*10000000
    
    enum Key: String {
        case shownLocation
        case routedLocation
        case type
        case name
        case countryName
        case countryLocalName
        case cityName
        case phoneNumber
        case formatDistanceValue
        case formatDistanceUnit
        case distance
        case directionToCarHead
        case objectId
    }

    public init(
        shownLocation: CLLocationCoordinate2D,
        routedLocation: CLLocationCoordinate2D,
        type: PolnavPointRecordType = .default,
        name: String = "",
        countryName: String = "",
        countryLocalName: String = "",
        cityName: String = "",
        phoneNumber: String? = nil,
        formatDistanceValue: String = "",
        formatDistanceUnit: String = "",
        distance: CGFloat = 0.0,
        directionToCarHead: CGFloat = 0.0
        ) {
        self.shownLocation = shownLocation
        self.routedLocation = routedLocation
        self.type = type
        self.name = name
        self.countryName = countryName
        self.countryLocalName = countryLocalName
        self.cityName = cityName
        self.phoneNumber = phoneNumber
        self.formatDistanceValue = formatDistanceValue
        self.formatDistanceUnit = formatDistanceUnit
        self.distance = distance
        self.directionToCarHead = directionToCarHead
        
        super.init()
    }
    
    public init(_ data: NDPoiData) {
        self.shownLocation = data.showLocation
        self.routedLocation = data.routedLocation
        self.type = .poi
        self.name = data.name
        self.countryName = data.countryName
        self.countryLocalName = data.countryLocalName
        self.cityName = data.cityName
        self.phoneNumber = data.phoneNumber
        self.formatDistanceValue = data.formatDistance.0
        self.formatDistanceUnit = data.formatDistance.1
        self.distance = CGFloat(data.distance)
        self.directionToCarHead = CGFloat(data.directionToCarHead)
    }
    
    
    public func encode(with aCoder: NSCoder) {
        
        aCoder.encode( shownLocation.latitude , forKey: Key.shownLocation.rawValue + "latitude")
        aCoder.encode( shownLocation.longitude , forKey: Key.shownLocation.rawValue + "longitude")
        
        aCoder.encode( routedLocation.latitude , forKey: Key.routedLocation.rawValue + "latitude")
        aCoder.encode( routedLocation.longitude , forKey: Key.routedLocation.rawValue + "longitude")

        aCoder.encode(type.rawValue, forKey: Key.type.rawValue)
        aCoder.encode(name, forKey: Key.name.rawValue)
        aCoder.encode(countryName, forKey: Key.countryName.rawValue)
        aCoder.encode(countryLocalName, forKey: Key.countryLocalName.rawValue)
        aCoder.encode(cityName, forKey: Key.cityName.rawValue)
        aCoder.encode(phoneNumber, forKey: Key.phoneNumber.rawValue)
        aCoder.encode(formatDistanceValue, forKey: Key.formatDistanceValue.rawValue)
        aCoder.encode(formatDistanceUnit, forKey: Key.formatDistanceUnit.rawValue)
        aCoder.encode(distance, forKey: Key.distance.rawValue)
        aCoder.encode(directionToCarHead, forKey: Key.directionToCarHead.rawValue)
    }
    
    required public init?(coder aDecoder: NSCoder) {
        
        let shownLatitude = aDecoder.decodeDouble(forKey: Key.shownLocation.rawValue + "latitude")
        let shownLongitude = aDecoder.decodeDouble(forKey: Key.shownLocation.rawValue + "longitude")
        shownLocation = CLLocationCoordinate2D(latitude: shownLatitude, longitude: shownLongitude)
        
        let routeLatitude = aDecoder.decodeDouble(forKey: Key.routedLocation.rawValue + "latitude")
        let routeLongitude = aDecoder.decodeDouble(forKey: Key.routedLocation.rawValue + "longitude")
        routedLocation = CLLocationCoordinate2D(latitude: routeLatitude, longitude: routeLongitude)
        
        let typeRawValue = UInt( aDecoder.decodeObject(forKey: Key.type.rawValue) as! Int )
        type =  PolnavPointRecordType(rawValue: typeRawValue)!
        
        name = aDecoder.decodeObject(forKey: Key.name.rawValue) as? String ?? ""
        countryName = aDecoder.decodeObject(forKey: Key.countryName.rawValue) as? String ?? ""
        countryLocalName = aDecoder.decodeObject(forKey: Key.countryLocalName.rawValue) as? String ?? ""
        cityName = aDecoder.decodeObject(forKey: Key.cityName.rawValue) as? String ?? ""
        phoneNumber = aDecoder.decodeObject(forKey: Key.phoneNumber.rawValue) as? String
        formatDistanceValue = aDecoder.decodeObject(forKey: Key.formatDistanceValue.rawValue) as? String ?? ""
        formatDistanceUnit = aDecoder.decodeObject(forKey: Key.formatDistanceUnit.rawValue) as? String ?? ""
        distance = aDecoder.decodeObject(forKey: Key.distance.rawValue) as? CGFloat ?? 0.0
        directionToCarHead = aDecoder.decodeObject(forKey: Key.directionToCarHead.rawValue) as? CGFloat ?? 0.0
    }
}

public class NDPoiData {
    public let ObjectId = Date().timeIntervalSince1970*10000000
    
    public let type: Int32
    public let name: String
    public let cityName: String
    public let countryName: String
    public let countryLocalName: String
    public let phoneNumber: String
    public let distance: Int
    public let formatDistance: (String, String)
    public let directionToCarHead: Int
    public let icon: UIImage?
    public let showLocation: CLLocationCoordinate2D
    public let routedLocation: CLLocationCoordinate2D
    
    public init(_ data: PolnavPoiData) {
        
        self.type = data.type
        self.name = data.name
        self.countryName = data.countryName
        self.countryLocalName = data.countryLocalName
        self.cityName = data.cityName
        self.phoneNumber = data.phoneNumber
        self.distance = data.distance
        self.formatDistance = (data.formatDistance.value, data.formatDistance.unit)
        self.directionToCarHead = data.directionToCarHead
        self.icon = data.icon
        self.showLocation = CLLocationCoordinate2D(latitude: CLLocationDegrees(Double(data.shownLocation.latitude)/100000), longitude: CLLocationDegrees(Double(data.shownLocation.longitude)/100000))
        self.routedLocation = CLLocationCoordinate2D(latitude: CLLocationDegrees(Double(data.routedLocation.latitude)/100000), longitude: CLLocationDegrees(Double(data.routedLocation.longitude)/100000))
    }
    
    public init(_ data: FtsResultData) {
        
        self.type = Int32(data.type.rawValue)
        self.name = data.name
        self.countryName = ""
        self.countryLocalName = ""
        self.cityName = data.cityName
        self.phoneNumber = data.phoneNumber ?? ""
        self.distance = data.distance
        self.formatDistance = (data.formatDistance.value, data.formatDistance.unit)
        self.directionToCarHead = data.directionToCarHead
        self.icon = data.poiIcon
        self.showLocation = CLLocationCoordinate2D(latitude: CLLocationDegrees(Double(data.shownLocation.latitude)/100000), longitude: CLLocationDegrees(Double(data.shownLocation.longitude)/100000))
        self.routedLocation = CLLocationCoordinate2D(latitude: CLLocationDegrees(Double(data.routedLocation.latitude)/100000), longitude: CLLocationDegrees(Double(data.routedLocation.longitude)/100000))
    }
}

public extension PolnavWrapperPointRecord {
    public var showRoadName: String {
        let roadName: String
        if self.type == .coordinate {
            roadName = self.cityName
        } else {
            if self.name.range(of: "anonymous_road") != nil {
                roadName = NSLocalizedString("NavigateService.Street.AnonymousRoad", comment: "anonymous road")
            } else {
                roadName = self.name
            }
        }
        return roadName
    }
}

extension JunctionInfo {
    public var showRoadName: String {
        let roadName: String
        if self.streetName.range(of: "anonymous_road") != nil {
            roadName = NSLocalizedString("NavigateService.Street.AnonymousRoad", comment: "anonymous road")
        } else {
            roadName = self.streetName
        }
        return roadName
    }
}

public class CustomPolnavServerProductInfoData: PolnavServerProductInfoData, NSCoding {
    
    public init(with serverData: PolnavServerProductInfoData) {
        super.init()
        self.productDisplayName = serverData.productDisplayName
        self.productDisplayLocalName = serverData.productDisplayLocalName
        self.mapDisplayName = serverData.mapDisplayName
        self.mapDisplayLocalName = serverData.mapDisplayLocalName
        self.mapName = serverData.mapName
    }
    
    enum CodingKeys: String, CodingKey {
        case productDisplayName
        case productDisplayLocalName
        case mapDisplayName
        case mapDisplayLocalName
        case mapName
    }
    
    public func encode(with aCoder: NSCoder){
        aCoder.encode(self.productDisplayName, forKey: CodingKeys.productDisplayName.rawValue)
        aCoder.encode(self.productDisplayLocalName, forKey: CodingKeys.productDisplayLocalName.rawValue)
        aCoder.encode(self.mapDisplayName, forKey: CodingKeys.mapDisplayName.rawValue)
        aCoder.encode(self.mapDisplayLocalName, forKey: CodingKeys.mapDisplayLocalName.rawValue)
        aCoder.encode(self.mapName, forKey: CodingKeys.mapName.rawValue)
        
    }
    
    public required init?(coder aDecoder: NSCoder) {
        super.init()
        
        self.productDisplayName = aDecoder.decodeObject(forKey: CodingKeys.productDisplayName.rawValue) as! String
        self.productDisplayLocalName = aDecoder.decodeObject(forKey: CodingKeys.productDisplayLocalName.rawValue) as! String
        self.mapDisplayName = aDecoder.decodeObject(forKey: CodingKeys.mapDisplayName.rawValue) as! String
        self.mapDisplayLocalName = aDecoder.decodeObject(forKey: CodingKeys.mapDisplayLocalName.rawValue) as! String
        self.mapName = aDecoder.decodeObject(forKey: CodingKeys.mapName.rawValue) as! String
        
    }
}

public class CustomPolnavServerMapInfoData: PolnavServerMapInfoData, NSCoding {
    
    public init(with serverMapData: PolnavServerMapInfoData) {
        super.init()
        self.mapName = serverMapData.mapName
        self.mapFileName = serverMapData.mapFileName
        self.buildDate = serverMapData.buildDate
        self.mapCode = serverMapData.mapCode
        self.fileSize = serverMapData.fileSize
        self.fullFileSize = serverMapData.fullFileSize
        self.warrantyStatus = serverMapData.warrantyStatus
        self.isKeyInstalled = serverMapData.isKeyInstalled
        self.isMapInstalled = serverMapData.isMapInstalled
    }
    
    enum CodingKeys: String, CodingKey {
        case mapName
        case mapFileName
        case buildDate
        case mapCode
        case fileSize
        case fullFileSize
        case warrantyStatus
        case isKeyInstalled
        case isMapInstalled
    }
    
    public func encode(with aCoder: NSCoder){
        aCoder.encode(self.mapName, forKey: CodingKeys.mapName.rawValue)
        aCoder.encode(self.mapFileName, forKey: CodingKeys.mapFileName.rawValue)
        aCoder.encode(self.buildDate, forKey: CodingKeys.buildDate.rawValue)
        aCoder.encode(self.mapCode, forKey: CodingKeys.mapCode.rawValue)
        aCoder.encode(self.fileSize, forKey: CodingKeys.fileSize.rawValue)
        aCoder.encode(self.fullFileSize, forKey: CodingKeys.fullFileSize.rawValue)
        aCoder.encode(self.warrantyStatus.rawValue, forKey: CodingKeys.warrantyStatus.rawValue)
        aCoder.encode(self.isKeyInstalled, forKey: CodingKeys.isKeyInstalled.rawValue)
        aCoder.encode(self.isMapInstalled, forKey: CodingKeys.isMapInstalled.rawValue)
    }
    
    public required init?(coder aDecoder: NSCoder) {
        super.init()
        
        self.mapName = aDecoder.decodeObject(forKey: CodingKeys.mapName.rawValue) as! String
        self.mapFileName = aDecoder.decodeObject(forKey: CodingKeys.mapFileName.rawValue) as! String
        self.buildDate = aDecoder.decodeObject(forKey: CodingKeys.buildDate.rawValue) as! Date
        self.mapCode = aDecoder.decodeObject(forKey: CodingKeys.mapCode.rawValue) as! String
        self.fileSize = aDecoder.decodeObject(forKey: CodingKeys.fileSize.rawValue) as! CGFloat
        self.fullFileSize = aDecoder.decodeObject(forKey: CodingKeys.fullFileSize.rawValue) as! CGFloat
        self.warrantyStatus = MapStatus(rawValue: ((aDecoder.decodeObject(forKey: CodingKeys.warrantyStatus.rawValue) as? Int) ?? 0 ) ) ?? .UNKNOWN
        self.isKeyInstalled = aDecoder.decodeBool(forKey: CodingKeys.isKeyInstalled.rawValue)
        self.isMapInstalled = aDecoder.decodeBool(forKey: CodingKeys.isMapInstalled.rawValue)
        
    }
}
