//
//  RoutePlanOptionData.h
//  PolnavSDKShell
//
//  Created by Zoey Yu on 06/03/2018.
//  Copyright © 2018 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//規劃方式
typedef NS_ENUM(NSUInteger, RoutePriority) {
    RoutePriorityDistanceFirst,     //距離優先
    RoutePriorityTimeFirst,         //時間優先
};

//RouteOption設定值資料結構
@interface RoutePlanOptionData : NSObject

//priorityType 規劃方式
@property (nonatomic) RoutePriority priorityType;
//isAvoidHighway 是否避開高速公路
@property (nonatomic, assign) BOOL isAvoidHighway;
//isAvoidTollway 是否避開收費道路
@property (nonatomic, assign) BOOL isAvoidTollway;
//isAvoidTrail 是否避開小路
@property (nonatomic, assign) BOOL isAvoidTrail;
//isAvoidFerry 是否避開水路
@property (nonatomic, assign) BOOL isAvoidFerry;

/*
 * @brief 根據導航路徑規劃相關資訊資料結構生成RoutePlanOptionData結構資料
 * @param priorityType 規劃方式
 * @param isAvoidHighway 是否避開高速公路
 * @param isAvoidTollway 是否避開收費道路
 * @param isAvoidTrail 是否避開小路
 * @param isAvoidFerry 是否避開水路
 * @return 生成RouteOption結構資料
 */
- (instancetype)initWithRoutePriority:(RoutePriority)priorityType isAvoidHighway:(BOOL)isAvoidHighway isAvoidTollway:(BOOL)isAvoidTollway isAvoidTrail:(BOOL)isAvoidTrail isAvoidFerry:(BOOL)isAvoidFerry;

@end
