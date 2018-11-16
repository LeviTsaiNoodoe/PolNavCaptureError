//
//  CaptureData.h
//  PolnavSDKShell
//
//  Created by Zoey on 03/07/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PolnavStructData.h"

//截取畫面的類型
typedef NS_ENUM(NSUInteger, CaptureType) {
    CaptureTypeNaviView2D = 0,          //導航2D車頭向上
    CaptureTypeNaviView3D,              //導航3D車頭向上
    CaptureTypeJuntionView2D,           //2D轉彎連接處
    CaptureTypeJuntionView3D,           //3D轉彎連接處
    CaptureTypeBestFit,                 //全路徑
    CaptureTypeLocationView,            //任意點截圖
    CaptureTypeDefault                  //Default
};

//截取畫面的資料
@interface CaptureData : NSObject
//截取畫面的類型
@property (nonatomic) CaptureType type;
//截取畫面的圖片
@property (nonatomic) UIImage *capturedImage;
//圖片的屬性狀態描述
@property (nonatomic, copy) NSString *imageAttributeDescription;
//Turn的ID
@property (nonatomic, copy) NSString *turnSignature;
/*
 * @brief 根據截取畫面的資料生成CaptureData
 * @param type 截取畫面的類型
 * @param image 截取畫面的圖片
 * @param imageDescription 圖片的屬性狀態描述
 * @param turnSignature Turn的ID
 * @return 生成CaptureData截取畫面的資料
 */
- (instancetype)initWithType:(CaptureType)type capturedImage:(UIImage *)image imageAttributeDescription:(NSString *)imageDescription turnSignature:(NSString *)turnSignature;
@end
