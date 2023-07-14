//
//  ZXXCommentView.h
//  AFNetworking
//
//  Created by 黄鹏艺 on 2023/7/4.
//

#import <UIKit/UIKit.h>
#import "ZXXAppraiseItem.h"

NS_ASSUME_NONNULL_BEGIN

@class ZXXCommentView;

@protocol ZXXCommentViewDelegate <NSObject>

// 未登录回调函数
- (void)unLoginWithCommentView:(ZXXCommentView *)commentView;

// 评分完成回调函数
- (void)completeCommentWithView:(ZXXCommentView *)commentView appraiseItem:(ZXXAppraiseItem *)item;

// 评分失败回调函数
- (void)failCommentWithView:(ZXXCommentView *)commentView error:(NSError *)error;

@end

@interface ZXXCommentView : UIView

@property (nonatomic, weak) id<ZXXCommentViewDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame resourceId:(NSString *)resourceId resourceType:(NSString *)resourceType;

@end

NS_ASSUME_NONNULL_END
