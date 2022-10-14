////////////////////////////////////////////////////////////////////////////////////////////
// Copyright 2014 by SafeNet, Inc., (collectively herein  "SafeNet"), Belcamp, Maryland
// All Rights Reserved
// The SafeNet software that accompanies this License (the "Software") is the property of
// SafeNet, or its licensors and is protected by various copyright laws and international
// treaties.
// While SafeNet continues to own the Software, you will have certain non-exclusive,
// non-transferable rights to use the Software, subject to your full compliance with the
// terms and conditions of this License.
// All rights not expressly granted by this License are reserved to SafeNet or
// its licensors.
// SafeNet grants no express or implied right under SafeNet or its licensors’ patents,
// copyrights, trademarks or other SafeNet or its licensors’ intellectual property rights.
// Any supplemental software code, documentation or supporting materials provided to you
// as part of support services provided by SafeNet for the Software (if any) shall be
// considered part of the Software and subject to the terms and conditions of this License.
// The copyright and all other rights to the Software shall remain with SafeNet or
// its licensors.
// For the purposes of this Agreement SafeNet, Inc. includes SafeNet, Inc and all of
// its subsidiaries.
//
// Any use of this software is subject to the limitations of warranty and liability
// contained in the end user license.
// SafeNet disclaims all other liability in connection with the use of this software,
// including all claims for  direct, indirect, special  or consequential regardless
// of the type or nature of the cause of action.
////////////////////////////////////////////////////////////////////////////////////////////

/**
 *  @File   :   MPLibST.h
 *  @Project:   MobilePASS SDK
 *
 *  @Description :
 *      This a declarations of the MobilePASS SDK API methods.
 */

#ifndef __MP_LIBST_H__
#define __MP_LIBST_H__

#import <Foundation/Foundation.h>
#import "MPLibSTConst.h"


@interface MPLibST : NSObject {
    
}

/**
 * Initializes the MPLib. Must be called before using the SDK.
 * @param [in]strAppId	- the String parameter, must contain between 4 to 64 characters.
 * @param [in]param 	- Reserved, must be set to 0
 *
 * @return  ERR_NONE on success or error code as defined below:
 *
 * @return ERR_INVALID_PARAMETER        -- Invalid input parameter
 * @return ERR_OP_FAILED                -- Unspecified error
 */
+(int)mp_libInit:(NSString*)strAppId andReservedParam:(int)reservedParam;

/**
 * Logs off all existing tokens,
 * and dereferences all tokens cache.
 */
+(void)mp_libFinal;

/**
 * Returns the currently selected SDK related String parameter using the MPSSDKPARAM input parameter.
 * If the field does not exist the function returns null.
 * @param [in]mpparam - the String parameter requested
 *
 * @return: a valid String value, or null if the field does not exist.
 */
+(NSString*)mp_getSDKParamStr:(MPSSDKPARAM)mpparam andErrParam:(int*)errCode;

/**
 * Returns the currently selected SDK related int parameter using the MPISDKPARAM input parameter.
 * If the field does not exist the function returns null.
 * @param [in]mpparam - the int parameter requested
 *
 * @return: a valid int value or -1 if the field does not exist.
 */
+(int)mp_getSDKParamInt:(MPISDKPARAM)mpparam;

/**
 * Returns the currently selected Token String parameter using the MPSPARAM input parameter.
 * If the field does not exist, the function returns null.
 * @param [in]mpparam - the String parameter requested
 *
 * @return: a valid String value, or null if the field does not exist.
 */
+(NSString*)mp_getTokenParamStr:(MPSPARAM)mpparam;

/**
 * Returns the currently selected Token int parameter according to the MPLib.MPIPARAM input parameter.
 * If the field does not exist the function returns null.
 * @param [in]mpparam - the int parameter requested
 *
 * @return: a valid int value or -1 if the field does not exist.
 */
+(int)mp_getTokenParamInt:(MPIPARAM)mpparam;

/**
 * Lists all existing tokens.
 * @param [out] tokenNames - must be a declared mutable array, not null. Upon return, contains a list of token names.
 *
 * @return ERR_NONE on success or error code as defined below:
 *
 * @return ERR_INVALID_PARAMETER   -- If count reference is nil or input parameter is invalid
 * @return ERR_LIB_NOT_INIT        -- Function failed because mp_libInit function was not called
 */
+(int)mp_listTokens:(NSMutableArray*)tokenNames;

