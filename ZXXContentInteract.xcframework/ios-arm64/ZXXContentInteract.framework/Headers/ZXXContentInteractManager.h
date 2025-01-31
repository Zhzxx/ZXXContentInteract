//
//  ZXXContentInteractManager.h
//  AFNetworking
//
//  Created by 黄鹏艺 on 2023/7/4.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@class ZXXFavFolderItem;
@class ZXXFavResourceItem;
@class ZXXResourceDetail;
@class ZXXStudyItem;

typedef enum : NSUInteger {
    ZXXEnvPreproduction,
    ZXXEnvEduproduction,
} ZXXEnv;

@interface ZXXContentInteractManager : NSObject

typedef void(^ZXXCompletionBlk)(id _Nullable resData, NSError * _Nullable error);

+ (instancetype)shareInstance;

/** 设置AppKey
@param appKey 申请的appkey.
@param appKey 申请的secretKey.
*/
- (void)setAppKey:(NSString *)appKey secretKey:(NSString *)secretKey;

/** 登录通行证id
@param userId 通行证id
*/
- (void)loginWithUserId:(NSString *)userId;

/// 登出
- (void)logout;

/** 设置环境
@param env 环境枚举 ZXXEnvPreproduction预生产环境，ZXXEnvEduproduction百度环境
*/
- (void)setEnvironment:(ZXXEnv)env;

/** 设置环境
@param env 环境枚举 ZXXEnvPreproduction预生产环境，ZXXEnvEduproduction百度环境
@param domain 域名，可以不填为nil
*/
- (void)setEnvironment:(ZXXEnv)env domain:(NSString *)domain;


#pragma mark - 点赞
/** 单个资源获取点赞状态
 @param resourceId 需要获取点赞的资源id.
 @param anonymous 是否使用匿名模式
 @param completion 回调 resData 为ZXXLikeStatuModel对象 当error有值时表示请求失败
 */
- (void)likeStateWithResourceId:(NSString *)resourceId
                      anonymous:(BOOL)anonymous
                     completion:(ZXXCompletionBlk)completion;

/** 批量获取资源的点赞数据(超过20个分批获取)
 @param resourceIds 资源id列表
 @param anonymous 是否使用匿名模式
 @param completion 回调 resData 为NSArray<ZXXLikeStatuModel *>对象
 */
- (void)listLikeState:(NSArray<NSString *> *)resourceIds
            anonymous:(BOOL)anonymous
           completion:(ZXXCompletionBlk)completion;

/** 为资源点赞
 @param resourceId     资源id
 @param completion     回调 resData 为ZXXLikeStatuModel对象 当error有值时表示请求失败
 */
- (void)likeResource:(NSString *)resourceId completion:(ZXXCompletionBlk)completion;

/** 取消点赞
 @param resourceId     资源id
 @param completion     回调 resData 为ZXXLikeStatuModel对象 当error有值时表示请求失败
 */
- (void)unLikeResource:(NSString *)resourceId completion:(ZXXCompletionBlk)completion;

#pragma mark - 收藏

/** 判断资源是否已经收藏
@param resourceId      资源id
@param type           资源类型
@param completion     回调 resData 为是否已收藏@(YES)/@(NO)
*/
- (void)hasBeenFavorited:(NSString *)resourceId type:(NSString *)type completion:(ZXXCompletionBlk)completion;

/** 获取收藏夹列表
 @param forceRequest 是否强制刷新
 @param completion 回调 resData 为ZXXFavFolderItem对象数组
 */
- (void)favoriteFolderListForceRequest:(BOOL)forceRequest completion:(ZXXCompletionBlk)completion;

/** 创建收藏夹
 @param name 收藏夹名称
 @param completion 回调 resData 为ZXXFavFolderItem对象
 */
- (void)favoriteFolderCreate:(NSString *)name completion:(ZXXCompletionBlk)completion;

/** 修改收藏夹
 @param item 收藏夹实体
 @param completion 回调 resData 为ZXXFavFolderItem对象
 */
