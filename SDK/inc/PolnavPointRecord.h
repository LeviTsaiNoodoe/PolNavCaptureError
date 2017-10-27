//
//  PolnavPointRecord.h
//  polnavMap
//
//  Created by Zoey on 24/04/2017.
//  Copyright © 2017 Zoey. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PolnavStructData.h"
//選取的物件的類型
typedef NS_ENUM(NSUInteger, PolnavPointRecordType) {
    PolnavPointRecordTypePoi = 0,               //POI
    PolnavPointRecordTypeCityCenter,            //城市中心
    PolnavPointRecordTypeStreetCenter,          //街道中心
    PolnavPointRecordTypeIntersectionRoad,      //交叉入口
    PolnavPointRecordTypeHouseAddress,          //房屋地址
    PolnavPointRecordTypeCoordinate,            //座標
    PolnavPointRecordTypeGPSPhoto,              //GPS Photo
    PolnavPointRecordTypeFavorite,              //Favorite
    PolnavPointRecordTypeGeo,                   //Geo
    PolnavPointRecordTypeMyHome,                //My Home
    PolnavPointRecordTypeDefault,               //Default
};

//選取的物件相關資料結構
@interface PolnavPointRecord : NSObject
//顯示點經緯度座標
@property (nonatomic) LocationCoordinate *shownLocation;
//導航點經緯度座標
@property (nonatomic) LocationCoordinate *routedLocation;
//物件的類型
@property (nonatomic) PolnavPointRecordType type;
//名稱
@property (nonatomic, copy) NSString *name;
//國家名稱
@property (nonatomic, copy) NSString *countryName;
//城市名稱
@property (nonatomic, copy) NSString *cityName;
//電話號碼
@property (nonatomic, copy) NSString *phoneNumber;
//格式化過的距離
@property (nonatomic, copy) CommonValueUnit *formatDistance;
//距離
@property (nonatomic, assign) CGFloat distance;
//位於車頭的方向
@property (nonatomic, assign) CGFloat directionToCarHead;

/*
 * @brief 根據選取的物件相關資料生成PolnavPointRecord結構資料
 * @param type 物件的類型
 * @param name 名稱
 * @param shownLocation 顯示點經緯度座標
 * @param routedLocation 導航點經緯度座標
 * @param countryName 國家名稱
 * @param cityName 城市名稱
 * @param phoneNum 電話號碼
 * @param distance 距離
 * @param formatDistance 格式化過的距離
 * @param directionToCarHead 位於車頭的方向
 * @return 生成PolnavPointRecord結構資料
 */
- (instancetype)initWithType:(PolnavPointRecordType)type
                        name:(NSString *)name
                shownLocation:(LocationCoordinate *)shownLocation
              routedLocation:(LocationCoordinate *)routedLocation
                 countryName:(NSString *)countryName
                    cityName:(NSString *)cityName
                    phoneNum:(NSString *)phoneNum
                    distance:(CGFloat)distance
             formateDistance:(CommonValueUnit *)formatDistance
          directionToCarHead:(CGFloat)directionToCarHead;

@end
