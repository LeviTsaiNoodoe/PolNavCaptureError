//
//  FtsSubRegionData.h
//  PolnavSDKShell
//
//  Created by Zoey Yu on 16/01/2018.
//  Copyright © 2018 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//FTS SubRegion 資料結構
@interface FtsSubRegionData : NSObject

//SubRegion 名稱
@property (nonatomic, copy) NSString *name;
//SubRegion 名稱[當地語言]
@property (nonatomic, copy) NSString *localName;
//SubRegion ID
@property (nonatomic, assign) NSUInteger ID;

/*
 * @brief 根據SubRegion資料生成FtsSubRegionData結構資料
 * @param name SubRegion 名稱
 * @param localName SubRegion 名稱[當地語言]
 * @param ID SubRegion ID
 * @return 生成FtsSubRegionData結構資料
 */
- (instancetype)initWithName:(NSString *)name localName:(NSString *)localName ID:(NSUInteger)ID;

@end
