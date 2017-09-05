//
//  PolnavStructData.h
//  PolnavSDKShell
//
//  Created by Zoey on 19/06/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
typedef void* sdkFeatureId;

//儲存數值和單位的資料結構
@interface CommonValueUnit : NSObject
//數值
@property (nonatomic, copy) NSString *value;
//單位
@property (nonatomic, copy) NSString *unit;
/*
 * @brief 根據儲存數值和單位的資料結構生成CommonValueUnit結構資料
 * @param value 數值
 * @param unit 單位
 * @return 生成CommonValueUnit結構資料
  */
- (instancetype)initWithValue:(NSString *)value unit:(NSString *)unit;
@end

//儲存經緯度的資料結構
@interface LocationCoordinate : NSObject
//經度
@property (nonatomic, assign) NSInteger longitude;
//緯度
@property (nonatomic, assign) NSInteger latitude;
/*
 * @brief 根據儲存數值和單位的資料結構生成LocationCoordinate結構資料
 * @param longitude 經度
 * @param latitude 緯度
 * @return 生成LocationCoordinate 結構資料
 */
- (instancetype)initWithLongitude:(NSInteger)longitude latitude:(NSInteger)latitude;
@end

//螢幕上的座標點資料結構
@interface PolnavPoint : NSObject
//x座標
@property (nonatomic, assign) NSInteger x;
//y座標
@property (nonatomic, assign) NSInteger y;
/*
 * @brief 根據螢幕上的座標點資料結構生成PolnavPoint結構資料
 * @param x x座標
 * @param y y座標
 * @return 生成PolnavPoint結構資料
 */
- (instancetype)initWithX:(NSInteger)x y:(NSInteger)y;
@end

//BoundingBox資料結構
@interface BoundingBox : NSObject
//區域範圍的最左下角
@property (nonatomic, assign) LocationCoordinate *leftBottom;
//區域範圍的最右上角
@property (nonatomic, assign) LocationCoordinate *rightTop;
/*
 * @brief 根據區域範圍的最左下角與最右上角資料結構生成BoundingBox結構資料
 * @param leftBottom 區域範圍的最左下角
 * @param rightTop 區域範圍的最右上角
 * @return 生成BoundingBox結構資料
 */
- (instancetype)initWithleftBottom:(LocationCoordinate *)leftBottom
                    rightTop:(LocationCoordinate *)rightTop;
@end

