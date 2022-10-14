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
 *  @File   :   MPEngine.h
 *  @Project:   MobilePASS SDK
 *
 *  @Description :
 *      This provides an interface to all MobilePASS SDK APIs.
 */

#ifndef __MP_ENGINE_H__
#define __MP_ENGINE_H__

#import <Foundation/Foundation.h>
#import "MPTokenInfo.h"
#import "PinComplexityValidator.h"


/* Singleton Class */
@interface MPEngine : NSObject 
{

}

/* MobilePASS SDK APIs Declaration */

#ifdef __MULTI_HOST__
#include "MPEngine_MH.h"
#endif //__MULTI_HOST__

#ifdef __NON_MULTI_HOST__
#include "MPEngine_NON_MH.h"
#endif // __NON_MULTI_HOST__

#pragma mark -
#pragma mark ------------------- Exposed API << MP_Initialize >> - Class Method -------------------
/**
 * This API initializes MobilePASS SDK library with Application Identifier, provided by SDK user. 
 *
 * NOTE : This should be the first call made by an application.
 * 
 * @Param   IN  strAppId     Application Identifier         // Length is in (4 - 64 chars) range. Valid char set consists of a-z, A-Z, 0-9, 
 *                                                          // Space, !, @, #, $, %, ^, &, (, ), -, _, {, }, [, ], :, ?, /, ~, `, Dot. 
 *                                                          // Comma is invalid. Spaces are allowed but should not contain only space. 
 * @param   IN  pvInfo      RFU (Placeholder for future use)// Should be nil.
 *
 * @return  MP_ERR_NONE on success or error code as defined follows.
 *
 * Following are the errorneous cases:
 *
 *  - MP_ERR_INVALID_PARAM              -- If Applcation ID is invalid (nil/ not matching complexity criteria)
 *                                      -- Or if payload is not nil
 *  - MP_ERR_LIB_INITIALIZATION_FAILED  -- Library initialization failed
 *  - MP_ERR_LIB_ALREADY_INITIALIZED    -- If library is already inited
 */
+ (unsigned long) MP_Initialize:(NSString*) strAppId andPayload:(void*) pvInfo;

#pragma mark -
#pragma mark ------------------- Exposed API << MP_Finalize >> - Class Method -------------------
/**
 * This API indicates that application is finished with MobilePASS SDK library. It releases any references and allocated memory. 
 * This API can be called anytime, once the engine is initialized.
 *
 * NOTE : This should be the last call made by an application. Call to this immediately abort the access to SDK APIs.
 * 
 * @param   NONE
 *
 * @return  MP_ERR_NONE on success or error code as defined follows.
 *
 * Following are the errorneous cases:
 *  - MP_ERR_LIB_NOT_INITIALIZED        -- If library is NOT initialized as yet
 */
+ (unsigned long) MP_Finalize;


#pragma mark -
#pragma mark ------------------- Exposed API << MP_CreateInstance >> - Singleton Class -------------------
/**
 * Creates Engine instance. It is Singleton Class, so fresh instance is being created only when it is not created as yet. 
 *
 * If token data file is NOT found the engine goes into installed state. 
 * If token data file is found the engine loads data from token data file and goes into state as stored in token data file.
 *
 * If engine is already created with the requested (input parameter) token name, then it returns the same previous instance else 
 * return nil.
 * 
 * @param   IN      strTokenName        Token Name          // Length is in (4 - 64 chars) range. Valid char set consists of a-z, A-Z, 0-9. 
 *                                                          // Space, !, @, #, $, %, ^, &, (, ), -, _, {, }, [, ], :, ?, /, ~, `, Dot. 
 *                                                          // Comma is invalid. Spaces are allowed but should not contain only space.  
 * @param   IN/OUT  mEngInst            Engine Instance 
 *
 * @return  MP_ERR_NONE on success or error code as defined follows.
 *
 * Following are the errorneous cases:
 *
 *  - MP_ERR_INVALID_PARAM              -- If token name is nil/invalid (not as per matching criteria) or Engine reference is nil
 *  - MP_ERR_LIB_NOT_INITIALIZED        -- If library is not initialized
 *  - MP_ERR_TOKEN_ALREADY_ASSOCIATED   -- If requested token is already associated with Engine. Existing token reference is returned.
 *  - MP_ERR_ANOTHER_TOKEN_ASSOCIATED   -- If engine is associated with token other than requested one. Nil token reference is returned.
 *  - MP_ERR_OPERATION_FAILED           -- Some internal error happened
 */
