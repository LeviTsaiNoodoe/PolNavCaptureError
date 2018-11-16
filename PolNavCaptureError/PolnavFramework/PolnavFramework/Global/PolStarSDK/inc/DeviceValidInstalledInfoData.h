//
//  DeviceValidInstalledInfoData.h
//  PolnavSDKShell
//
//  Created by Zoey Yu on 15/03/2018.
//  Copyright © 2018 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//手機上合法安裝的地圖資料結構資料
@interface DeviceValidInstalledMapInfoData : NSObject

//地圖名稱
@property (nonatomic, copy) NSString *mapName;
//地圖打包的時間
@property (nonatomic) NSDate *buildDate;
//地圖版本號
@property (nonatomic, copy) NSString *mapCode;
/*
 * @brief 根據地手機上合法安裝的地圖資料生成DeviceValidInstalledMapInfoData結構資料
 * @param mapName 地圖名稱
 * @param buildDate 地圖打包的時間
 * @param mapCode 地圖版本號
 * @return 生成DeviceValidInstalledMapInfoData手機上合法安裝的地圖資料
 */
- (instancetype)initWithMapName:(NSString *)mapName buildData:(NSDate *)builDate mapCode:(NSString *)mapCode;

@end

//手機上合法安裝的語音資料結構資料
@interface DeviceValidInstalledVoiceInfoData : NSObject

//語音名稱
@property (nonatomic, copy) NSString *voiceName;
//語音打包的時間
@property (nonatomic) NSDate *buildDate;
/*
 * @brief 根據地手機上合法安裝的語音資料生成DeviceValidInstalledVoiceInfoData結構資料
 * @param voiceName 語音名稱
 * @param builDate 語音打包的時間
 * @return 生成DeviceValidInstalledVoiceInfoData手機上合法安裝的地圖資料
 */
- (instancetype)initWithVoiceName:(NSString *)voiceName buildData:(NSDate *)builDate;

@end
