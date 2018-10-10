/**
 * Card
 *
 * Created by Your Name
 * Copyright (c) 2018 Your Company. All rights reserved.
 */

#import "ACardModule.h"
#import "TiBase.h"
#import "TiHost.h"
#import "TiUtils.h"

@implementation ACardModule

#pragma mark Internal

// This is generated for your module, please do not change it
- (id)moduleGUID
{
  return @"730278f5-e194-4f7a-a3bb-a08b16229585";
}

// This is generated for your module, please do not change it
- (NSString *)moduleId
{
  return @"a.card";
}

#pragma mark Lifecycle

- (void)startup
{
  // This method is called when the module is first loaded
  // You *must* call the superclass
  [super startup];
//  DebugLog(@"[DEBUG] %@ loaded", self);
}

#pragma Public APIs

- (void)debugCard
{
    // debug method
    // Call with "Card.debugCard()"
    [[GJPGLXAPI sharedInstance] setIsDebugMode:YES];
    [[GJPGLXAPI sharedInstance] debugSetSendBatchWhenLocationReceived:YES];
}

- (void)startCardWithKey:(id)args
{
    // start method.
    // Call with "Card.startCardWithKey(args)"
    NSArray *argsArray = (NSArray *)args;
    NSString *apiKey = argsArray.lastObject;
    [[GJPGLXAPI sharedInstance] startWithApiKey:apiKey];
}

@end
