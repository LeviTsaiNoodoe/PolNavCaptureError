//
//  PolnavSDKShell.h
//  PolnavSDKShell
//
//  Created by Zoey on 25/04/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "PolnavStructData.h"
#import "PolnavPOIType.h"

@protocol PolnavRouteDelegate;
@class PolnavPointRecord;
@class TurnInfoData;
@class PolnavPoiData;
@class FtsResultData;
@class NaviMatrixData;
@class CaptureData;
@class MapGeocoding;
@class PolnavIntersectionData;

typedef NS_ENUM(NSUInteger, CaptureType);

//地圖顯示模式
typedef NS_ENUM(NSUInteger, MapMode) {
    MapModeNaviViewNorthUp2D = 0,      //導航正北向上
    MapModeNaviViewHeadingUp2D = 1,    //導航2D車頭向上
    MapModeNaviViewHeadingUp3D = 2,    //導航3D車頭向上
    MapModeMapView = 3,                //地圖顯示模式
};

//規劃方式
typedef NS_ENUM(NSUInteger, RoutePriority) {
    RoutePriorityDistanceFirst,     //距離優先
    RoutePriorityTimeFirst,         //時間優先
};

//日夜間顯示模式
typedef NS_ENUM(NSUInteger, DayNightMode) {
    DayNightModeAuto = 0,           //自動
    DayNightModeDay = 1,            //日間
    DayNightModeNight = 2,          //夜間
};

//距離單位
typedef NS_ENUM(NSUInteger, DistanceUnitMode) {
    DistanceUnitModeKmM = 0,       //公里/公尺
    DistanceUnitModeMileFeet = 1,  //英哩/英呎
    DistanceUnitModeMileYard = 2,  //英哩/碼
};

//時間顯示格式
typedef NS_ENUM(NSUInteger, TimeFormatMode) {
    TimeFormatMode24HR = 0,         //24小時制
    TimeFormatMode12HR,             //12小時制
};

//語音語言
typedef NS_ENUM(NSUInteger, VoiceLanguage) {
    VoiceLanguageEnglish = 0 ,      //英語
    VoiceLanguageFrench,            //法語
    VoiceLanguageMandarin,          //國語
    VoiceLanguageTaiwanese,         //台語
    VoiceLanguageHakkaFourCountries,//客語四縣
    VoiceLanguageHakkaHoiLiuk,      //客語海陸
    VoiceLanguageDutch,             //荷蘭語
    VoiceLanguagePersian,           //波斯語
    VoiceLanguageItaliano,          //義大利語
};

@interface PolnavSDKShell : NSObject

//圖資檔案位置
@property (nonatomic, copy, class) NSString *resourcePath;

#pragma mark - ***** A. About Polnav Map *****
/*
 * @brief 放大地圖
 */
+ (void)mapZoomIn;
/*
 * @brief 縮小地圖
 */
+ (void)mapZoomOut;
/*
 * @brief 取得畫面選轉角度
 * @return 選轉角度
 */
+ (NSInteger)mapRotateAngle;
/*
 * @brief 設定地圖顯示模式
 * @param mapMode 地圖顯示類型
 */
+ (void)changeMapModeWithMode:(MapMode)mapMode;
/*
 * @brief 取得被點擊選取的物件資料
 * @return 物件資料PolnavPointRecord參數
 */
+ (PolnavPointRecord *)selectPointInfo;
/*
 * @brief 取得畫面上重疊的POI清單筆數
 * @return 重疊的POI清單筆數
 */
+ (NSUInteger)selectMultiPoiCount;
/*
 * @brief 取得畫面上重疊的POI清單該筆詳細資訊
 * @param index 重疊的POI資訊陣列的index值
 * @return PolnavPoiData POI相關資訊資料結構
 */
+ (PolnavPoiData *)selectMultiPoiDataAtIndex:(NSUInteger)index;
/*
 * @brief 將經緯度換算成裝置座標
 * @param locationCoordinate 座標點
 * @return CGPoint 裝置座標
 */
+ (CGPoint)getDevicePointWithLocation:(LocationCoordinate *)location;
/*
 * @brief 設定置中
 * @param locationCoordinate 經緯度資料
 * @param scale 縮放比例值
 * @param angle 角度值
 */
+ (void)moveToDeviceCenterWithLocation:(LocationCoordinate *)location
                                 scale:(CGFloat)scale
                                 angle:(NSInteger)angle;
/*
 * @brief 全路徑顯示
 * @param borderPercent 邊框百分比
 */