/**
 * Selects a token.
 * @param [in]tokenName - the token name to be selected, typically retrieved via mp_listTokens
 *
 * @return ERR_NONE on success or error code as defined below:
 *
 * @return ERR_OP_FAILED            -- Unspecified error
 * @return ERR_LIB_NOT_INIT         -- Function failed because mp_libInit function was not called
 * @return ERR_INVALID_PARAMETER	-- If count reference is nil or input parameter is invalid
 * @return ERR_TOKEN_DOES_NOT_EXIST	-- Function failed because a target token does not exist
 */
+(int)mp_selectToken:(NSString*)tokenName;

/**
 * Creates a new empty token (with no seed). Token state is installed, and the token will become the currently selected token.
 * @param [in]tokenName - the new token name to be created
 *
 * @return ERR_NONE on success or error code as defined below:
 *
 * @return ERR_OP_FAILED            -- Unspecified error
 * @return ERR_LIB_NOT_INIT         -- Function failed because mp_libInit function was not called
 * @return ERR_INVALID_PARAMETER	-- If count reference is nil or input parameter is invalid
 * @return ERR_TOKEN_DOES_NOT_EXIST	-- Function failed because a target token does not exist
 */
+(int)mp_createToken:(NSString*)tokenName;

/**
 * Deletes the currently selected token.
 *
 * @return ERR_NONE on success or error code as defined below:
 *
 * @return ERR_OP_FAILED            -- Unspecified error
 * @return ERR_LIB_NOT_INIT         -- Function failed because mp_libInit function was not called
 * @return ERR_NO_TOKEN_SELECTED	-- Operation requires that a token be selected
 * @return ERR_NEED_PIN_VERIFICATION-- Function failed because the PIN was not yet verified
 */
+(int)mp_deleteToken;

/**
 * Deletes all tokens.
 *
 * @return MP_ERR_NONE on success or error code as defined follows.
 *
 * Following are the errorneous cases:
 *
 *  - ERR_LIB_NOT_INIT              -- If library is not initialized
 *  - ERR_OP_FAILED                 -- Unspecified error
 *  - ERR_DATA_CLEANING_PARTIAL        -- Removal of some entries failed
 */
+ (int) mp_deleteAllTokens;

/**
 * Erases the token seed and policy. The token returns to its installed state.
 *
 * @return ERR_NONE on success or error code as defined below:
 *
 * @return ERR_OP_FAILED            -- Unspecified error
 * @return ERR_LIB_NOT_INIT         -- Function failed because mp_libInit function was not called
 * @return ERR_NO_TOKEN_SELECTED	-- Operation requires that a token be selected
 * @return ERR_NEED_PIN_VERIFICATION-- Function failed because the PIN was not yet verified
 */
+(int)mp_eraseToken;

/**
 * Verifies the input PIN using the currently selected token's secured data.
 * @param [in]strPIN - The PIN to be validated
 *
 * @return ERR_NONE on success or error code as defined below:
 *
 * @return ERR_OP_FAILED            -- Unspecified error
 * @return ERR_LIB_NOT_INIT         -- Function failed because mp_libInit function was not called
 * @return ERR_NO_TOKEN_SELECTED	-- Operation requires that a token be selected
 * @return ERR_TOKEN_IS_EMPTY 		-- Operation requires a non-empty token (seed in place)
 * @return ERR_PIN_VERIFY_FAILED 	-- PIN entered is incorrect
 * @return ERR_PIN_VERIFY_FAILED_TOKEN_ERSAED -- Token was erased due to PIN verification counter exceeding max error counter
 */
+(int)mp_verifyPin:(NSString*)strPIN;

/**
 * Changes the currently selected token's PIN
 * @param [in]currentPIN - The current PIN
 * @param [in]newPIN - The new PIN
 *
 * @return ERR_NONE on success or error code as defined below:
 *
 * @return ERR_OP_FAILED            -- Unspecified error
 * @return ERR_LIB_NOT_INIT         -- Function failed because mp_libInit function was not called
 * @return ERR_NO_TOKEN_SELECTED	-- Operation requires that a token be selected
 * @return ERR_TOKEN_IS_EMPTY 		-- Operation requires a non-empty token (seed in place)
 * @return ERR_PIN_VERIFY_FAILED 	-- PIN entered is incorrect
 * @return ERR_PIN_DOES_NOT_MEET_REQUIREMENTS -- PIN does not meet requirements
 * @return ERR_PIN_VERIFY_FAILED_TOKEN_ERSAED -- Token was erased due to PIN verification counter exceeding max error counter
 */
+(int)mp_changePin:(NSString*)currentPIN newPin:(NSString*)newPIN;