- (void)favoriteFolderRename:(ZXXFavFolderItem *)item completion:(ZXXCompletionBlk)completion;

/** 删除收藏夹
 @param item 收藏夹实体
 @param completion 状态
 */
- (void)favoriteFolderRemove:(ZXXFavFolderItem *)item completion:(ZXXCompletionBlk)completion;

/** 收藏资源
 @param item  收藏的资源对象，收藏夹id可为空，收藏到默认收藏夹
 @param completion 回调 resData 是否收藏成功@(YES)/@(NO)
 */
- (void)favoriteResourceWithItem:(ZXXFavResourceItem *)item completion:(ZXXCompletionBlk)completion;

/** 取消收藏资源
 @param resourceId      资源id
 @param type           资源类型
 @param completion     回调 resData 为是否取消成功@(YES)/@(NO)
 */
- (void)delFavoriteResource:(NSString *)resourceId type:(NSString *)type completion:(ZXXCompletionBlk)completion;
/** 批量取消指定的已收藏资源
 @param items         已收藏的资源数组（只需要资源id和资源类型）
 @param completion     回调 resData 为是否取消成功@(YES)/@(NO)
 */
- (void)delFavoriteResources:(NSArray<ZXXResourceDetail *> *)items completion:(ZXXCompletionBlk)completion;

/** 按收藏夹查询收藏列表（全量）
@param folderId      收藏夹id
@param forceRequest 是否强制刷新
@param completion     回调 resData 为ZXXFavFolderItem对象数组
*/
- (void)favoriteResourceListWithFolderId:(NSString *)folderId forceRequest:(BOOL)forceRequest completion:(ZXXCompletionBlk)completion;

/** 按收藏夹查询收藏列表（全量）
@param folderId      收藏夹id
@param offset 偏移量默认0
@param limit 大小默认20
@param forceRequest 是否强制刷新
@param completion     回调 resData 为ZXXFavFolderItem对象数组
*/
- (void)favoriteResourceListWithFolderId:(NSString *)folderId offset:(NSInteger)offset limit:(NSInteger)limit forceRequest:(BOOL)forceRequest completion:(ZXXCompletionBlk)completion;

#pragma mark - 评分
/** 提交评分
@param resourceId     资源id
@param type         资源类型
@param score         评价分数
@param completion     完成回调
*/
- (void)appraiseDataWithResourceId:(NSString *)resourceId
                              type:(NSString *)type
                             score:(NSInteger)score
                        completion:(ZXXCompletionBlk)completion;

/** 获取评分
@param resourceId 资源id
@param type 资源类型
@param anonymous 是否使用匿名模式
@param completion 回调 resData 为ZXXAppraiseItem对象
*/
- (void)getAppraiseDataWithResourceId:(NSString *)resourceId
                                 type:(NSString *)type
                            anonymous:(BOOL)anonymous
                           completion:(ZXXCompletionBlk)completion;

/** 批量获取评分
@param resourceIds 资源ids
@param type 资源类型
@param anonymous 是否使用匿名模式
@param completion 回调 resData 为ZXXAppraiseMultiItem对象
*/
- (void)batchAppraiseDataWithResourceId:(NSArray <NSString *>*)resourceIds
                                   type:(NSString *)type
                              anonymous:(BOOL)anonymous
                             completion:(ZXXCompletionBlk)completion;

/** 上报浏览记录
@param item 资源
@param completion 回调 resData 为是否成功@(YES)/@(NO)
*/
- (void)updateStudyItem:(ZXXStudyItem *)item completion:(ZXXCompletionBlk)completion;

/** 浏览记录列表
@param catalogType     分类，为空时全部
@param offset         偏移量
@param limit          条数上限
@param completion     回调 resData ZXXStudyItem数组
*/
- (void)studyListWithCatalogType:(nullable NSString *)catalogType
                          offset:(NSInteger)offset
                           limit:(NSInteger)limit
                      completion:(ZXXCompletionBlk)completion;
@end

NS_ASSUME_NONNULL_END
