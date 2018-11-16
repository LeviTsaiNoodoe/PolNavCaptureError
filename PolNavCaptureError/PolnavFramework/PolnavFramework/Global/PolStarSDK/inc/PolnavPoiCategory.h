//
//  PolnavPoiCategory.h
//  PolnavSDKShell
//
//  Created by Zoey on 17/07/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//POI類型
@interface PolnavPoiCategory : NSObject

extern int const PoiCategoryRailwayStation,  //火車站
                 PoiCategoryAirPort,         //機場
                 PoiCategoryBusStation,      //公車站
                 PoiCategoryFerryTerminal,   //水運站
                 PoiCategoryParkingRestArea, //停車場/休息站
                 PoiCategoryCarRental,       //租車
                 PoiCategoryCarRepair,       //修車
                 PoiCategoryAutoDealer,      //車廠
                 PoiCategoryGasStation,      //加油站
                 PoiCategoryBorderCross,     //邊界
                 PoiCategoryKYMCO,           //光陽經銷商

                 PoiCategoryShop,            //購物
                 PoiCategoryGroceryStore,    //便利商店
                 PoiCategoryPharmacy,        //藥局
                 PoiCategoryBookStore,       //書局
                 PoiCategorySportGoods,      //運動器材

                 PoiCategorySportCenter,     //健身中心
                 PoiCategoryStadiumSportClub,//體育場館
                 PoiCategoryIceSkatingRink,  //溜冰場
                 PoiCategoryBowling,         //保齡球館
                 PoiCategoryGolfCourse,      //高爾夫球場
                 PoiCategorySportAirport,    //飛航運動場
                 PoiCategoryMarina,          //遊艇碼頭
                 PoiCategoryAutoClub,        //賽車場

                 PoiCategoryCasino,          //賭場
                 PoiCategoryPerformArt,      //表演藝術
                 PoiCategoryMovieTheater,    //電影院
                 PoiCategoryBarPubNightClub, //酒吧/夜店

                 PoiCategoryMuseumMonument,  //博物館
                 PoiCategoryAmusementPark,   //主題樂園
                 PoiCategoryTouristAttration,//觀光景點
                 PoiCategoryTouristInfo,     //觀光資訊
                 PoiCategorySkiResort,       //滑雪場
                 PoiCategoryWinery,          //酒廠
                 PoiCategoryPark,            //國家公園/花園

                 PoiCategoryRestaurant,      //餐飲
                 PoiCategoryCoffeeShop,      //咖啡店

                 PoiCategoryCommunityCenter, //社區活動中心
                 PoiCategoryCityHall,        //政府/公所
                 PoiCategoryCouncil,         //議會
                 PoiCategoryCourtHouse,      //法院
                 PoiCategoryEmbassy,         //大使館
                 PoiCategoryHighEducation,   //高等教育機構
                 PoiCategorySchool,          //中小學校
                 PoiCategoryLibrary,         //圖書館
                 PoiCategoryExhibitionCenter,//展覽場
                 PoiCategoryReligion,        //寺廟/教堂
                 PoiCategoryIndustrialZone,  //工業區
                 PoiCategorySettlementZone,  //住宅區

                 PoiCategoryHospitalClinic,  //醫院
                 PoiCategoryPoliceStation,   //警察消防

                 PoiCategoryHotelMotel,      //旅館
                 PoiCategoryGuestHouse,      //民宿

                 PoiCategoryPostOffice,      //郵局
                 PoiCategoryBusiness,        //企業/公司
                 PoiCategoryBank,            //銀行
                 PoiCategoryATM,             //自動提款機
                 PoiCategoryMedicalService,  //醫學中心
                 PoiCategoryCommonService;   //一般服務
@end
