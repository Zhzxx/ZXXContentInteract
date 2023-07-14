//
//  ZXXEventObject.h
//  resource_interaction_sdk
//
//  Created by 黄鹏艺 on 2023/7/3.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZXXLikeStatuModel : NSObject

@property (nonatomic, copy) NSString *resourceId;           ///< resourceId
@property (nonatomic, assign) UInt64 count;                 ///< 点赞数
@property (nonatomic, assign) BOOL liked;                   ///< 当前用户是否点赞

- (instancetype)initWithDict:(NSDictionary *)dict;

- (NSDictionary *)modelToJson;

- (NSString *)countStr;

@end

NS_ASSUME_NONNULL_END
