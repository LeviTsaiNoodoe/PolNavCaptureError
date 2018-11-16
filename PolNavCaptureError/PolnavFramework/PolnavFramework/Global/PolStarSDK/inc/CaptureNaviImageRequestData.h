//
//  CaptureNaviImageRequestData.h
//  PolnavSDKShell
//
//  Created by Zoey Yu on 22/11/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, DayNightMode);
typedef NS_ENUM(NSUInteger, CaptureType);
//截圖相關設定結構資料
@interface CaptureNaviImageRequestData : NSObject

//Base Info
//截取畫面的類型
@property (nonatomic) CaptureType captureType;
//截取畫面的尺寸
@property (nonatomic, assign) CGSize imageSize;

//for component on map
//是否顯示道路名稱
@property (nonatomic, assign) BOOL isShowLabel;
//是否顯示POI
@property (nonatomic, assign) BOOL isShowPOI;
//是否顯示單行道符號
@property (nonatomic, assign) BOOL isShowOneWay;
//是否顯示測速照相機
@property (nonatomic, assign) BOOL isShowSpeedCamera;
//是否顯示車標
@property (nonatomic, assign) BOOL isShowCar;
//指定截圖的日夜間模式。dayNightMode的設定值同API: configDayNightMode。輸入DayNightModeAuto代表截圖的日夜間同地圖顯示的模式。
@property (nonatomic, assign) DayNightMode dayNightMode;
//waypoint icon Size
@property (nonatomic, assign) NSUInteger waypointIconSize;
//RoadSign Icon Size
@property (nonatomic, assign) NSUInteger roadSignIconSize;
//是否顯示debug log
@property (nonatomic, assign) BOOL isEnableVerbose;

//for Turn Arrow
//轉彎箭頭顏色
@property (nonatomic) UIColor *turnArrowColor;
//轉彎箭頭寬度大小
@property (nonatomic, assign) CGFloat turnArrowWidthRatio;

//for Street Ratio
//街道寬度
@property (nonatomic, assign) CGFloat streetRatio;

//for Text Ratio
@property (nonatomic, assign) CGFloat textRatio;
//for Apply Device DPI
@property (nonatomic, assign) BOOL isApplyDpi;

//Only for Junction View
//要擷取第幾個Turn的JunctionView。junctionIndex參數只對JunctionView有效，同時也不可以超過Turn的數量，否則會回傳null
@property (nonatomic, assign) NSUInteger junctionIndex;
//預測車子可能在junction前方N公尺。若設為0代表使用舊版的截圖方式。
@property (nonatomic, assign) NSUInteger junctionDistance;

//Only for BestfitView View
//BestfitView截圖內縮比例
@property (nonatomic, assign) CGFloat bestfitBorderPercent;
//截取畫面的縮放比例值。輸入0會用預設值0.5f來截圖
@property (nonatomic, assign) CGFloat zoomScale;


- (instancetype)initWithCaptureType:(CaptureType)captureType imageSize:(CGSize)imageSize;

- (void)enableMapComponentWithIsShowLabel:(BOOL)showLabel isShowPOI:(BOOL)isShowPOI isShowOneWay:(BOOL)isShowOneWay isShowSpeedCamera:(BOOL)isShowSpeedCamera isShowCar:(BOOL)isShowCar;

- (void)turnArrowStyleWithTurnArrowColor:(UIColor *)turnArrowColor turnArrowWidthRatio:(CGFloat)turnArrowWidthRatio;

- (void)junctionViewParamWithJunctionDistance:(NSUInteger)junctionDistance atJunctionIndex:(NSUInteger)junctionIndex;

@end
