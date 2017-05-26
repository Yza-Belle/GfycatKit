//
//  GFYArraySource.h
//  GfycatKit
//
//  Created by Victor Pavlychko on 3/7/17.
//  Copyright © 2017 GfyCat. All rights reserved.
//
//  GFYCAT_LICENSE
//

#import <GfycatApiKit/GfycatApiKit.h>
#import "GFYInterfaceAnalytics.h"

NS_ASSUME_NONNULL_BEGIN

@protocol GFYArrayProvider;
@protocol GFYArrayConsumer;
@protocol GfycatBlackListCache;

@protocol GFYArrayConsumer <NSObject>

- (void)gfyArrayProvider:(id<GFYArrayProvider>)provider didUpdateArray:(NSArray *)media;
- (void)gfyArrayProvider:(id<GFYArrayProvider>)provider didFailWithError:(NSError *)error;

@end

@protocol GFYArrayProvider <NSObject>

@property (nonatomic, readonly) NSArray *array;
@property (nonatomic, readonly) BOOL hasMoreData;

- (void)loadMoreData;
- (BOOL)isLoadingMoreData;

- (void)refreshBlackList;

@end

@protocol GFYArraySource <NSObject>

- (id<GFYArrayProvider>)createProviderWithConsumer:(id<GFYArrayConsumer>)consumer blackListCache:(id<GfycatBlackListCache>)blackListCache;

@property (nonatomic, readonly) NSString *localizedTitle;
@property (nonatomic, readonly) NSString *localizedErrorMessage;
@property (nonatomic, readonly) NSString *localizedEmptyMessage;

@property (nonatomic, readonly) GFYAnalyticsContext gfy_reportingContext;
@property (nonatomic, readonly, nullable) NSString *gfy_reportingKeyword;

@end

NS_ASSUME_NONNULL_END
