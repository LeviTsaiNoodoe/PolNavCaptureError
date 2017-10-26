//
//  ViewController.swift
//  PolNavCaptureError
//
//  Created by LeviTsai on 2017/9/4.
//  Copyright © 2017年 LeviTsai. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    @IBOutlet weak fileprivate var upperImageView: UIImageView!
    
    var junctions = [(String,UIImage, String)]()
    
    
    
    var queue = OperationQueue()
    
    fileprivate let carIcon = UIImage(named: "carIcon")
    
    
    override func viewDidLoad() {
        super.viewDidLoad()
        PolnavSDKShell.add(self)
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    override var prefersStatusBarHidden: Bool{
        return true
    }
    
    @IBAction func route(_ sender: Any) {
        
        /*
         25.058161, 121.606655
         25.052349, 121.607910
         25.050969, 121.595550
         25.054876, 121.594595
         25.058161, 121.606655
         */
        
        
        let start = LocationCoordinate(longitude: 12160665, latitude: 2505816)

        var points = NSMutableArray()
        points.add(LocationCoordinate(longitude: 12160791, latitude: 2505234))
        points.add(LocationCoordinate(longitude: 12159555, latitude: 2505096))
        points.add(LocationCoordinate(longitude: 12159459, latitude: 2505487))
        points.add(LocationCoordinate(longitude: 12160665, latitude: 2505816))



        PolnavSDKShell.doRoute(withStartLocation: start, destinations: points)
    }
    
    fileprivate func addCustomIcon( image: UIImage, location: CGPoint) -> UIImage? {
        
        return autoreleasepool(invoking: { () -> UIImage? in
            
            UIGraphicsBeginImageContext(image.size)
            
            guard let ctx = UIGraphicsGetCurrentContext() else {
                UIGraphicsEndImageContext()
                return nil
            }
            
            image.draw(in: CGRect(x: 0, y: 0, width: image.size.width, height: image.size.height))
            
            let rect = CGRect(x: location.x - 10, y: image.size.height - location.y + 10, width: 20, height: 20)
            self.carIcon?.draw(in: rect)
            
            let returnImage = UIGraphicsGetImageFromCurrentImageContext()
            UIGraphicsEndImageContext()
            //            completion(returnImage)
            return returnImage
            
        })
    }
    
    
}

extension ViewController: PolnavRouteDelegate {
    
    fileprivate func getJunction3DView() -> [(String,UIImage, String)] {
        var NDBlue = UIColor(red: 0x1D/255.0, green: 0x86/255.0, blue: 0xE3/255.0, alpha: 1)
        var NDRed = UIColor(red: 0xE3/255.0, green: 0x09/255.0, blue: 0x14/255.0, alpha: 1)
        var count = 0
        
        
        DispatchQueue.main.sync {
            count = PolnavSDKShell.turnInfoCount()
        }
        
        
        var array = [(String,UIImage, String)]()
        
        
        
        let condition = NSCondition()
        var predicate = true
        
        for _index in 0 ..< count {
            condition.lock()
            predicate = true
            DispatchQueue.main.sync {
                PolnavSDKShell.captureNaviImage(with: CaptureType.juntionView3D, imageSize: CGSize(width: 265, height: 265),
                                                zoomScale: 0,
                                                isShowLabel: false,
                                                isShowPOI: false,
                                                isShowOneWay: false,
                                                isShowSpeedCamera: false,
                                                isShowCar: false,
                                                junctionIndex: UInt(_index),
                                                junctionColor: NDRed,
                                                junctionDistance: 500,
                                                dayNightMode: .auto,
                                                captureHandler: { (data, error) in
                                                    
                                                    condition.lock()
                                                    defer{
                                                        predicate = false
                                                        condition.signal()
                                                        condition.unlock()
                                                    }
                                                    
                                                    array.append((data!.turnSignature, data!.capturedImage, data!.imageAttributeDescription))
                })
            }
            
            while predicate {
                condition.wait()
            }
            
            condition.unlock()
            
        }
        
        return array
        
    }
    
    // Mark PolnavRouteDelegate
    func onRoutingCalculateFinish() {
        print("onRoutingCalculateFinish")
        DispatchQueue.global().async {
            self.junctions = self.getJunction3DView()
            
            DispatchQueue.main.sync {
                PolnavSDKShell.startSimulate()
            }
            
            
            
            
            self.queue.addOperation {
                
                
                while true {
                    
                    var nav: NaviMatrixData!
                    
                    DispatchQueue.main.sync {
                        nav = PolnavSDKShell.naviMatrixData()
                    }
                    
                    let (sig, image, des) = self.junctions.first(where: { (arg0) -> Bool in
                        let (turn, image, des) = arg0
                        return nav.nextTurnInfoData.signature == turn
                    })!
                    
                    var p: PolnavPoint?
                    
                    DispatchQueue.main.sync {
                        p = PolnavSDKShell.transformLocation(toCapturedImagePosition: LocationCoordinate(longitude: nav.currentCarLocation.longitude,
                                                                                                         latitude: nav.currentCarLocation.latitude),
                                                             contextAttr: des as! String)
                    }
                    
                    let i = self.addCustomIcon(image: image, location: CGPoint(x: (p?.x)!, y: (p?.y)!))
                    
                    DispatchQueue.main.sync {
                        self.upperImageView.image = i
                    }
                    
                    Thread.sleep(forTimeInterval: 0.2)
                }
                
                
            }
        }
    }
    
    func onCalculateFailed(with index: Int) {
        print("onCalculateFailed:\(index)")
    }
    
    func onReachDestination(_ index: UInt) {
        print("onReachDestination:\(index)")
    }
    
    func onUpdateRoutingProgress(withProgress progress: Int) {
        print("onUpdateRoutingProgress:\(progress)")
    }
}
