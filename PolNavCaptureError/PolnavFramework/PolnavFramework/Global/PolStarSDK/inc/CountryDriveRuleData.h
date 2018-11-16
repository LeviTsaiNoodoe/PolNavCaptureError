//
//  CountryDriveRuleData.h
//  PolnavSDKShell
//
//  Created by Zoey on 25/05/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, DriveRule) {
    DriveRuleRHD,                    //右駕駛
    DriveRuleLHD,                    //左駕駛
};

//國家左右駕資訊資料結構
@interface CountryDriveRuleData : NSObject

//目前所在國家名稱
@property (nonatomic, copy) NSString *countryName;
//目前所在國家名稱[當地語言]
@property (nonatomic, copy) NSString *countryLocalName;
//國家左右駕駛類型
@property (nonatomic) DriveRule driveRule;

/*
 * @brief 根據國家左右駕資訊資料生成CountryDriveRuleData結構資料
 * @param countryName 目前所在國家名稱
 * @param countryLocalName 目前所在國家名稱[當地語言]
 * @param driveRule 國家左右駕駛類型
 * @return 生成CountryDriveRuleData結構資料
 */
- (instancetype)initWithCountryName:(NSString *)countryName
                   countryLocalName:(NSString *)countryLocalName
                          dirveRule:(DriveRule)rule;
@end
