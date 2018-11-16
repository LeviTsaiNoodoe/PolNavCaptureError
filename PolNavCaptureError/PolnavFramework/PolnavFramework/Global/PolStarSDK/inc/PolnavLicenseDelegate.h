//
//  PolnavLicenseDelegate.h
//  PolnavSDKShell
//
//  Created by Zoey Yu on 01/11/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//PolnavLicenseDelegate協議，定義了通知更新與安裝授權完成的callback
@protocol PolnavLicenseDelegate <NSObject>
/*
 * @brief 當更新Product/Map/Voice相關資訊成功時，會調用此方法
 */
- (void)updateProductMapVoiceInfoSuccess;
/*
 * @brief 當更新Product/Map/Voice相關資訊失敗時，會調用此方法
 */
- (void)updateProductMapVoiceInfoFailed;
/*
 * @brief 當安裝授權成功時，會調用此方法
 * @param mapName 地圖名稱
 * @param mapCode 地圖版本
 */
- (void)installLicenseKeySuccessWithMapName:(NSString *)mapName mapCode:(NSString *)mapCode;
/*
 * @brief 當安裝授權失敗時，會調用此方法
 * @param mapName 地圖名稱
 * @param mapCode 地圖版本
 */
- (void)installLicenseKeyFailedWithMapName:(NSString *)mapName mapCode:(NSString *)mapCode;
/*
 * @brief 當有地圖可上高速公路的CC數有變更時，若有變更且會影響目前地圖正確性，會調用此方法，需重啟APP
 */
- (void)mapCCValueChanged;
@end

