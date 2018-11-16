//
//  PolnavRouteDelegate.h
//  PolnavSDKShell
//
//  Created by Zoey on 26/06/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//PolnavRouteDelegate協議，定義了路由規劃結果的callback
@protocol PolnavRouteDelegate <NSObject>
@optional
/*
 * @brief 當路由規劃計算完成時，會調用此方法
 */
- (void)onCalculateFinish;
/*
 * @brief 當路由規劃完成結束時，會調用此方法
 */
- (void)onDoRouteFinish;
/*
 * @brief 當路由規劃計算錯誤時，會調用此方法
 */
- (void)onCalculateFailed;
/*
 * @brief 當路由規劃錯誤發生時，會調用此方法
 * @return index 無法規劃路徑的 index節點
 */
- (void)onDoRouteFailedAtIndex:(NSInteger)index;
/*
 * @brief 當路由規劃完成後，路過目的地時會調用此方法
 * @return index 路過目的地的index節點
 */
- (void)onReachDestination:(NSUInteger)index;
/*
 * @brief 當路由規劃時，路由規劃進度會調用此方法
 * @return progress 路由規劃進度完成比例值
 */
- (void)onUpdateRoutingProgressWithProgress:(NSInteger)progress;
/*
 * @brief 當目前所在位置已偏移規劃路徑時，會調用此方法
 */
- (void)onOffRoute;
@end
