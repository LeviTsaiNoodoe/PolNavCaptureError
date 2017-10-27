//
//  ViewController.swift
//  PolNavCaptureError
//
//  Created by LeviTsai on 2017/9/4.
//  Copyright © 2017年 LeviTsai. All rights reserved.
//

import UIKit

class ViewController: UIViewController {
    
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

extension ViewController: PolnavRouteDelegate {
    
    // Mark PolnavRouteDelegate
    func onRoutingCalculateFinish() {
        print("onRoutingCalculateFinish")
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