+ (unsigned long) MP_CreateInstance:(NSString*) strTokenName andEngine:(MPEngine**) mEngInst;


#pragma mark -
#pragma mark ------------------- Exposed API << MP_ReleaseInstance >> - Instance Method -------------------
/**
 * This API is used to release the instance of the token. 
 * This can be called anytime, once the engine is initialized.
 * 
 * @param   NONE    
 *
 * @return  MP_ERR_NONE on success or error code as defined follows.
 *
 * Following are the errorneous cases:
 *
 *  - MP_ERR_LIB_NOT_INITIALIZED        -- If library is not initialized
 *  - MP_ERR_TOKEN_NOT_AVAILABLE        -- If token not available (either not created or already released)
 *  - MP_ERR_OPERATION_FAILED           -- Some internal error happened
 */
- (unsigned long) MP_ReleaseInstance;


#pragma mark -
#pragma mark ------------------- Exposed API << MP_SetPin >> - Instance Method -------------------
/**
 * Initializes User's PIN for MobilePASS Token
 *
 * This operation can be called only when activation code has been generated and PIN is not set as yet.
 * 
 * @param       IN          strNewPIN           // User PIN to set
 *                                              // Length is in (4 - 64 chars) range and Shouldn't contain any other character
 *                                              // other than 'A' to 'Z' / 'a' to 'z' / '0' to '9'
 * @return  MP_ERR_NONE on success or error code as defined follows.
 *
 * Following are the errorneous cases
 *
 *  - MP_ERR_LIB_NOT_INITIALIZED        -- If library is not initialized
 *  - MP_ERR_TOKEN_NOT_AVAILABLE        -- If token not available (either not created or already released)
 *  - MP_ERR_TOKEN_NOT_ACTIVATED        -- When token is not Activated, (Activation code is not generated as yet)
 *  - MP_ERR_TOKEN_PIN_ALREADY_SET      -- When token PIN is already set
 *  - MP_ERR_PIN_NOT_REQUIRED           -- API is called for NO PIN Policy
 *  - MP_ERR_INVALID_PARAM              -- If nil PIN / PIN not meeting complexity criteria / PIN len not as per configured Policy 
 *  - MP_ERR_OPERATION_FAILED           -- Some internal error happened
 */
- (unsigned long) MP_SetPin:(NSString*) strNewPIN;
- (unsigned long) MP_SetPin:(NSString*) strNewPIN complexityType:(id<PinComplexity>)pinComplexity;

#pragma mark -
#pragma mark ------------------- Exposed API << MP_GenerateOTP >> - Instance Method -------------------
/**
 * Generates the passcode. Generated OTP is returned via the out parameter. 
 *  - For ES mode - strChall and iHostNum parameters would be ignored
 *  - For TS mode - strChall and iHostNum parameters would be ignored
 *  - For CR mode - iHostNum parameters would be ignored
 *
 * This operation can be performed only once the token activation is completed with user PIN or once the auto enrollment
 * operation is completed and PIN is set based on policy requirements.
 * This API can be called again and again. 
 * 
 * @param       IN              strChall        // Challenge String. Only Numeric challenge is supported.
 * @param       IN              iHostNum        // Unused parameter 
 * @param       OUT             strOtp          // Generated OTP will be set in this parameter
 * 
 * @return  MP_ERR_NONE on success or error code as defined follows.
 *
 * Following are the errorneous cases
 *
 *  - MP_ERR_LIB_NOT_INITIALIZED        -- If library is not initialized
 *  - MP_ERR_TOKEN_NOT_AVAILABLE        -- If token not available (either not created or already released)
 *  - MP_ERR_PIN_NOT_SET                -- When PIN has not been set as yet
 *  - MP_ERR_ENGINE_DISABLED            -- When MP is under attack
 *  - MP_ERR_VALIDATION_REQUIRED        -- If token is in Ready state but user is not logged in 
 *  - MP_ERR_PIN_CHANGE_REQUIRED        -- Pin change is enforced by policy.
 *  - MP_ERR_INVALID_PARAM              -- Some parameter provided is nil or invalid. 
 *  - MP_ERR_OPERATION_FAILED           -- Some internal error happened
 */
