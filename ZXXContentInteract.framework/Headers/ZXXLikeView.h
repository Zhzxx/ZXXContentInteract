//
//  XCILikeView.h
//  resource_interaction_sdk
//
//  Created by 黄鹏艺 on 2023/7/3.
//

#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@class ZXXLikeView;

@protocol ZXXLikeViewDelegate <NSObject>

// 点赞成功或失败回调
- (void)generateLikeEventWithLikeView:(ZXXLikeView *)likeView error:(NSError *)error;

// 取消点赞成功或失败回调
- (void)generateUnlikeEventWithLikeView:(ZXXLikeView *)likeView error:(NSError *)error;

@end

@interface ZXXLikeView : UIView

- (instancetype)initWithFrame:(CGRect)frame resourceId:(NSString *)resourceId;

@property (nonatomic, weak) id<ZXXLikeViewDelegate> delegate;


@end

NS_ASSUME_NONNULL_END
