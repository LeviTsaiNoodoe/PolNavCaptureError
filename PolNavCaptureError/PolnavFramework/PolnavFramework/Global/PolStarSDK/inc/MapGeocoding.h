//
//  MapGeocoding.h
//  PolnavSDKShell
//
//  Created by Zoey on 15/08/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//GeoCode反查結果資料結構
@interface MapGeocoding : NSObject

//國家名稱
@property (nonatomic, copy) NSString *countryName;
//國家名稱[當地語言]
@property (nonatomic, copy) NSString *countryLocalName;
//城市名稱
@property (nonatomic, copy) NSString *cityName;
//街道名稱
@property (nonatomic, copy) NSString *streetName;
//地圖名稱
@property (nonatomic, copy) NSString *mapName;
/*
 * @brief 根據GeoCode相關資料生成GeoCode結構資料
 * @param countryName 國家名稱
 * @param countryLocalName 國家名稱[當地語言]
 * @param cityName 城市名稱
 * @param streetName 街道名稱
 * @param mapName 地圖名稱
 * @return 生成GeoCode結構資料
 */
- (instancetype)initWithCountryName:(NSString *)countryName
                   countryLocalName:(NSString *)countryLocalName
                           cityName:(NSString *)cityName
                         streetName:(NSString *)streetName
                            mapName:(NSString *)mapName;
@end