- (unsigned long) MP_GenerateOTP:(NSString*) strChall andHostNum:(int) nHost andOtp:(NSMutableString*) strOtp;


#pragma mark -
#pragma mark ------------------- Exposed API << MP_ValidatePin >> - Instance Method -------------------
/**
 * Validates User PIN of MobilePASS Token. 
 *
 * This API can be called once the PIN has been set.
 * This API can be called again and again. 
 *
 * If USER PIN is not validated, then user is logged out.
 *
 * @param       IN          strUserPIN          // user PIN to set
 *                                              // Length is in (4 - 64 chars) range and Shouldn't contain any other character
 *                                              // other than 'A' to 'Z' / 'a' to 'z' / '0' to '9'
 * @return  MP_ERR_NONE on success or error code as defined follows.
 *
 * Following are the errorneous cases
 *
 *  - MP_ERR_LIB_NOT_INITIALIZED        -- If library is not initialized
 *  - MP_ERR_TOKEN_NOT_AVAILABLE        -- If token not available (either not created or already released)
 *  - MP_ERR_PIN_NOT_SET                -- When PIN has not been set as yet
 *  - MP_ERR_PIN_NOT_REQUIRED           -- Operation is invalid for No PIN policy
 *  - MP_ERR_ENGINE_DISABLED            -- When MP is under attack
 *  - MP_ERR_ENGINE_RESET               -- Token Resets if max attacks reach 
 *  - MP_ERR_VERIFY_FAIL                -- When PIN entered is invalid (nil / having special chars / len not as per policy)
 *  - MP_ERR_OPERATION_FAILED           -- Some internal error happened
 */
- (unsigned long) MP_ValidatePin:(NSString*) strUserPIN;
- (unsigned long) MP_ValidatePin:(NSString*) strUserPIN complexityType:(id<PinComplexity>) pinComplexity;
- (bool) MP_isTrivialPinAllowed;
- (int) MP_isNumericKB;

#pragma mark -
#pragma mark ------------------- Exposed API << MP_ChangePin >> - Instance Method -------------------
/**
 * Changes User Pin of MobilePASS Token 
 * 
 * This API can be called once the PIN has been set.
 * This API can be called again and again. 
 * 
 * If USER PIN is not validated, then user is logged out. Else current PIN is changed with the new PIN.
 *  
 * @param       IN          strCurrPIN          // Current User PIN
 *                                              // Length is in (4 - 64 chars) range and Shouldn't contain any other character
 *                                              // other than 'A' to 'Z' / 'a' to 'z' / '0' to '9'
 * @param       IN          strNewPIN           // New User PIN
 *                                              // Length is in (4 - 64 chars) range and Shouldn't contain any other character
 *                                              // other than 'A' to 'Z' / 'a' to 'z' / '0' to '9'
 * @return  MP_ERR_NONE on success or error code as defined follows.
 *
 * Following are the errorneous cases
 *
 *  - MP_ERR_LIB_NOT_INITIALIZED        -- If library is not initialized
 *  - MP_ERR_TOKEN_NOT_AVAILABLE        -- If token not available (either not created or already released)
 *  - MP_ERR_PIN_NOT_SET                -- When PIN has not been set as yet
 *  - MP_ERR_PIN_NOT_REQUIRED           -- Operation is invalid for No PIN policy
 *  - MP_ERR_ENGINE_DISABLED            -- When MP is under attack
 *  - MP_ERR_VERIFY_FAIL                -- When current PIN entered is invalid (nil / having special chars / len not as per policy)
 *  - MP_ERR_ENGINE_RESET              -- Token Resets if max attacks reach 
 *  - MP_ERR_INVALID_PARAM              -- New pin provided is invalid (nil / having special chars / len not as per policy / new pin same as current pin)
 *  - MP_ERR_OPERATION_FAILED           -- Some internal error happened
 */