+ (void)showBestFitViewWithBorderPercent:(CGFloat)borderPercent;
/*
 * @brief 給定BBox自動縮放出BestFitView
 * @param boundingBox 區域範圍
 */
+ (void)showBestFitViewWithBoundingBox:(BoundingBox *)boundingBox;
/*
 * @brief 取得目前地圖縮放比例
 * @return CGFloat 縮放比例值
 */
+ (CGFloat)currentMapScale;
/*
 * @brief GeoCode反查
 * @param location 經緯度
 * @return MapGeocoding GeoCode反查結果資料結構
 */
+ (MapGeocoding *)mapGeocodingWithLocation:(LocationCoordinate *)location;
/*
 * @brief 判斷地圖顯示是否為日間模式
 */
+ (BOOL)mapIsDayMode;
/*
 * @brief 移動地圖(x,y)pixel
 * @param displacement 位移量
 */
+ (void)panMapWithDisplacement:(CGVector)displacement;

#pragma mark - B. Navi
/*
 * @brief 設定行程並規劃路徑
 * @param startLocation 起始點經緯度。如果起始點是目前所在地，則該值為nil
 * @param destinations 目的地座標點陣列。陣列結構使用LocationCoordinate類型，目的地座標組數最多只能有21個。
 */
+ (void)doRouteWithStartLocation:(LocationCoordinate *)startLocation
                    destinations:(NSMutableArray<LocationCoordinate*> *)destinations;
/*
 * @brief 新增PolnavRouteDelegate協議
 * @param delegate 地圖路由的 PolnavRouteDelegate
 */
+ (void)addRouteDelegate:(id<PolnavRouteDelegate>)delegate;
/*
 * @brief 移除PolnavRouteDelegate協議
 * @param delegate 地圖路由的 PolnavRouteDelegate
 */
+ (void)removeRouteDelegate:(id<PolnavRouteDelegate>)delegate;
/*
 * @brief 是否有路徑規劃
 */
+ (BOOL)hasRoute;
/*
 * @brief 取消路徑規劃
 */
+ (void)cancelRoute;
/*
 * @brief 開始模擬導航
 */
+ (void)startSimulate;
/*
 * @brief 暫停模擬導航
 */
+ (void)pauseSimulate;
/*
 * @brief 回復模擬導航
 */
+ (void)resumeSimulate;
/*
 * @brief 停止模擬導航
 */
+ (void)stopSimulate;
/*
 * @brief 是否正在模擬導航
 */
+ (BOOL)isSimulate;
/*
 * @brief 是否模擬導航暫停中
 */
+ (BOOL)isSimulatePause;
/*
 * @brief 轉彎數量
 */
+ (NSInteger)turnInfoCount;
/*
 * @brief 取得轉彎資訊
 * @param index 轉彎資訊陣列的index值
 * @return TurnInfoData 轉彎相關資訊資料結構
 */
+ (TurnInfoData *)turnDataAtIndex:(int)index;
/*
 * @brief 取得導航相關資訊
 * @return NaviMatrixData 導航相關資訊資料結構
 */
+ (NaviMatrixData *)naviMatrixData;
/*
 * @brief 該點是否為合法導航點 (此API僅判斷是否有鄰近道路，不能確保一定可規劃出路徑)
 * @param location 座標點
 */
+ (BOOL)canRouteWithLocation:(LocationCoordinate *)location;

#pragma mark - C. About Config
/*
 * @brief 設定日夜間顯示模式
 * @param mode 日夜間顯示模式
 */
+ (BOOL)configDayNightMode:(DayNightMode)mode;
/*
 * @brief 設定距離單位
 * @param unit 距離單位
 */
+ (BOOL)configDistanceUnit:(DistanceUnitMode)unit;
/*
 * @brief 設定時間顯示格式
 * @param timeFormat 時間顯示格式
 */
+ (BOOL)configTimeFormat:(TimeFormatMode)timeFormat;
/*
 * @brief 設定語音語言
 * @param language 語音語言
 */
+ (BOOL)configVoiceLanguage:(VoiceLanguage)language;
/*
 * @brief 設定導航路徑規劃參數
 * @param routePriorty 規劃方式
 * @param isAvoidHighway 是否避開高速公路
 * @param isAvoidTollway 是否避開收費道路
 * @param isAvoidTrail 是否避開小路
 * @param isAvoidFerry 是否避開水路
 */
