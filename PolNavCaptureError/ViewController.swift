//
//  ViewController.swift
//  PolNavCaptureError
//
//  Created by LeviTsai on 2017/9/4.
//  Copyright © 2017年 LeviTsai. All rights reserved.
//

import UIKit
import PolnavFramework


class ViewController: UIViewController {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        
        PolnavManager.install(with: self)
        
        
        PolnavManager.default.loadPolnavMobileFolder(product: ["Taiwan_RM" : Date().timeIntervalSinceNow], displacement: 150)
        
        
        PolnavManager.default.updateProductMapVoiceInfo()
        
    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }


}

extension ViewController: PolnavManagerDataSource{
    func noodoeUUID() -> String {
        return "RFBSR30JDJB100057"
    }
}