- (unsigned long) MP_ChangePin:(NSString*) strCurrPIN andNewPIN:(NSString*) strNewPIN;
- (unsigned long) MP_ChangePin:(NSString*) strCurrPIN andNewPIN:(NSString*) strNewPIN complexityType:(id<PinComplexity>) pinComplexity;


#pragma mark -
#pragma mark ------------------- Exposed API << MP_ChangeTokenName >> - Instance Method -------------------
/**
 * Changes Token Name of MobilePASS Token
 *
 * This operation can be called once the activation process is completed and user PIN is set
 * This API can be called again and again
 *  
 * @param       IN              strNewTokenName             // New token name 
 *                                                          // Length is in (4 - 64 chars) range. Valid char set consists of a-z, A-Z, 0-9. 
 *                                                          // Space, !, @, #, $, %, ^, &, (, ), -, _, {, }, [, ], :, ?, /, ~, `, Dot. 
 *                                                          // Comma is invalid. Spaces are allowed but should not contain only space.  
 *
 * @return  MP_ERR_NONE on success or error code as defined follows.
 *
 * Following are the errorneous cases
 *
 *  - MP_ERR_LIB_NOT_INITIALIZED        -- If library is not initialized
 *  - MP_ERR_TOKEN_NOT_AVAILABLE        -- If token not available (either not created or already released)
 *  - MP_ERR_PIN_NOT_SET                -- When PIN has not been set as yet
 *  - MP_ERR_VALIDATION_REQUIRED        -- If token is in Ready state but user is not logged in 
 *  - MP_ERR_ENGINE_DISABLED            -- When MP is under attack
 *  - MP_ERR_INVALID_PARAM              -- New token name provided is invalid (nil / not meeting complexity criteria 
 *  - MP_ERR_DUPLICATE_TOKEN_NAME       -- New token name is same as token name of another token or same as current name of the token. 
 *  - MP_ERR_OPERATION_FAILED           -- Some internal error happened
 */
- (unsigned long) MP_ChangeTokenName:(NSString*)strNewTokenName;


#pragma mark -
#pragma mark ------------------- Exposed API << MP_GetTokenInfo >> - Instance Method -------------------
/**
 * This API is used to retrieve the information 
 *
 * This API can be called once the engine instance has been created.
 * This API can be called again and again. 
 * 
 * @param       IN/OUT          mpTknInfo           // Buffer allocated by application, This API filled token information in buffer
 * 
 * @return  MP_ERR_NONE on success or error code as defined follows.
 *
 * Following are the errorneous cases
 *
 *  - MP_ERR_LIB_NOT_INITIALIZED        -- If library is not initialized
 *  - MP_ERR_TOKEN_NOT_AVAILABLE        -- If token not available (either not created or already released)
 *  - MP_ERR_INVALID_PARAM              -- If parameter is nil or invalid
 *  - MP_ERR_OPERATION_FAILED           -- Some internal error happened
 */
- (unsigned long) MP_GetTokenInfo:(MPTokenInfo*) mpTknInfo;


#pragma mark -
#pragma mark ------------------- Exposed API << MP_GetTokenList >> - Class Method -------------------
/**
 * This API is used to obtain a list of token information associated with the application.
 *
 * This API does not allocate any space on its own, application will often call it twice. Application is responsible to allocate buffer.
 *
 * API behavior is governed by API parameters.
 *
 * (1) If pTknList parameter is NIL, then function returns information about the tokens associated with the application. 
 *     In this case no token info will be returned, only the count will be returned. 
 *
 *
 * (2) If pTknList parameter is non-nil, then count parameter must contain the size (#token) of the buffer pointed to by pTknList.
 *     -- If that buffer is large enough to hold the list of token info, then the list is returned in it, and CKR_OK is returned. 
 *     -- If not, then function returns the value MP_ERR_BUFFER_TOO_SMALL. 
 *
 * @param       IN/OUT          pTknList             // Pointer to buffer holding information about tokens
 * @param       IN/OUT          count               // Pointer to integer, either used to get token numbers available or used to let the 
 *                                                  // API knows number of tokens for which calling function need token information
 * @return  MP_ERR_NONE on success or error code as defined follows.
 * When API called with allocated buffer, and none of the token is available, it returns MP_ERR_NONE alongwith 0 in out param
 *
 * Following are the errorneous cases
 *
 *  - MP_ERR_INVALID_PARAM              -- If count reference is nil or input parameter is invalid
 *  - MP_ERR_LIB_NOT_INITIALIZED        -- If library is not initialized
 *  - MP_ERR_BUFFER_TOO_SMALL           -- When buffer provided cannot accommodate all the tokens
 *  - MP_ERR_OPERATION_FAILED           -- Some internal error happened
 */
