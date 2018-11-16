//
//  ProductInfoData.h
//  PolnavSDKShell
//
//  Created by Zoey Yu on 31/10/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//Server上的產品相關結構資料
@interface PolnavServerProductInfoData : NSObject

//產品顯示名稱，如：荷比盧地圖包
@property (nonatomic, copy) NSString *productDisplayName;
//產品顯示名稱，如：荷比盧地圖包[當地語言]
@property (nonatomic, copy) NSString *productDisplayLocalName;
//該產品下的地圖顯示名稱，如：荷蘭地圖
@property (nonatomic, copy) NSString *mapDisplayName;
//該產品下的地圖顯示名稱，如：荷蘭地圖[當地語言]
@property (nonatomic, copy) NSString *mapDisplayLocalName;
//上述地圖存在/Map/資料夾中的名稱，此數值可用來查MapInfoData，進一步決定要下載哪一版地圖
@property (nonatomic, copy) NSString *mapName;

/*
 * @brief 根據產品的資料生成PolnavServerProductInfoData
 * @param productDisplayName 產品顯示名稱
 * @param productDisplayLocalName 產品顯示名稱，如：荷比盧地圖包[當地語言]
 * @param mapDisplayName 該產品下的地圖顯示名稱
 * @param mapDisplayLocalName 該產品下的地圖顯示名稱，如：荷蘭地圖[當地語言]
 * @param mapName 地圖名稱
 * @return 生成PolnavServerProductInfoData產品的資料
 */
- (instancetype)initWithProductDisplayName:(NSString *)productDisplayName productDisplayLocalName:(NSString *)productDisplayLocalName mapDisplayName:(NSString *)mapDisplayName mapDisplayLocalName:(NSString *)mapDisplayLocalName mapName:(NSString *)mapName;

@end
