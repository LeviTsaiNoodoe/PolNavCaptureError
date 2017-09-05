//
//  PolnavViewController.h
//  polnavMap
//
//  Created by Zoey on 06/04/2017.
//  Copyright © 2017 Zoey. All rights reserved.
//

#import <UIKit/UIKit.h>
//地圖畫面操作的callback
@interface PolnavViewController : UIViewController <UIGestureRecognizerDelegate>

@property (nonatomic, readonly) UIView *polnavView;
/*
 * @brief 地圖點擊操作的回調函數
 */
- (void)handleTap:(UITapGestureRecognizer *)recognizer NS_REQUIRES_SUPER;
/*
 * @brief 地圖平移操作的回調函數
 */
- (void)handlePan:(UIPanGestureRecognizer *)recognizer NS_REQUIRES_SUPER;
/*
 * @brief 地圖縮放操作的回調函數
 */
- (void)handlePinch:(UIPinchGestureRecognizer *)recognizer NS_REQUIRES_SUPER;
/*
 * @brief 地圖選轉操作的回調函數
 */
- (void)handleRotation:(UIRotationGestureRecognizer *)recognizer NS_REQUIRES_SUPER;
/*
 * @brief 地圖長按操作的回調函數
 */
- (void)handleLongPress:(UILongPressGestureRecognizer *)recognizer NS_REQUIRES_SUPER;
/*
 * @brief 地圖畫面操作時，需要更新畫面的回調函數
 */
- (void)updateMoveUI;
@end
