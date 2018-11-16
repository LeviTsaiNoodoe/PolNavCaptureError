//
//  PolnavServerMapInfoData.h
//  PolnavSDKShell
//
//  Created by Zoey Yu on 19/10/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//地圖授權狀態的類型
typedef NS_ENUM(NSInteger, MapStatus) {
    MapStatusUNKNOWN  = -1,         //尚未合法取得此地圖
    MapStatusUnderWarranty = 0,     //合法取得地圖且此版本在保固期限內
    MapStatusWarrantyExpired = 1,   //合法取得地圖且此版本不在授權保固期限內
};

//Server上的地圖相關結構資料
@interface PolnavServerMapInfoData : NSObject

//地圖下載完解開後的名稱
@property (nonatomic, copy) NSString *mapName;
//地圖存在server的.zip檔名
@property (nonatomic, copy) NSString *mapFileName;
//地圖打包的時間，Expired Date會跟此日期判斷，並決定下方的Permission
@property (nonatomic, copy) NSDate *buildDate;
//地圖版本號
@property (nonatomic, copy) NSString *mapCode;
//.zip檔地圖大小
@property (nonatomic, assign) CGFloat fileSize;
//地圖解壓縮後的大小
@property (nonatomic, assign) CGFloat fullFileSize;
//地圖授權狀態
@property (nonatomic, assign) MapStatus warrantyStatus;
//此版本地圖是否已安裝過授權Key
@property (nonatomic, assign) BOOL isKeyInstalled;
//此版本地圖是否已安裝在/Map/資料夾中
@property (nonatomic, assign) BOOL isMapInstalled;

/*
 * @brief 根據地圖相關資料生成PolnavServerMapInfoData
 * @param mapName 地圖下載完解開後的名稱
 * @param mapFileName 地圖存在server的.zip檔名
 * @param buildDate 地圖打包的時間
 * @param mapCode 地圖版本號
 * @param fileSize .zip檔地圖大小
 * @param fullFileSize 地圖解壓縮後的大小
 * @param warrantyStatus 地圖授權狀態
 * @param isKeyInstalled 此版本地圖是否已安裝過授權Key
 * @param isMapInstalled 此版本地圖是否已安裝在/Map/資料夾中
 * @return 生成PolnavServerMapInfoData地圖相關的結構資料
 */
- (instancetype)initWithMapName:(NSString *)mapName mapFileName:(NSString *)mapFileName buildDate:(NSDate *)buildDate mapCode:(NSString *)mapCode fileSize:(CGFloat)fileSize fullFileSize:(CGFloat)fullFileSize warrantyStatus:(MapStatus)warrantyStatus isKeyInstalled:(BOOL)isKeyInstalled isMapInstalled:(BOOL)isMapInstalled;
@end


