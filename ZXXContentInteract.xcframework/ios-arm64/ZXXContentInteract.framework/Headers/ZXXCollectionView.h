//
//  XCICollectionView.h
//  AFNetworking
//
//  Created by 黄鹏艺 on 2023/7/4.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@class ZXXCollectionView;
@class ZXXFavResourceItem;

@protocol ZXXCollectionViewDelegate <NSObject>

// 传入一个资源模型
@required
- (ZXXFavResourceItem *)generalFavRerousceForCollect;

// 未登录回调
- (void)unLoginWithCollectionView:(ZXXCollectionView *)collectionView;

// 收藏回调
- (void)generateCollectionEventWithCollectionView:(ZXXCollectionView *)collectionView error:(NSError *)error;

// 取消收藏回调
- (void)generateCancelCollectionEventWithCollectionView:(ZXXCollectionView *)collectionView error:(NSError *)error;

@end

@interface ZXXCollectionView : UIView

@property (nonatomic, weak) id<ZXXCollectionViewDelegate> delegate;

- (instancetype)initWithFrame:(CGRect)frame resourceId:(NSString *)resourceId resourceType:(NSString *)resourceType;

@end

NS_ASSUME_NONNULL_END
