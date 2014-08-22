//
//  SecurityMgr.h
//  BMDK
//
//  Created by Dan Melcher on 8/11/14.
//  Copyright (c) 2014 Actuate Corporation. All rights reserved.
//

#import "NSData-CommonCrypto.h"

@interface SecurityMgr : NSObject

- (NSString*) encryptIt: (NSString*)toHash withKey: (NSString*)key;
- (NSString*) createKey;

@end