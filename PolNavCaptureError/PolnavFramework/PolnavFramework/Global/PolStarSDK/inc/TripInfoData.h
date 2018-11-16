//
//  TripInfoData.h
//  PolnavSDKShell
//
//  Created by Zoey on 25/05/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PolnavStructData.h"
//旅程相關資訊資料結構
@interface TripInfoData : NSObject

//離WayPoint預估剩餘時間(單位:秒)
@property(nonatomic, assign) CGFloat totalSecondsToFirstWayPoint;
//離WayPoint剩餘距離
@property(nonatomic) CommonValueUnit *formatDistanceToFirstWayPoint;
//離終點預估剩餘時間(單位:秒)
@property(nonatomic, assign) CGFloat totalSecondsToDestination;
//離終點剩餘距離
@property(nonatomic) CommonValueUnit *formatDistanceToDestination;

/*
 * @brief 根據旅程相關資料生成TripInfoData結構資料
 * @param totalSecondsToFirstWayPoint 離WayPoint預估剩餘時間(單位:秒)
 * @param formatDistanceToFirstWayPoint 離WayPoint剩餘距離
 * @param totalSecondsToDestination 離終點預估剩餘時間(單位:秒)
 * @param formatDistanceToDestination 離終點剩餘距離
 * @return 生成TripInfoData結構資料
 */
- (instancetype)initWithTotalSecondsToFirstWayPoint:(CGFloat)totalSecondsToFirstWayPoint
                      formatDistanceToFirstWayPoint:(CommonValueUnit *)formatDistanceToFirstWayPoint
                          totalSecondsToDestination:(CGFloat)totalSecondsToDestination
                        formatDistanceToDestination:(CommonValueUnit *)formatDistanceToDestination;

@end
