//
//  PolnavColorData.h
//  PolnavSDKShell
//
//  Created by polstar on 9/6/17.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//顏色資料結構（RGB）
@interface PolnavColorData : NSObject

//紅色數值
@property (nonatomic, assign) NSInteger red;
//綠色數值
@property (nonatomic, assign) NSInteger green;
//藍色數值
@property (nonatomic, assign) NSInteger blue;
//透明度數值
@property (nonatomic, assign) NSInteger alpha;

/*
 * @brief 根據顏色相關資料生成PolnavColorData結構資料
 * @param red 紅色數值
 * @param green 綠色數值
 * @param blue 藍色數值
 * @param alpha 透明度數值
 * @return 生成PolnavColorData結構資料
 */
- (instancetype)initWithRed:(NSInteger)red green:(NSInteger)green blue:(NSInteger)blue alpha:(NSInteger)alpha;
@end
