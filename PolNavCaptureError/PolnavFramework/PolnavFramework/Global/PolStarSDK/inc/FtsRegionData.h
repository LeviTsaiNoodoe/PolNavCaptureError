//
//  FtsRegionData.h
//  PolnavSDKShell
//
//  Created by Zoey Yu on 16/01/2018.
//  Copyright © 2018 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>

@class FtsSubRegionData;
//FTS Region 資料結構
@interface FtsRegionData : NSObject

//Region 顯示名稱
@property (nonatomic, copy) NSString *mainRegionDisplayName;
//Region 顯示名稱[當地語言]
@property (nonatomic, copy) NSString *mainRegionDisplayLocalName;
//SubRegion 清單
@property (nonatomic, copy) NSMutableArray<FtsSubRegionData *> *subRegionList;

/*
 * @brief 根據Region資料生成FtsRegionData結構資料
 * @param mainRegionDisplayName Region 顯示名稱
 * @param mainRegionDisplayLocalName  Region 顯示名稱[當地語言]
 * @param subRegionList SubRegion 清單
 * @return 生成FtsRegionData結構資料
 */
- (instancetype)initWithMainRegionDisplayName:(NSString *)mainRegionDisplayName mainRegionDisplayLocalName:(NSString *)mainRegionDisplayLocalName subRegionList:(NSMutableArray *)subRegionList;
@end