/**
 * Currently selected token's logoff operation - i.e. delete the token's cached PIN
 *
 * @return ERR_NONE on success or error code as defined below:
 *
 * @return ERR_OP_FAILED            -- Unspecified error
 * @return ERR_LIB_NOT_INIT         -- Function failed because mp_libInit function was not called
 * @return ERR_NO_TOKEN_SELECTED	-- Operation requires that a token be selected
 */
+(int)mp_logout;

/**
 * Generates an activation code using the policy string input. 
 * The selected token state changes from TOKEN_STATE_INSTALLED to TOKEN_STATE_IN_PROCESS.
 * @param [in]policyStr - The token policy string
 * @param [out]mppActCode - Contains one MPParamStr instance that holds the activation code
 *
 * @return ERR_NONE on success or error code as defined below.
 *
 * @return ERR_OP_FAILED            -- Unspecified error
 * @return ERR_LIB_NOT_INIT         -- Function failed because mp_libInit function was not called
 * @return ERR_NO_TOKEN_SELECTED	-- Operation requires that a token be selected
 * @return ERR_TOKEN_IS_EMPTY 		-- Operation requires a non-empty token (seed in place)
 * @return ERR_PIN_VERIFY_FAILED 	-- PIN entered is incorrect
 * @return ERR_PIN_DOES_NOT_MEET_REQUIREMENTS -- PIN does not meet requirements
 * @return ERR_PIN_VERIFY_FAILED_TOKEN_ERSAED --Token was erased due to PIN verification counter exceeding max error counter
 */
+(int)mp_generateActivationCode:(NSString*)strTokenPolicy andActCode:(NSMutableString*)strActCode;

/**
 * Performs auto enrollment using the enrollParams input - which typically is gotten as a base 64 string from a URL association or clipboard.
 * Selected/Created token state changes from TOKEN_STATE_INSTALLED to TOKEN_STATE_IN_PROCESS.
 * @param [in]enrollParams - Must contains the following fields:
 * @param					MP_KEY_TOKEN_NAME - if the token name is not already created, it will be created.
 * @param					Note that mp_performAutoEnrollment selects a token according to the MP_KEY_TOKEN_NAME parameter.
 * @param					MP_KEY_PORTAL_URL - Server URL
 * @param                   MP_KEY_USERNAME - User ID
 * @param					MP_KEY_PASSWORD - Enrollment session password, typically received via the base 64 string or SMS.
 * @param                   MP_KEY_SOFTPIN - Depending on the server definition, an OTP PIN (server side PIN) may be required.
 * If an OTP PIN is required, the first mp_performAutoEnrollment call returns ERR_AUTO_ENROLL_SOFTPIN_NEEDED.
 * In this case, the App should prompt the user to enter an OTP PIN.
 * This OTP PIN must be appended to enrollParams, and the application must call mp_performAutoEnrollment again.
 *
 * @return ERR_NONE on success or error code as defined below:
 *
 * @return ERR_OP_FAILED            		-- Unspecified error
 * @return ERR_LIB_NOT_INIT         		-- Function failed because mp_libInit function was not called
 * @return ERR_TOKEN_NOT_EMPTY				-- Operation requires an empty token (i.e. without seed)
 * @return ERR_NO_ENROLL_PARAM_FOUND		-- One or more of the enrollment input fields is missing
 * @return ERR_AUTO_ENROLL_OP_FAILED 		-- Enrollment unspecified error
 * @return ERR_AUTO_ENROLL_COM_ERROR 		-- Enrollment communication error
 * @return ERR_AUTO_ENROLL_SERVER_NOT_INIT 	-- Enrollment server error
 * @return ERR_AUTO_ENROLL_SESSION_EXPIRED 	-- Enrollment server timeout error
 * @return ERR_AUTO_ENROLL_SESSION_ABORTED 	-- Enrollment server abort
 * @return ERR_AUTO_ENROLL_SOFTPIN_NEEDED 	-- Enrollment requires OTP PIN
 * @return ERR_AUTO_ENROLL_SOFT_PIN_INVALID	-- Enrollment OTP PIN is invalid
 */
+(int)mp_performAutoEnrollment:(NSDictionary*) pAutoEnrollDict;

/**
 * Parse the base 64 string, gotten via mp_getBase64EnrollString, into enrollment parameters fields.
 * Note that selecting a token prior to this call is not required.
 * @param [in]strEnrollmentBase64Str - the base-64 string input
 * @param [in]strSoftPin - the OTP PIN if required
 * @param [out]pAutoEnrollDictionary - must be a declared dictionary, not null.
 *                                     Upon return, contains parameters required for enrollment.
 *
 * @return ERR_NONE on success or error code as defined below:
 *
 * @return ERR_OP_FAILED            -- Unspecified error
 * @return ERR_LIB_NOT_INIT         -- Function failed because mp_libInit function was not called
 * @return ERR_INVALID_PARAMETER	-- If count reference is nil or input parameter is invalid
 * @return ERR_NO_ENROLL_PARAM_FOUND-- One or more of the enrollment input fields is missing
 */
