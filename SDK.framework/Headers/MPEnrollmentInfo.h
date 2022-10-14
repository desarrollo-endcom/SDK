/*   \dontinclude MPEngine.h
/************************************************************************
 * Copyright (c) 2013  SafeNet, Inc. All rights reserved.
 *
 * This software contains proprietary information, which shall not
 * be reproduced or transferred to other documents and shall not
 * be disclosed to others or used for manufacturing or any other
 * purpose without prior written permission of SafeNet, Inc.
 ************************************************************************/

/*
 *  @File   :   MPEnrollmentInfo.h
 *  @Project:   MobilePASS SDK
 *
 *  @Description :
 *      Interface to retrieve Enrollment Information
 */

#ifndef __MP_ENROLLMENTINFO_H__
#define __MP_ENROLLMENTINFO_H__

#import <Foundation/Foundation.h>

#define     MP_ENROLLMENT_URL         @"EnrollmentURL"
#define     MP_ENROLLMENT_USERID      @"UserID"
#define     MP_ENROLLMENT_PASSPHRASE  @"Passphrase"

@interface MPEnrollmentInfo : NSObject
{
@private
    NSString*           mUserIDStr;
    NSString*           mPassphraseStr;
    NSString*           mEnrollmentURL;
    NSDictionary*       mEnrollmentInfoDictionary;
}

#pragma mark ---------------- Methods ----------------
- (id) init;
- (NSString*) base64StringRelaxation:(NSString*)str;
- (void) initializedWithBase64String:(NSString *)base64String;
- (void) initializedWithBase64StringA:(NSString *)base64String;

/* Returns Enrollment User ID
 */
- (NSString*) MP_GetUserID;

/* Returns Enrollment Passphrase
 */
- (NSString*) MP_GetPassphrase;

/* Returns Enrollment URL
 */
- (NSString*) MP_GetEnrollmentURL;

/* Returns Enrollment Dictionary
 */
- (NSDictionary*) MP_GetEnrollmentDictionary;


//+ (NSString *) base64EncodeString: (NSString *) strData;
//+ (NSString *) base64EncodeData: (NSData *) objData;
//+ (NSData *) base64DecodeString: (NSString *) strBase64;

@end

#endif //__MP_ENROLLMENTINFO_H__
