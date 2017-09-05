//
//  ViewController.swift
//  PolNavCaptureError
//
//  Created by LeviTsai on 2017/9/4.
//  Copyright © 2017年 LeviTsai. All rights reserved.
//

import UIKit

class ViewController: PolnavViewController {

    var serviceTimer: Timer?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        let points = NSMutableArray()
        
        let start1 = LocationCoordinate(longitude: 12161223, latitude: 2505896)
        points.add(LocationCoordinate(longitude: 12156428, latitude: 2503314))
        PolnavSDKShell.doRoute(withStartLocation: start1, destinations: points)
        
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    @IBAction func start(_ sender: Any) {
        
        if !PolnavSDKShell.isSimulate() {
           PolnavSDKShell.startSimulate()
        }
        
        self.serviceTimer = Timer.scheduledTimer(withTimeInterval: 1, repeats: true) { (timer) in
            
            if !PolnavSDKShell.isSimulate() {
                timer.invalidate()
                PolnavSDKShell.stopSimulate()
                return
            }
            
            PolnavSDKShell.captureNaviImage(with: CaptureType.naviView2D, imageSize: CGSize(width: 480, height: 480), zoomScale: 0, isShowLabel: false, isShowPOI: false, isShowOneWay: false, junctionIndex: 0, captureHandler: { (data, error) in
                
            })
            
            PolnavSDKShell.captureNaviImage(with: CaptureType.bestFit, imageSize: CGSize(width: 480, height: 480), zoomScale: 0, isShowLabel: false, isShowPOI: false, isShowOneWay: false, junctionIndex: 0, captureHandler: { (data, error) in
                
            })

    }
        
        
    }
    
}

