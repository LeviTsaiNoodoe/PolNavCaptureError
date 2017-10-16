//
//  ViewController.swift
//  PolNavCaptureError
//
//  Created by LeviTsai on 2017/9/4.
//  Copyright © 2017年 LeviTsai. All rights reserved.
//

import UIKit

class ViewController: PolnavViewController {
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        PolnavSDKShell.add(self)
        
        // Do any additional setup after loading the view, typically from a nib.
        
        
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func start(_ sender: Any) {
        let points = NSMutableArray()
        
        let start1 = LocationCoordinate(longitude: 12161223, latitude: 2505896)
        points.add(LocationCoordinate(longitude: 12156428, latitude: 2503314))
        PolnavSDKShell.doRoute(withStartLocation: nil, destinations: points)
        
        
    }
    
    @IBAction func simulate(_ sender: UISegmentedControl) {
        
        switch sender.selectedSegmentIndex {
        case 0:
            PolnavSDKShell.startSimulate()
        case 1:
            PolnavSDKShell.stopSimulate()
        default:
            PolnavSDKShell.stopSimulate()
        }
        
    }
}

extension ViewController: PolnavRouteDelegate {
    
    // Mark PolnavRouteDelegate
    func onRoutingCalculateFinish() {
        print("onRoutingCalculateFinish")
    }
    
    func onCalculateFailed(with index: Int) {
        print("onCalculateFailed:\(index)")
        //        self.navigationTask?.updateDisplay(SunrayNavigationTask.NavigationEvent.notAvailable)
//        self.stopService()
    }
    
    func onReachDestination(_ index: UInt) {
        print("onReachDestination:\(index)")
    }
    
    func onUpdateRoutingProgress(withProgress progress: Int) {
        print("onUpdateRoutingProgress:\(progress)")
        //        self.navigationTask?.updateDisplay(SunrayNavigationTask.NavigationEvent.calculating)
    }
}

