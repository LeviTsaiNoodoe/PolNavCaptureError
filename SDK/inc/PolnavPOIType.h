//
//  PolnavPOIType.h
//  PolnavSDKShell
//
//  Created by Zoey on 17/07/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//POI類型
@interface PolnavPOIType : NSObject

extern int const NearbyTypeRailwayStation,  //火車站
                 NearbyTypeAirPort,         //機場
                 NearbyTypeBusStation,      //公車站
                 NearbyTypeFerryTerminal,   //水運站
                 NearbyTypeParkingRestArea, //停車場/休息站
                 NearbyTypeCarRental,       //租車
                 NearbyTypeCarRepair,       //修車
                 NearbyTypeAutoDealer,      //車廠
                 NearbyTypeGasStation,      //加油站
                 NearbyTypeBorderCross,     //邊界
                 NearbyTypeRoadSign,        //路牌

                 NearbyTypeShop,            //購物
                 NearbyTypeGroceryStore,    //便利商店
                 NearbyTypePharmacy,        //藥局
                 NearbyTypeBookStore,       //書局
                 NearbyTypeSportGoods,      //運動器材

                 NearbyTypeSportCenter,     //健身中心
                 NearbyTypeStadiumSportClub,//體育場館
                 NearbyTypeIceSkatingRink,  //溜冰場
                 NearbyTypeBowling,         //保齡球館
                 NearbyTypeGolfCourse,      //高爾夫球場
                 NearbyTypeSportAirport,    //飛航運動場
                 NearbyTypeMarina,          //遊艇碼頭
                 NearbyTypeAutoClub,        //賽車場

                 NearbyTypeCasino,          //賭場
                 NearbyTypePerformArt,      //表演藝術
                 NearbyTypeMovieTheater,    //電影院
                 NearbyTypeBarPubNightClub, //酒吧/夜店

                 NearbyTypeMuseumMonument,  //博物館
                 NearbyTypeAmusementPark,   //主題樂園
                 NearbyTypeTouristAttration,//觀光景點
                 NearbyTypeTouristInfo,     //觀光資訊
                 NearbyTypeSkiResort,       //滑雪場
                 NearbyTypeWinery,          //酒廠
                 NearbyTypePark,            //國家公園/花園

                 NearbyTypeRestaurant,      //餐飲
                 NearbyTypeCoffeeShop,      //咖啡店

                 NearbyTypeCommunityCenter, //社區活動中心
                 NearbyTypeCityHall,        //政府/公所
                 NearbyTypeCouncil,         //議會
                 NearbyTypeCourtHouse,      //法院
                 NearbyTypeEmbassy,         //大使館
                 NearbyTypeHighEducation,   //高等教育機構
                 NearbyTypeSchool,          //中小學校
                 NearbyTypeLibrary,         //圖書館
                 NearbyTypeExhibitionCenter,//展覽場
                 NearbyTypeReligion,        //寺廟/教堂
                 NearbyTypeIndustrialZone,  //工業區
                 NearbyTypeSettlementZone,  //住宅區

                 NearbyTypeHospitalClinic,  //醫院
                 NearbyTypePoliceStation,   //警察消防

                 NearbyTypeHotelMotel,      //旅館
                 NearbyTypeGuestHouse,      //民宿

                 NearbyTypePostOffice,      //郵局
                 NearbyTypeBusiness,        //企業/公司
                 NearbyTypeBank,            //銀行
                 NearbyTypeATM,             //自動提款機
                 NearbyTypeMedicalService,  //醫學中心
                 NearbyTypeCommonService;   //一般服務
@end
