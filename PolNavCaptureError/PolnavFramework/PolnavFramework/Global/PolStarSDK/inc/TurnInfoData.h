//
//  TurnInfoData.h
//  PolnavSDKShell
//
//  Created by Zoey on 25/05/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PolnavStructData.h"
//轉彎相關資訊資料結構
@interface TurnInfoData : NSObject

//街道名稱
@property (nonatomic, copy) NSString *streetName;
//城市
@property (nonatomic, copy) NSString *cityName;
//是否是Towards
@property (nonatomic, assign) BOOL isTowards;
//到轉彎入口實際距離
@property (nonatomic, assign) NSInteger realDistance;
//到轉彎入口的距離，使用CommonValueUnit結構資料
@property (nonatomic) CommonValueUnit *formatDistance;
//到轉彎入口剩餘時間(單位:秒)
@property (nonatomic, assign) CGFloat arriveTotalSeconds;
//轉彎入口的經緯度
@property (nonatomic) LocationCoordinate *location;
//轉彎圖標的檔案名稱
@property (nonatomic, copy) NSString *turnSymbolFile;
//Turn的ID
@property (nonatomic, copy) NSString *signature;
//幾號出口離開圓環
@property (nonatomic, assign) NSUInteger roundaboutExitNum;
/*
 * @brief 根據轉彎相關資料生成TurnInfoData結構資料
 * @param name 街道名稱
 * @param cityName 城市
 * @param isTowards 是否是Towards
 * @param realDistance 到轉彎入口實際距離
 * @param formatDistance 到轉彎入口的距離，使用CommonValueUnit結構資料
 * @param arriveTotalSeconds 到轉彎入口剩餘時間(單位:秒)
 * @param location 轉彎入口的經緯度
 * @param turnSymbolFile 轉彎圖標的檔案名稱
 * @param signature Turn的ID
 * @param roundaboutExitNum 幾號出口離開圓環
 * @return 生成TurnInfoData結構資料
 */
- (instancetype)initWithStreetName:(NSString *)name
                          cityName:(NSString *)cityName
                         isTowards:(BOOL)isTowards
                      realDistance:(NSInteger)realDistance
                    formatDistance:(CommonValueUnit *)formatDistance
                arriveTotalSeconds:(CGFloat)arriveTotalSeconds
                          location:(LocationCoordinate *)location
                    turnSymbolFile:(NSString *)turnSymbolFile
                         signature:(NSString *)signature
                 roundaboutExitNum:(NSUInteger)roundaboutExitNum;

@end
