//
//  VoiceInfoData.h
//  PolnavSDKShell
//
//  Created by Zoey Yu on 31/10/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//Server上的聲音檔相關結構資料
@interface PolnavServerVoiceInfoData : NSObject

//聲音檔下載完解開後的名稱
@property (nonatomic, copy) NSString *voiceName;
//聲音檔下載完解開後的名稱[當地語言]
@property (nonatomic, copy) NSString *voiceLocalName;
//聲音檔存在server的.zip檔名
@property (nonatomic, copy) NSString *voiceFileName;
//聲音檔打包的時間
@property (nonatomic, copy) NSDate *buildDate;
//.zip檔聲音檔大小
@property (nonatomic, assign) CGFloat fileSize;
//聲音檔解壓縮後的大小
@property (nonatomic, assign) CGFloat fullFileSize;
//此版本語音是否已安裝在/Sound/資料夾中
@property (nonatomic, assign) BOOL isVoiceInstalled;
/*
 * @brief 根據聲音檔相關資料生成PolnavServerVoiceInfoData結構資料
 * @param voiceName 聲音檔名稱
 * @param voiceLocalName 聲音檔下載完解開後的名稱[當地語言]
 * @param voiceFileName 聲音檔存在server的.zip檔名
 * @param buildDate 聲音檔打包的時間
 * @param fileSize .zip檔聲音檔大小
 * @param fullFileSize 聲音檔解壓縮後的大小
 * @param isVoiceInstalled 此版本語音是否已安裝在/Sound/資料夾中
 * @return 生成PolnavServerVoiceInfoData聲音檔相關結構資料
 */
- (instancetype)initWithVoiceName:(NSString *)voiceName voiceLocalName:(NSString *)voiceLocalName voiceFileName:(NSString *)voiceFileName buildDate:(NSDate *)buildDate fileSize:(CGFloat)fileSize fullFileSize:(CGFloat)fullFileSize isVoiceInstalled:(BOOL)isVoiceInstalled;


@end
