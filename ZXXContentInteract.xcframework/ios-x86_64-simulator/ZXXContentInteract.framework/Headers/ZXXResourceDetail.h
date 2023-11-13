//
//  XSTResourceDetail.h
//  resource_interaction_sdk
//
//  Created by 黄鹏艺 on 2023/7/4.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ZXXResourceDetail : NSObject

@property (nonatomic, copy) NSString *tag;                     ///< 标签编码
@property (nonatomic, copy) NSString *resourceId;               ///< 资源id（课本id、课程id等UUID）
@property (nonatomic, copy) NSString *resourceType;             ///< 资源类型
@property (nonatomic, copy, nullable) NSString *resourceName;   ///< 资源名称（标题）
@property (nonatomic, copy, nullable) NSString *coverUrl;       ///< 封面url，可以为空
@property (nonatomic, copy, nullable) NSString *resourceDesc;   ///< 资源副标题（描术等）
@property (nonatomic, copy, nullable) NSDictionary *extInfo;    ///< 扩展数据（资源本身需要的字段可以放在该扩展信息中透传）
@property (nonatomic, copy, nullable) NSString *targetUrl;      ///< 资源跳转地址

@end

NS_ASSUME_NONNULL_END
