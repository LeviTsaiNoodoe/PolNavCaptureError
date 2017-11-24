//
//  MapExpiredData.h
//  PolnavSDKShell
//
//  Created by Zoey Yu on 10/11/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//地圖授權保固期限資料結構資料
@interface MapExpiredData : NSObject

//地圖名稱
@property (nonatomic, copy) NSString *mapName;
//保固期限
@property (nonatomic) NSDate *expiredDate;

/*
 * @brief 根據地圖授權保固期限資料生成MapExpiredData結構資料
 * @param mapName 地圖名稱
 * @param expiredDate 保固期限
 * @return 生成MapExpiredData地圖授權保固期限結構資料
 */
- (instancetype)initWithMapName:(NSString *)mapName expiredDate:(NSDate *)expiredDate;

@end
