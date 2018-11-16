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
#import "PolnavPoiCategory.h"
#import "DeviceValidInstalledInfoData.h"

@protocol PolnavRouteDelegate;
@protocol PolnavLicenseDelegate;

@class PolnavPointRecord;
@class TurnInfoData;
@class PolnavPoiData;
@class FtsResultData;
@class NaviMatrixData;
@class CaptureData;
@class MapGeocoding;
@class PolnavIntersectionData;
@class CaptureNaviImageRequestData;
@class FtsRegionData;
@class RoutePlanOptionData;

@class PolnavServerProductInfoData;
@class PolnavServerMapInfoData;
@class PolnavServerVoiceInfoData;
@class MapWarrantyData;

typedef NS_ENUM(NSUInteger, CaptureType);

//地圖顯示模式
typedef NS_ENUM(NSUInteger, MapMode) {
    MapModeNaviViewNorthUp2D = 0,      //導航正北向上
    MapModeNaviViewHeadingUp2D = 1,    //導航2D車頭向上
    MapModeNaviViewHeadingUp3D = 2,    //導航3D車頭向上
    MapModeMapView = 3,                //地圖顯示模式
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

//SDK init 狀態類型
typedef NS_ENUM(NSUInteger, SDKInitStatus) {
    SDKInitStatusErrorUUIDNull = 96,                    //UUID值不正確
    SDKInitStatusErrorPhoneIDNull = 97,                 //PhoneID值不正確
    SDKInitStatusErrorMoterCCValue = 98,                //MoterCCValue值不正確
    SDKInitStatusErrorPolnavMobileFolderNotExist = 99,  //PolnavMobile資料夾不存在正確位置
    SDKInitStatusErrorWriteProtect = 100,               //儲存裝置處於防寫狀態
    SDKInitStatusErrorVirtualMemoryNotEnough = 102,     //虛擬記憶體不足
    SDKInitStatusErrorNoMap = 103,                      //無法打開地圖(可能是Map資料夾或BaseMap不存在)
    SDKInitStatusSuccess = 109,                         //初始化成功
};

//測速照相提示距離
typedef NS_ENUM(NSUInteger, SpeedCameraAlertDistance) {
    SpeedCameraAlertDistanceAuto, //Calculate distance according to car speed
    SpeedCameraAlertDistance300M, //300m(0.2mile)
    SpeedCameraAlertDistance500M, //500m(0.3mile)
    SpeedCameraAlertDistance800M, //800m(0.5mile)
    SpeedCameraAlertDistance1KM,  //1km(0.6mile)
};

//FTS排序方式
typedef NS_ENUM(NSUInteger, FTSSortOption) {
    FTSSortOptionDefault,   //原本的排序
    FTSSortOptionDistance   //依距離排序
};

@interface PolnavSDKShell : NSObject

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
/*
 * @brief 將裝置座標換算成經緯度
 * @param devicePoint 裝置座標
 * @return LocationCoordinate 經緯度座標
 */
+ (LocationCoordinate *)getLocationCoordinateWithDevicePoint:(CGPoint)devicePoint;
/*
 * @brief 判斷目前時間是否為日間模式
 */
+ (BOOL)isCurrentTimeDayStatus;
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
 * @param speed 車速
 */
+ (void)startSimulateWithNaviSpeed:(NSInteger)speed;
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
+ (TurnInfoData *)turnDataAtIndex:(NSUInteger)index;
/*
 * @brief 取得導航相關資訊
 * @param speedKmh 車速
 * @return NaviMatrixData 導航相關資訊資料結構
 */
+ (NaviMatrixData *)naviMatrixDataWithCarSpeed:(NSInteger)speedKmh;
/*
 * @brief 該點是否為合法導航點 (此API僅判斷是否有鄰近道路，不能確保一定可規劃出路徑)
 * @param location 座標點
 */
+ (BOOL)canRouteWithLocation:(LocationCoordinate *)location;
/*
 * @brief 取得導航引擎RouteOption設定值
 * @return RoutePlanOptionData RouteOption設定值
 */
+ (RoutePlanOptionData *)getRoutePlanOptionData;
/*
 * @brief 播放駛入禁行道路的警示音檔
 */
 + (void)promptMotorClosedVoice;
/*
 * @brief 設定進入機車進行道路Alarm播放頻率
 * 備註：
 * sec < 0 代表關閉播放alarm音檔
 * sec = 0 代表使用預設的頻率播放alarm音檔
 * sec > 0 代表使用此設定值的頻率播放alarm音檔
 */
+ (void)setMotorClosedPromptVoicePeriod:(NSInteger)sec;
/*
 * @brief 取得進入機車進行道路Alarm播放頻率
 */
+ (NSInteger)motorClosedPromptVoicePeriod;

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
 * @param languageName 語音語言名稱
 */
+ (BOOL)configVoiceLanguage:(NSString *)languageName;
/*
 * @brief 設定道路文字大小
 * @param textRatio 文字大小
 */
+ (void)configMapStreetTextRatio:(CGFloat)textRatio;
/*
 * @brief 設定是否顯示起點/中途點/終點
 * @param drawStartPoint 是否顯示起點
 * @param drawWayPoint 是否顯示中途點
 * @param drawDestination 是否顯示終點
 */
+ (void)configMapDrawItineraryWithDrawStartPoint:(BOOL)drawStartPoint
                                    drawWayPoint:(BOOL)drawWayPoint
                                 drawDestination:(BOOL)drawDestination;
/*
 * @brief 設定地圖只顯示某些POI類別
 * @param categories POI類別 (categories傳nil，表示開啟全部POI類別)
 */
+ (void)configPoiShowOnMapWithPoiCategories:(NSArray *)categories;
/*
 * @brief 設定是否靜音
 * @param isMute 是否靜音
 */
+ (void)configVolumeMute:(BOOL)isMute;
/*
 * @brief 設定是否開啟鬼影車標(Debug用)
 * @param isEnable 是否開啟
 */
+ (void)configGhostCarEnable:(BOOL)isEnable;
/*
 * @brief 設定模擬導航是否Repeat播放
 * @param isRepeat 是否重覆
 */
+ (void)configRepeatSimulateNavi:(BOOL)isRepeat;
/*
 * @brief 設定測速照相提示距離
 * @param alertDistance 提示距離
 */
+ (void)configSpeedCameraAleartDistance:(SpeedCameraAlertDistance)alertDistance;
/*
 * @brief 設定導航引擎RouteOption設定值
 * @param routeOption RouteOption設定值
 */
+ (void)setRoutePlanOption:(RoutePlanOptionData *)routeOption;
/*
 * @brief 工程版API:(Release時勿使用)動態調整摩托車CC數
 * @param motorCCValue 機車CC數
 */
+ (BOOL)changeMotorCCValue:(NSUInteger)motorCCValue;
/*
 * @brief 工程版API:(Release時勿使用)切換到汽車模式
 */
+ (void)changeToCarMode;
/*
 * @brief 設定SDK在MMT時對禁行道路的懲罰值
 * @param MMTPenaltyOnClosedRoad 禁行道路的懲罰值
 備註：
 penalty=0代表不懲罰，看GPS訊號比較靠近哪條路
 若無呼叫此API，SDK預設penalty=20
 */
+ (void)setMMTPenaltyOnClosedRoad:(NSInteger)MMTPenaltyOnClosedRoad;
/*
 * @brief 取得SDK在MMT時對禁行道路的懲罰值
 */
+ (NSInteger)MMTPenaltyOnClosedRoad;
#pragma mark - D. Capture
/*
 * @brief 截取畫面
 * @param captureParam 截圖相關設定結構資料
 * @return data 截取畫面的CaptureData資料
 * @return error 錯誤訊息
 */
+ (void)captureNaviImageWithCaptureParam:(CaptureNaviImageRequestData *)captureParam
                          captureHandler:(void (^)(CaptureData *data, NSError *error))completionBlock;
/*
 * @brief 將特定經緯度轉換成某張圖上的座標點
 * @param location 座標點
 * @param contextAttr 圖片的屬性說明
 * @return PolnavPoint 螢幕上的座標點
 */
+ (PolnavPoint *)transformLocationToCapturedImagePosition:(LocationCoordinate *)location
                                              contextAttr:(NSString *)contextAttr;
/*
 * @brief 任意點截圖(LocationView)
 * @param location 座標點
 * @param angle 角度值
 * @param is3DView  是否3DView
 * @param isShowLabel 是否顯示道路名稱
 * @param isShowPOI 是否顯示POI
 * @param isShowOneWay 是否顯示單行道符號
 * @param isShowSpeedCamera 是否顯示測速照相機
 * @param isShowCar 是否顯示車標
 * @param dayNightMode 指定截圖的日夜間模式。dayNightMode的設定值同API: configDayNightMode。輸入DayNightModeAuto代表截圖的日夜間同地圖顯示的模式。
 * @param streetRatio 街道寬度
 * @param textRatio 文字寬度
 * @param isApplyDpi for Apply Device DPI
 * @return data 截取畫面的CaptureData資料
 * @return error 錯誤訊息
 */
+ (void)captureLocationViewWithlocation:(LocationCoordinate *)location
                                  angle:(NSInteger)angle
                               is3DView:(BOOL)is3DView
                            isShowLabel:(BOOL)isShowLabel
                              isShowPOI:(BOOL)isShowPOI
                           isShowOneWay:(BOOL)isShowOneWay
                      isShowSpeedCamera:(BOOL)isShowSpeedCamera
                              isShowCar:(BOOL)isShowCar
                           dayNightMode:(DayNightMode)dayNightMode
                            streetRatio:(CGFloat)streetRatio
                              textRatio:(CGFloat)textRatio
                             isApplyDpi:(BOOL)isApplyDpi
                         captureHandler:(void (^)(CaptureData *data, NSError *error))completionBlock;

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
/*
 * @brief 取得已安裝地圖的區域名稱清單(FTS一次只能search某個SubRegion，請從此API取出想要search的SubRegion後，將其ID傳給F2的API來選定區域)
 * @param ftsRegionList 區域名稱清單
 */
+ (NSMutableArray<FtsRegionData *> *)ftsRegionList;
/*
 * @brief 設定FTS搜尋的區域
 * @param rigionID 區域ID
 */
+ (void)selectFtsRegionWithRegionID:(NSUInteger)rigionID;
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
/*
 * @brief 切換搜尋的排序方式
 * @param option 排序方式
 */
+ (void)changeFtsSortOption:(FTSSortOption)option;
#pragma mark - ***** G. About License  *****
/*
 * @brief 新增PolnavLicenseDelegate協議
 * @param delegate 通知更新與安裝授權完成的 PolnavLicenseDelegate
 */
+ (void)addLicenseDelegate:(id<PolnavLicenseDelegate>)delegate;
/*
 * @brief 移除PolnavLicenseDelegate協議
 * @param delegate 通知更新與安裝授權完成的 PolnavLicenseDelegate
 */
+ (void)removeLicenseDelegate:(id<PolnavLicenseDelegate>)delegate;
/*
 * @brief 更新Product/Map/Voice相關資訊，才能知道是否有新版Release
 */
+ (void)updateProductMapVoiceInfo;
/*
 * @brief 安裝指定地圖的授權Key
 * @param mapName 地圖名稱
 * @param mapCode 地圖版本
 * @param productName 產品名稱
 * @param reason 安裝原因;reason請Noodoe定義，原則是一個英文單字，請勿填寫空白與特殊字元
 */
+ (void)installLicenseKeyWithMapName:(NSString *)mapName mapCode:(NSString *)mapCode reason:(NSString *)reason productName:(NSString *)productName;
/*
 * @brief 取得Server上的產品清單
 */
+ (NSMutableArray<PolnavServerProductInfoData *> *)polnavServerProductInfoDataList;
/*
 * @brief 取得Server上的地圖檔清單
 */
+ (NSMutableArray<PolnavServerMapInfoData *> *)polnavServerMapInfoDataList;
/*
 * @brief 取得Server上的聲音檔清單
 */
+ (NSMutableArray<PolnavServerVoiceInfoData *> *)polnavServerVoiceInfoDataList;
/*
 * @brief 取得地圖檔下載的Server URL
 * @param mapName 地圖名稱
 */
+ (NSString *)mapFileServerURLWithMapName:(NSString *)mapName;
/*
 * @brief 取得聲音檔下載的Server URL
 */
+ (NSString *)voiceFileServerURL;
/*
 * @brief 取得手機上合法安裝的地圖清單
 */
+ (NSMutableArray<DeviceValidInstalledMapInfoData *> *)deviceValidInstalledMapInfoDataList;
/*
 * @brief 取得手機上合法安裝的語音清單
 */
+ (NSMutableArray<DeviceValidInstalledVoiceInfoData *> *)deviceValidInstalledVoiceInfoDataList;

#pragma mark - SDK init Status
/*
 * @brief 初始化設定Init Method
 * @param resourcePath 圖資檔案位置路徑
 * @param noodoeUUID noodoe識別碼
 * @param phoneID 手機識別碼
 * @param motorCCValue 機車CC數
 * @param mapWarrantyList 合法取得的地圖清單與授權保固截止日期
 * @return SDKInitStatus SDK init 狀態類型
 */
+ (SDKInitStatus)startWithResourcePath:(NSString *)resourcePath
                            noodoeUUID:(NSString *)noodoeUUID
                               phoneID:(NSString *)phoneID
                       mapWarrantyList:(NSMutableArray<MapWarrantyData *> *)mapWarrantyList
                          motorCCValue:(NSUInteger)motorCCValue;

#pragma mark - ***** GPS *****
/*
 * @brief 設定是否更新GPS座標
 * @param enable 是否開GPS
 */
+ (void)configGPSEnable:(BOOL)enable;
/*
 * @brief 設定Replay NMEA File
 * @param fileFullPath 檔案路徑
 */
+ (void)startPlayNMEALog:(NSString *)fileFullPath;
/*
 * @brief 停止 Replay NMEA
 */
+ (void)stopPlayNMEALog;

@end

