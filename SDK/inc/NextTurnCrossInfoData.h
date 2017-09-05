//
//  NextTurnCrossInfoData.h
//  PolnavSDKShell
//
//  Created by Zoey on 06/07/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//下個轉彎路口左右岔的資料結構
@interface NextTurnCrossInfoData : NSObject
//轉彎方向類型
typedef NS_ENUM(NSInteger, TurnDirection) {
    TurnDirectionLeft = -1,         //左轉
    TurnDirectionRight = 1,         //右轉
    TurnDirectionStraight = 0,      //直走
};

//左岔路口個數
@property (nonatomic, assign) NSInteger leftCrossNumber;
//右岔路口個數
@property (nonatomic, assign) NSInteger rightCrossNumber;
//總岔路口個數
@property (nonatomic, assign) NSInteger totalCrossNumber;
//轉彎方向類型
@property (nonatomic) TurnDirection turnSide;


/*
  * @brief 根據下個路口左右岔的資料生成NextTurnCrossInfoData結構資料
 * @param leftCrossNumber 左岔路口個數
  * @param rightCrossNumber 右岔路口個數
 * @param totalCrossNumber 總岔路口個數
 * @param turnSide 轉彎方向類型
  * @return 生成NextTurnCrossInfoData結構資料
 */
- (instancetype)initWithLeftCrossNumber:(NSInteger)leftCrossNumber rightCrossNumber:(NSInteger)rightCrossNumber totalCrossNumber:(NSInteger)totalCrossNumber turnSide:(TurnDirection)turnSide;
@end
