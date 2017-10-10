//
//  ViewController.swift
//  PolNavCaptureError
//
//  Created by LeviTsai on 2017/9/4.
//  Copyright © 2017年 LeviTsai. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
    var myController = UIStoryboard(name: "PolNav", bundle: nil).instantiateInitialViewController() as! MyPolnavViewController
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        print("\(self.myController.view)")
        
        Timer.scheduledTimer(withTimeInterval: 10, repeats: false) { (timer) in
            print("route")
            let start1 = LocationCoordinate(longitude: 12161223, latitude: 2505896)
            var points = NSMutableArray()
            points.add(LocationCoordinate(longitude: 12161254, latitude: 2505554))
            points.add(LocationCoordinate(longitude: 12160759, latitude: 2505445))
            points.add(LocationCoordinate(longitude: 12158215, latitude: 2504483))
            points.add(LocationCoordinate(longitude: 12156428, latitude: 2503314))
            
            //            self.mapController.naviService.startService(start1, relayPoint: points)
            
            PolnavSDKShell.doRoute(withStartLocation: start1, destinations: points)
        }
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    override var prefersStatusBarHidden: Bool{
        return true
    }
}

class MyPolnavViewController: PolnavViewController {
    
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
}

extension MyPolnavViewController: PolnavRouteDelegate {
    
    fileprivate func getJunction3DView() {
        var NDBlue = UIColor(red: 0x1D/255.0, green: 0x86/255.0, blue: 0xE3/255.0, alpha: 1)
        var NDRed = UIColor(red: 0xE3/255.0, green: 0x09/255.0, blue: 0x14/255.0, alpha: 1)
        var count = 0
        
        DispatchQueue.main.sync {
            count = PolnavSDKShell.turnInfoCount()
        }
        
        let condition = NSCondition()
        var predicate = true
        
        for _index in 0 ..< count {
            condition.lock()

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
                                                captureHandler: { (data, error) in
                                                    
                                                    condition.lock()
                                                    defer{
                                                        predicate = false
                                                        condition.signal()
                                                        condition.unlock()
                                                    }
                                                    
                })
            }
            
            while predicate {
                condition.wait()
            }
            
            condition.unlock()
        }
    }
    
    // Mark PolnavRouteDelegate
    func onRoutingCalculateFinish() {
        print("onRoutingCalculateFinish")
        DispatchQueue.global().async {
            self.getJunction3DView()
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