+ (unsigned long) MP_GetTokenList:(NSArray*) pTknList andCount:(unsigned int *) count andAppId:(NSString*)appId forLegacy82:(bool)isLegacy82;
+ (unsigned long) MP_GetTokenList:(NSArray*) pTknList andCount:(unsigned int *) count;

+ (unsigned long) MP_ConvertLegacyTokenListForAppId:(NSString*)appId fromAppId:(NSString*)legacyAppId;

#pragma mark -
#pragma mark ------------------- Exposed API << MP_ResetToken >> - Instance Method -------------------
/**
 * This API is used to reset the token. All the token data gets erased and the engine goes back to the un-activated state. 
 * 
 * This operation can be performed anytime till PIN is not set.
 * If PIN is set, then this operation can be performed only when PIN is validated
 * This operation can be called again and again
 * 
 * @param       NONE
 *  
 * @return  MP_ERR_NONE on success or error code as defined follows.
 *
 * Following are the errorneous cases
 *
 *  - MP_ERR_LIB_NOT_INITIALIZED        -- If library is not initialized
 *  - MP_ERR_TOKEN_NOT_AVAILABLE        -- If token not available (either not created or already released)
 *  - MP_ERR_ENGINE_DISABLED            -- When MP is under attack
 *  - MP_ERR_VALIDATION_REQUIRED        -- If token is in Ready state but user is not logged in 
 *  - MP_ERR_OPERATION_FAILED           -- Some internal error happened
 */
- (unsigned long) MP_ResetToken;


#pragma mark -
#pragma mark ------------------- Exposed API << MP_DeleteToken >> - Instance Method -------------------
/**
 * This API is used to delete the token. All the token data related to the token will be permanently removed from storage.
 * 
 * This operation can be performed anytime till PIN is not set.
 * If PIN is set, then this operation can be performed only when PIN is validated
 * This operation can be called again and again 
 *  
 * @param       NONE
 *  
 * @return  MP_ERR_NONE on success or error code as defined follows.
 *
 * Following are the errorneous cases
 *
 *  - MP_ERR_LIB_NOT_INITIALIZED        -- If library is not initialized
 *  - MP_ERR_TOKEN_NOT_AVAILABLE        -- If token not available (either not created or already released)
 *  - MP_ERR_ENGINE_DISABLED            -- When MP is under attack
 *  - MP_ERR_VALIDATION_REQUIRED        -- If token is in Ready state but user is not logged in 
 *  - MP_ERR_OPERATION_FAILED           -- Some internal error happened
 */
- (unsigned long) MP_DeleteToken;


#pragma mark -
#pragma mark ------------------- Exposed MultiToken API << MP_DeleteAllToken >> - Class Method -------------------
/**
 * Deleting all MobilePASS tokens associated with this application
 *  - Deletes all available tokens  
 * 
 * This API can be called only after the library is initialized.
 * 
 * @param       NONE
 * 
 * @return  MP_ERR_NONE on success or error code as defined follows.
 * 
 * Following are the errorneous cases
 * 
 *  - MP_ERR_LIB_NOT_INITIALIZED        -- If library is not initialized
 */
+ (unsigned long) MP_DeleteAllToken;
+ (unsigned long) MP_DeleteAllToken:(NSString *)appID;

- (BOOL) isPinVerificationSet;
- (BOOL) isPinCachingSet;

+ (BOOL) isPinValid:(NSString*) strPin complexityType:(id<PinComplexity>)pinComplexity;

@end

#endif //__MP_ENGINE_H__