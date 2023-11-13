//
//  XSTCollectionVo.h
//  resource_interaction_sdk
//
//  Created by 黄鹏艺 on 2023/7/4.
//

#import <Foundation/Foundation.h>
#import "ZXXResourceDetail.h"

NS_ASSUME_NONNULL_BEGIN

/// 收藏夹
@interface ZXXFavFolderItem : NSObject
@property (nonatomic, copy) NSString *folderId;              ///< 收藏夹id
@property (nonatomic, copy) NSString *folderName;            ///< 收藏夹名称
@property (nonatomic, copy) NSString *folderType;

- (instancetype)initWithDict:(NSDictionary *)dict;

- (instancetype)initWithSerDict:(NSDictionary *)dict;

- (NSDictionary *)modelToJson;

@end

/// 资源收藏模型
@interface ZXXFavResourceItem : ZXXResourceDetail
@property (nonatomic, copy, nullable) NSString *folderId;       ///< 收藏夹id，获取时会返回，取消收藏或判断是否收藏时不是必须的
@property (nonatomic, assign) BOOL collected;   // 是否收藏

- (instancetype)initWithDict:(NSDictionary *)dict;

- (instancetype)initWithSerDict:(NSDictionary *)dict;

- (NSDictionary *)modelToJson;

- (NSDictionary *)modeltoSerJson;

@end

NS_ASSUME_NONNULL_END
