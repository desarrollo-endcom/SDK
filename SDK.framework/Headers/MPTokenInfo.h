/*   \dontinclude MPEngine.h
/************************************************************************
 * Copyright (c) 2011  SafeNet, Inc. All rights reserved.
 *
 * This software contains proprietary information, which shall not
 * be reproduced or transferred to other documents and shall not
 * be disclosed to others or used for manufacturing or any other
 * purpose without prior written permission of SafeNet, Inc.
 ************************************************************************/

/*
 *  @File   :   MPTokenInfo.h
 *  @Project:   MobilePASS SDK
 *
 *  @Description :
 *      Interface to retrieve Token Information
 */

#ifndef __MP_TOKENINFO_H__
#define __MP_TOKENINFO_H__

#import <Foundation/Foundation.h>

@interface MPTokenInfo : NSObject 
{
@private
    NSString*           mTknNameStr;
    NSString*           mSerialNumStr;
    NSString*           mTokenModeStr;
    NSString*           mPolicyStr;
    NSString*           mSdkVersionStr;

    int                 mState;
    int                 mCapLevel;
    int                 mChallengeLen;
    int                 mPinLen;
    int                 mTickCount;
    
    BOOL                isPinEnabled;
    BOOL                isMpInWait;

    int                 mMaxAttacks;
    unsigned long       mFailedAttempts;
    unsigned long       mWaitingTime;
}


#pragma mark ---------------- Methods ----------------
- (id) init;
- (void) initialized:(id) pDataObj;

/* Returns Token Name 
 *  - Token name can never be nil
 */
- (NSString*) MP_GetTokenName;

/* Returns Token Policy 
 *  - Nil if policy has not been set, or appropriate value as per policy
 */
- (NSString*) MP_GetTokenPolicy;

/* Returns Token Policy Level 
 *  - Nil if policy has not been set, or appropriate value i.e. “Level 1” or “Level 2” as per policy
 */
- (NSString*) MP_GetTokenPolicyLevel;

/* Returns Token Policy Level ID
 *  - (-1) if policy has not been set, or appropriate value i.e. “1” or “2” as per policy
 */
- (int) MP_GetTokenPolicyLevelID;

/* Returns Token Mode 
 *  - Nil if policy has not been set, or appropriate value as per policy
 */
- (NSString*) MP_GetTokenMode;

/* Returns Token Serial Number of the token that gets assigned after the auto-enrollment operation is completed.
 *  - Non-nil value when Auto-enrollment is completed, else nil
 */
- (NSString*) MP_GetTokenSerialNo;

/* Return Max number of Attacks after which the token will reset.
 *  - (-1) if policy not set, else appropriate value as per policy.
 */
- (int) MP_GetMaxAttacks;

/* Return Challenge Length 
 *  - (-1) if policy not set, else appropriate value as per policy.
 */
- (int) MP_GetChallengeLength;

/* Return PIN Length 
 *  - (-1) if policy not set, else appropriate value as per policy. Returns 0, for No-Pin policy
 */
- (int) MP_GetPinLength;

/* Return Tick Counts  
 *  - (-1) if policy not set or for ES/CR based tokens, else appropriate value as per policy.
 */
- (int) MP_GetTickCount;

/* Return Failled Attempts 
 *  - (>=0) number of failed Attempts
 */
- (unsigned long) MP_GetAttackCount;

/* Return Waiting Time, if MP is in wait state 
 *  - 0 or Time remaining for the token to get unlocked.
 */
- (unsigned long) MP_GetWaitTime;

/* To find out whether token is in wait state or not 
 *  - Returns YES / NO
 */
- (BOOL) MP_IsTokenInWait;

/* Checks whether PIN is enabled or not 
 *  - Returns YES / NO
 */
- (BOOL) MP_IsPinEnabled;

/* Returns current token state
 *  - Returns 1 (INSTALLED_STATE) / 2 (PRE_INIT_STATE) / 3 (READY_STATE)
 */
- (int) MP_GetTokenState;


/* Returns SDK version 
 *  - Non-nil value, having format MajorVersion.MinorVersion.PatchNumber.BuildNumber.
 */
- (NSString*) MP_GetSdkVersion;

@end

#endif //__MP_TOKENINFO_H__
