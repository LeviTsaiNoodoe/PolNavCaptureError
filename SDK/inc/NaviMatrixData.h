//
//  NaviMatrixData.h
//  PolnavSDKShell
//
//  Created by Zoey on 25/05/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PolnavStructData.h"

@class SpeedCameraData;
@class TripInfoData;
@class TurnInfoData;
@class CountryDriveRuleData;
@class NextTurnCrossInfoData;

//導航相關資訊資料結構
@interface NaviMatrixData : NSObject

//目前街道名稱
@property (copy, nonatomic) NSString *currentStreetName;
//目前城市
@property (copy, nonatomic) NSString *currentCityName;
//目前街道速限
@property (copy, nonatomic) NSString *currentStreetLimitSpeed;
//目前速度
@property (assign, nonatomic) NSInteger currentRealSpeed;
//車頭方向角度
@property (assign, nonatomic) NSInteger carHeading;
//是否超速
@property (nonatomic) BOOL isExceedSpeedLimit;
//是否有路徑規劃
@property (nonatomic) BOOL hasRoute;
//是否目前所在位置不在道路上
@property (nonatomic) BOOL isOffRoad;
//是否目前所在位置已偏移規劃路徑
@property (nonatomic) BOOL isOffRoute;
//目前街道速限資料
@property (nonatomic) CommonValueUnit *currentFormatSpeed;
//目前車子經緯度資料
@property (nonatomic) LocationCoordinate *currentCarLocation;
//測速照相資料
@property (nonatomic) SpeedCameraData *speedCameraData;
//旅程相關資訊資料
@property (nonatomic) TripInfoData *tripInfoData;
//下個轉彎相關資訊資料
@property (nonatomic) TurnInfoData *nextTurnInfoData;
//下下個轉彎相關資訊資料
@property (nonatomic) TurnInfoData *nextNextTurnInfoData;
//國家左右駕資訊資料
@property (nonatomic) CountryDriveRuleData *countryDriveRuleData;
//下個路口左右岔的資料
@property (nonatomic) NextTurnCrossInfoData *nextTurnCrossInfoData;

/*
 * @brief 根據導航相關資料生成NaviMatrixData結構資料
 * @param streetName 目前街道名稱
 * @param cityName 目前城市
 * @param carLocation 目前車子經緯度資料
 * @param isExceedSpeedLimit 是否超速
 * @param limitSpeed 目前街道速限
 * @param realSpeed 目前速度
 * @param currentSpeed 目前街道速限資料
 * @param carHeading 車頭方向角度
 * @param speedCameraData 測速照相資料
 * @param hasRoute 是否有路徑規劃
 * @param isOffRoad 是否目前所在位置不在道路上
 * @param isOffRoute 是否目前所在位置已偏移規劃路徑
 * @param tripInfoData 旅程相關資訊資料
 * @param nextTurnInfoData下個轉彎相關資訊資料
 * @param nextNextTurnInfoData 下下個轉彎相關資訊資料
 * @param countryDirveRuleData 國家左右駕資訊資料
 * @param nextTurnCrossInfoData 下個路口左右岔的資料
 * @return 生成NaviMatrixData結構資料
 */
- (instancetype)initWithCurrentStreetName:(NSString *)streetName
                          currentCityName:(NSString *)cityName
                       currentCarLocation:(LocationCoordinate *)carLocation
                       isExceedSpeedLimit:(BOOL)isExceedSpeedLimit
                  currentStreetLimitSpeed:(NSString *)limitSpeed
                         currentRealSpeed:(NSInteger)realSpeed
                       currentFormatSpeed:(CommonValueUnit *)currentSpeed
                               carHeading:(NSInteger)carHeading
                          speedCameraData:(SpeedCameraData *)speedCameraData
                                 hasRoute:(BOOL)hasRoute
                                isOffRoad:(BOOL)isOffRoad
                               isOffRoute:(BOOL)isOffRoute
                             tripInfoData:(TripInfoData *)tripInfoData
                         nextTurnInfoData:(TurnInfoData *)nextTurnInfoData
                     nextNextTurnInfoData:(TurnInfoData *)nextNextTurnInfoData
                     countryDriveRuleData:(CountryDriveRuleData *)countryDirveRuleData
                    nextTurnCrossInfoData:(NextTurnCrossInfoData *)nextTurnCrossInfoData;

@end
