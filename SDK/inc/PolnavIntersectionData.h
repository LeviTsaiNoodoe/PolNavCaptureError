//
//  PolnavIntersectionData.h
//  PolnavSDKShell
//
//  Created by polstar on 9/14/17.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PolnavStructData.h"

//FTS交叉路口資料結構
@interface PolnavIntersectionData : NSObject

//名稱
@property (nonatomic, copy) NSString *name;
//城市名稱
@property (nonatomic, copy) NSString *cityName;
//經緯度座標
@property (nonatomic) LocationCoordinate *location;

/*
 * @brief 根據FTS交叉路口相關資料生成PolnavIntersectionData結構資料
 * @param name 名稱
 * @param cityName 城市名稱
 * @param location 經緯度座標
 * @return 生成PolnavIntersectionData結構資料
 */
- (instancetype)initWithName:(NSString *)name cityName:(NSString *)cityName location:(LocationCoordinate *)location;
@end
