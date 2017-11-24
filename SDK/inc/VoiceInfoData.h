//
//  VoiceInfoData.h
//  PolnavSDKShell
//
//  Created by Zoey Yu on 31/10/2017.
//  Copyright © 2017 Polstar. All rights reserved.
//

#import <Foundation/Foundation.h>
//聲音檔相關結構資料
@interface VoiceInfoData : NSObject

//聲音檔下載完解開後的名稱
@property (nonatomic, copy) NSString *voiceName;
//聲音檔存在server的.zip檔名
@property (nonatomic, copy) NSString *voiceFileName;
//聲音檔打包的時間
@property (nonatomic, copy) NSDate *buildDate;
//.zip檔聲音檔大小
@property (nonatomic, assign) CGFloat fileSize;
//聲音檔解壓縮後的大小
@property (nonatomic, assign) CGFloat fullFileSize;

/*
 * @brief 根據聲音檔相關資料生成VoiceInfoData結構資料
 * @param voiceName 聲音檔名稱
 * @param voiceFileName 聲音檔存在server的.zip檔名
 * @param buildDate 聲音檔打包的時間
 * @param fileSize .zip檔聲音檔大小
 * @param fullFileSize 聲音檔解壓縮後的大小
 * @return 生成VoiceInfoData聲音檔相關結構資料
 */
- (instancetype)initWithVoiceName:(NSString *)voiceName voiceFileName:(NSString *)voiceFileName buildDate:(NSDate *)buildDate fileSize:(CGFloat)fileSize fullFileSize:(CGFloat)fullFileSize;

@end

