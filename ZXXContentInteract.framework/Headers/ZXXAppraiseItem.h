//
//  ZXXAppraiseItem.h
//  resource_interaction_sdk
//
//  Created by 黄鹏艺 on 2023/7/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZXXAppraiseItem : NSObject

@property (nonatomic, copy) NSString *resourceId;                 ///< resourceId
@property (nonatomic, copy) NSString *type;                     ///< 资源类型
@property (nonatomic, assign) NSInteger count;         ///< 评价总数
@property (nonatomic, assign) CGFloat averagePoint;     ///< 评价平均分
@property (nonatomic, assign) BOOL appraised;                     ///< 当前用户是否已评价
@property (nonatomic, assign) CGFloat myAppraisePoint;             ///< 当前用户的评分
///<
- (instancetype)initWithSerDict:(NSDictionary *)dict;

@end

NS_ASSUME_NONNULL_END
