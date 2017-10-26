//
//  TripInfoData.h
//  PolnavSDKShell
//
//  Created by Zoey on 25/05/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "PolnavStructData.h"
//旅程相關資訊資料結構
@interface TripInfoData : NSObject

//預計下個目的地抵達時間
@property (nonatomic) CommonValueUnit *ETA;
//距離下個目的地之距離
@property (nonatomic) CommonValueUnit *DTG;
//預計下個目的地還需行駛多久時間
@property (nonatomic) CommonValueUnit *TTG;


/*
 * @brief 根據旅程相關資料生成TripInfoData結構資料
 * @param distanceToWay 預計下個目的抵達時間
 * @param timeToWay 距離下個目的地之距離
 * @param timeAtWay 預計下個目的地還需行駛多久時間
 * @return 生成TripInfoData結構資料
 */
- (instancetype)initWithDTG:(CommonValueUnit *)distanceToWay
                        TTG:(CommonValueUnit *)timeToWay
                        ETA:(CommonValueUnit *)timeAtWay;
@end