+(int) mp_enrollParamsFromBase64Str:(NSString*)strEnrollmentBase64Str andSoftPinStr:(NSString*)strSoftPin andAutoEnrollmentArgs:(NSDictionary**)pAutoEnrollDictionary;

/**
 * Sets the currently selected token PIN to protect the token and stores the token seed to the persistent token data.
 * This step is done post auto enrollment or activation code generation.
 * The function changes the token state from TOKEN_STATE_IN_PROCESS to TOKEN_STATE_READY.
 * @parame [in]strPin - The Token PIN to set
 *
 * @return ERR_NONE on success or error code as defined follows.
 *
 * @return ERR_OP_FAILED            -- Unspecified error
 * @return ERR_LIB_NOT_INIT         -- Function failed because mp_libInit function was not called
 * @return ERR_INVALID_PARAMETER	-- If count reference is nil or input parameter is invalid
 * @return ERR_TOKEN_NOT_EMPTY   	-- Operation requires an empty token (i.e. without seed)
 * @return ERR_NO_TOKEN_SELECTED	-- Operation requires that a token be selected
 * @return ERR_PIN_DOES_NOT_MEET_REQUIREMENTS -- PIN does not meet requirements
 */
+(int)mp_tokenSetPin:(NSString*)strPin;

/**
 * Renames the currently selected token.
 * The selected token must be in a token ready state, and if the token is PIN protected
 * the PIN must be validated beforehand.
 * @parame [in]newTokenName - String input
 * 
 * @return ERR_NONE on success or error code as defined below:
 *
 * @return ERR_OP_FAILED            -- Unspecified error
 * @return ERR_LIB_NOT_INIT         -- Function failed because mp_libInit function was not called
 * @return ERR_INVALID_PARAMETER	-- If count reference is nil or input parameter is invalid
 * @return ERR_NO_TOKEN_SELECTED	-- Operation requires that a token be selected
 * @return ERR_TOKEN_IS_EMPTY 		-- Operation requires a non-empty token (seed in place)
 * @return ERR_PIN_VERIFY_FAILED 	-- PIN entered is incorrect
 */
+(int)mp_renameToken:(NSString*)newTokenName;

/**
 * This method is used to generate an OTP.
 * The generated OTP is returned via the out String parameter.
 * Challenge should be null – unless using a CR token.
 * If the token has a PIN, the token PIN must be validated beforehand.
 * @param [in]challenge - String input; should be null if not a CR token
 * @param [out]otpOut - NSMutableString that holds the OTP output
 *
 * @return ERR_NONE on success or error code as defined below:
 *
 * @return ERR_OP_FAILED            -- Unspecified error
 * @return ERR_LIB_NOT_INIT         -- Function failed because mp_libInit function was not called
 * @return ERR_INVALID_PARAMETER	-- If count reference is nil or input parameter is invalid
 * @return ERR_NO_TOKEN_SELECTED	-- Operation requires that a token be selected
 * @return ERR_TOKEN_IS_EMPTY 		-- Operation requires a non-empty token (seed in place)
 * @return ERR_PIN_VERIFY_FAILED 	-- PIN entered is incorrect
 */
+(int)mp_genOTP:(NSString*)challenge andHostNum:(int)nHost andOtp:(NSMutableString*)strOtps;

/**
 * Validates the new Pin for currently selected token.
 * @param [in] pinType              -- pin type
 * @param [in] sPinToValidate       -- token pin to validate against complexity and length
 
 * @return ERR_NONE on success or error code as defined below:
 *
 * @return ERR_OP_FAILED            -- Unspecified error
 * @return ERR_LIB_NOT_INIT         -- Function failed because mp_libInit function was not called
 * @return ERR_INVALID_PARAMETER	-- Invalid input parameter
 * @return ERR_NO_TOKEN_SELECTED	-- Operation requires that a token be selected
 * @return ERR_PIN_VERIFY_FAILED 	-- PIN entered is incorrect
 * @return ERR_PIN_DOES_NOT_MEET_REQUIREMENTS -- PIN does not meet requirements
 */
+(int)mp_validateTokenPin:(MPPINTYPE)pinType andPinToValidate:(NSString*)sPinToValidate;


@end
#endif  //__MP_LIBST_H__