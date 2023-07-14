//
//  ZXXStudyItem.h
//  resource_interaction_sdk
//
//  Created by 黄鹏艺 on 2023/7/6.
//

#import "ZXXResourceDetail.h"

NS_ASSUME_NONNULL_BEGIN

@interface ZXXStudyItem : ZXXResourceDetail

@property (nonatomic, copy) NSString *catalogType;  /// 分类，必须，浏览历史页面中使用该分类进行分tab显示（如区域：areaSite）
@property (nonatomic, copy) NSString *topicType;    /// 主题类型
@property (nonatomic, assign) CGFloat progress;     /// 进度
@property (nonatomic, assign) int status;           /// 状态：0未开始，1进行中，2已完成

- (instancetype)initWithDict:(NSDictionary *)dict;

- (NSDictionary *)modelToJson;

@end

NS_ASSUME_NONNULL_END
