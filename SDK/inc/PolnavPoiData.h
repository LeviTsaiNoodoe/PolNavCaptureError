//
//  PolnavPoiData.h
//  PolnavSDKShell
//
//  Created by Zoey on 08/06/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PolnavStructData.h"
//POI相關資訊資料結構
@interface PolnavPoiData : NSObject

//POI的類型
@property (nonatomic, assign) int type;
//名稱
@property (nonatomic, copy) NSString *name;
//城市名稱
@property (nonatomic, copy) NSString *cityName;
//國家名稱
@property (nonatomic, copy) NSString *countryName;
//電話號碼
@property (nonatomic, copy) NSString *phoneNumber;
//距離
@property (nonatomic, assign) NSInteger distance;
//格式化過的距離
@property (nonatomic) CommonValueUnit *formatDistance;
//位於車頭的方向
@property (nonatomic, assign) NSInteger directionToCarHead;
//POI的圖示
@property (nonatomic) UIImage *icon;
//顯示點經緯度座標
@property (nonatomic) LocationCoordinate *shownLocation;
//導航點經緯度座標
@property (nonatomic) LocationCoordinate *routedLocation;

/*
 * @brief 根據POI相關資料生成PolnavPoiData結構資料
 * @param type POI的類型
 * @param poiName 名稱
 * @param cityName 城市名稱
 * @param countryName 國家名稱
 * @param phoneNumber 電話號碼
 * @param icon POI的圖示
 * @param distance 距離
 * @param formatDistance 格式化過的距離
 * @param shownLocation 顯示點經緯度座標
 * @param routedLocation 導航點經緯度座標
 * @return 生成PolnavPoiData結構資料
 */
- (instancetype)initWithType:(int)type
                     poiName:(NSString *)poiName
                    cityName:(NSString *)cityName
                 countryName:(NSString *)countryName
                 phoneNumber:(NSString *)phoneNumber
          directionToCarHead:(NSInteger)directionToCarHead
                        icon:(UIImage *)icon
                    distance:(NSInteger)distance
              formatDistance:(CommonValueUnit *)formatDistance
                shownLocation:(LocationCoordinate *)shownLocation
              routedLocation:(LocationCoordinate *)routedLocation;

@end
