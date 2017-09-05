//
//  SpeedCameraData.h
//  PolnavSDKShell
//
//  Created by Zoey on 25/05/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PolnavStructData.h"
//測速照相資訊資料結構
@interface SpeedCameraData : NSObject

//偵測的超速數值
@property (nonatomic, copy) NSString *speedLimit;
//距離
@property (nonatomic) CommonValueUnit *distance;

/*
 * @brief 根據測速照相關資料生成SpeedCameraData結構資料
 * @param distance 距離
 * @param speedLimit 偵測的超速數值
 * @return 生成SpeedCameraData結構資料
 */

- (instancetype)initWithDistance:(CommonValueUnit *)distance
                      speedLimit:(NSString *)speedLimit;
@end