+ (void)configRouteOptionWithRoutePriorty:(RoutePriority)routePriorty
                           isAvoidHighway:(BOOL)isAvoidHighway
                           isAvoidTollway:(BOOL)isAvoidTollway
                             isAvoidTrail:(BOOL)isAvoidTrail
                             isAvoidFerry:(BOOL)isAvoidFerry;
/*
 * @brief 設定道路文字大小
 * @param textRatio 文字大小
 */
+ (void)configMapStreetTextRatio:(CGFloat)textRatio;

#pragma mark - D. Capture
/*
 * @brief 截取畫面
 * @param type 截取畫面的類型
 * @param imageSize 截取畫面的尺寸
 * @param zoomScale 截取畫面的縮放比例值。輸入0會用預設值0.5f來截圖
 * @param isShowLabel 是否顯示道路名稱
 * @param isShowPOI 是否顯示POI
 * @param isShowOneWay 是否顯示單行道符號
 * @param isShowSpeedCamera 是否顯示測速照相機
 * @param isShowCar 是否顯示車標
 * @param junctionIndex 要擷取第幾個Turn的JunctionView。junctionIndex參數只對JunctionView有效，同時也不可以超過Turn的數量，否則會回傳null Image
 * @param color 指定junctionView轉彎箭頭顏色
 * @param junctionDistance 預測車子可能在junction前方N公尺。若設為0代表使用舊版的截圖方式。
 * @param dayNightMode 指定截圖的日夜間模式。dayNightMode的設定值同API: configDayNightMode。輸入DayNightModeAuto代表截圖的日夜間同地圖顯示的模式。
 * @return data 截取畫面的CaptureData資料
 * @return error 錯誤訊息
 */
+ (void)captureNaviImageWithType:(CaptureType)type
                       imageSize:(CGSize)imageSize
                       zoomScale:(CGFloat)zoomScale
                     isShowLabel:(BOOL)isShowLabel
                       isShowPOI:(BOOL)isShowPOI
                    isShowOneWay:(BOOL)isShowOneWay
               isShowSpeedCamera:(BOOL)isShowSpeedCamera
                       isShowCar:(BOOL)isShowCar
                   junctionIndex:(NSUInteger)junctionIndex
                   junctionColor:(UIColor *)color
                junctionDistance:(NSInteger)junctionDistance
                    dayNightMode:(DayNightMode)dayNightMode
                  captureHandler:(void (^)(CaptureData *data, NSError *error))completionBlock;
/*
 * @brief 將特定經緯度轉換成某張圖上的座標點
 * @param location 座標點
 * @param contextAttr 圖片的屬性說明
 * @return PolnavPoint 螢幕上的座標點
 */
+ (PolnavPoint *)transformLocationToCapturedImagePosition:(LocationCoordinate *)location
                                              contextAttr:(NSString *)contextAttr;

#pragma mark - About Search
#pragma mark Nearby Search
/*
 * @brief 取得指定類別(或全部)的Nearby POI數量(可複選)。筆數最多回傳300筆，如果categoryList為nil，代表搜尋所有類別
 * @param location 座標點
 * @param categoryList 類別清單
 * @return Nearby POI數量
 */
+ (NSUInteger)nearbyPoiDataCount:(LocationCoordinate *)location
                    categoryList:(NSArray *)categoryList;
/*
 * @brief 取得該某一筆POI的詳細資料
 * @param index 座標點
 * @return PolnavPoiData POI相關資訊資料結構
 */
+ (PolnavPoiData *)nearbyPoiDataAtIndex:(NSUInteger)index;


#pragma mark FTS Search
//取得已安裝地圖的國家名稱清單
+ (NSMutableArray *)countries;
//設定FTS搜尋的國家
+ (void)selectCountryAtIndex:(NSUInteger)index;
/*
 * @brief 輸入搜尋字串進行搜尋
 * @param keyWord 搜尋字串
 */
+ (void)ftsRequestWithKeyWord:(NSString *)keyWord ftsHandler:(void (^)(void))completionBlock;
//取出搜尋結果筆數
+ (NSUInteger)ftsResultDataCount;
//上述API執行後，進一步取得某一筆資料的詳細資訊
+ (FtsResultData *)ftsResultDataAtIndex:(NSUInteger)index;
//若搜尋結果的類別是Street的話，可用此API查詢是否有其他道路和此道路相連成為交叉路口，並取出交叉路口的數量。
+ (NSUInteger)ftsIntersectionCountAtIndex:(NSUInteger)index;
//上述API執行後，進一步取得某一筆交叉路口的詳細資訊
+ (PolnavIntersectionData *)ftsIntersectionDataAtIndex:(NSUInteger)index;

@end

