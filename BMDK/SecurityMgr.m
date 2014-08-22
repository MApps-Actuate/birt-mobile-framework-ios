//
//  SecurityMgr.m
//  BMDK
//
//  Created by Dan Melcher on 8/11/14.
//  Copyright (c) 2014 Actuate Corporation. All rights reserved.
//

#import "SecurityMgr.h"
#import <Foundation/Foundation.h>
#import "NSData-CommonCrypto.h"
#import <sysexits.h>

@implementation SecurityMgr : NSObject

- (NSString*) createKey {
    CFUUIDRef uuidObj = CFUUIDCreate(nil); //create a new UUID
    NSString *uuidString = (__bridge NSString*)CFUUIDCreateString(nil, uuidObj);
    CFRelease(uuidObj);
    return uuidString;
}

- (NSString*) encryptIt: (NSString*)toHash withKey:(NSString*)uniqueKey {
	//NSString *password = @"mypassword";
	//NSString *str = @"hello world 123";
    
	// 1) Encrypt
	NSLog(@"encrypting string = %@",toHash);
    
	NSData *data = [toHash dataUsingEncoding: NSASCIIStringEncoding];
	//NSData *encryptedData = [data AESEncryptWithPassphrase:password];
	CCAlgorithm algo = kCCAlgorithmAES128;
	CCOptions opts = kCCOptionPKCS7Padding;
	id key = uniqueKey;
	CCCryptorStatus status = kCCSuccess;
    NSData * encryptedData = [data dataEncryptedUsingAlgorithm: algo
                                                    key: key
                                                options: opts
                                                  error: &status];
	if ( status != kCCSuccess )
	{
		NSError * err = [NSError errorWithCCCryptorStatus: status];
		errexit( "Cryptor failed: %s\n", [[err localizedDescription] UTF8String] );
	}

	// Encode Base 64
	NSString *b64EncStr = [[NSString alloc] initWithData:encryptedData encoding:NSUTF8StringEncoding];
    NSLog(@"Base 64 encoded = %@",b64EncStr);
    return b64EncStr;
}

static void errexit( const char * format, ... ) {
	va_list args;
	va_start( args, format );
	vfprintf( stderr, format, args );
	va_end( args );
	//[gAutoreleasePool drain];
	exit( EX_SOFTWARE );
}

@end