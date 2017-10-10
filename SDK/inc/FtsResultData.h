//
//  FtsResultData.h
//  PolnavSDKShell
//
//  Created by Zoey on 06/06/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PolnavStructData.h"

//FTS搜尋結果資料的類型
typedef NS_ENUM(NSUInteger, FtsResultType) {
    FtsResultTypeDefault,           //default
    FtsResultTypePoi,               //POI
    FtsResultTypeStreet,            //街道
    FtsResultTypeAddressPoint,      //門牌號碼
};

//FTS搜尋結果資料結構
@interface FtsResultData : NSObject

//名稱
@property (copy, nonatomic) NSString *name;
//城市名稱
@property (copy, nonatomic) NSString *cityName;
//電話號碼
@property (copy, nonatomic) NSString *phoneNumber;
//位於車頭的方向
@property (nonatomic, assign) NSInteger directionToCarHead;
//距離
@property (assign, nonatomic) NSInteger distance;
//格式化過的距離
@property (nonatomic) CommonValueUnit *formatDistance;
//顯示點經緯度座標
@property (nonatomic) LocationCoordinate *shownLocation;
//導航點經緯度座標
@property (nonatomic) LocationCoordinate *routedLocation;
//POI的圖示
@property (nonatomic) UIImage *poiIcon;
//FTS搜尋結果資料類型
@property (nonatomic) FtsResultType type;

/*
 * @brief 根據FTS搜尋結果相關資料生成FtsResultData結構資料
 * @param name 名稱
 * @param cityName 城市名稱
 * @param phoneNumber 電話號碼
 * @param directionToCarHead 位於車頭的方向
 * @param distance 距離
 * @param formatDistance 格式化過的距離
 * @param distance 距離
 * @param shownLocation 顯示點經緯度座標
 * @param routedLocation 導航點經緯度座標
 * @param poiIcon POI的圖示
 * @param type FTS搜尋結果資料類型
 * @return 生成FtsResultData結構資料
 */
- (instancetype)initWithName:(NSString *)name
                    cityName:(NSString*)cityName
                 phoneNumber:(NSString *)phoneNumber
          directionToCarHead:(NSInteger)directionToCarHead
                    distance:(NSInteger)distance
              formatDistance:(CommonValueUnit *)formatDistance
               shownLocation:(LocationCoordinate *)shownLocation
              routedLocation:(LocationCoordinate *)routedLocation
                     poiIcon:(UIImage *)poiIcon
                        type:(FtsResultType)type;

@end
