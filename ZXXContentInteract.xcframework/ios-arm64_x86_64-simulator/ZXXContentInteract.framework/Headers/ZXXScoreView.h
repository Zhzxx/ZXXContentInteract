//
//  ZXXScoreView.h
//  resource_interaction_sdk
//
//  Created by 黄鹏艺 on 2023/7/4.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZXXScoreView : UIView

- (instancetype)initWithFrame:(CGRect)frame resourceId:(NSString *)resourceId resourceType:(NSString *)resourceType;

- (void)updateScore:(NSNumber *)score totalNumber:(NSInteger)number;

- (void)reloadData;

@end

NS_ASSUME_NONNULL_END
