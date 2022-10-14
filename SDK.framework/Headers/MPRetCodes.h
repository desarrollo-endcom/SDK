/************************************************************************
 * Copyright (c) 2011  SafeNet, Inc. All rights reserved.
 *
 * This software contains proprietary information, which shall not
 * be reproduced or transferred to other documents and shall not
 * be disclosed to others or used for manufacturing or any other
 * purpose without prior written permission of SafeNet, Inc.
 ************************************************************************/

/*
 *  @File   :   MPRetCodes.h
 *  @Project:   MobilePASS SDK
 *
 *  @Description :
 *      Define return codes, used by MobilePASS SDK
 */

#ifndef __MP_RETCODES_H__
#define __MP_RETCODES_H__


#pragma mark ----------------------- MobilePASS SDK Return Codes -------------------------------


/* Operation is successfully executed */
#define     MP_ERR_NONE                             0


#pragma mark -------- Generic error range : 6001 - 6499 (parameters and programmatic errors) -------

/* Buffer provided to retrieve token list is too small */
#define     MP_ERR_BUFFER_TOO_SMALL                 6001

/* Any of the API param is invalid */
#define     MP_ERR_INVALID_PARAM                    6002

/* SDK API is failed */
#define     MP_ERR_OPERATION_FAILED                 6003
#pragma mark -


#pragma mark -------- Library initialization errors: 6500 - 6999 --------

/* MobilePASS SDK Library is already initialized */
#define     MP_ERR_LIB_ALREADY_INITIALIZED			6500

/* MobilePASS SDK Library initialization failed */
#define     MP_ERR_LIB_INITIALIZATION_FAILED        6501

/* MobilePASS SDK Library is not initialized as yet */
#define     MP_ERR_LIB_NOT_INITIALIZED              6502
#pragma mark -


#pragma mark -------- Engine and token related errors: 7000 - 7499 --------

/* Another MobilePASS token is already active */
#define     MP_ERR_ANOTHER_TOKEN_ASSOCIATED         7000

/* New token name is already associated with some existing token */
#define     MP_ERR_DUPLICATE_TOKEN_NAME             7001

/* Engine is disabled due to wrong pin attacks. Ready state operations can not be executed at this moment */
#define     MP_ERR_ENGINE_DISABLED                  7002

/* Token gets reset as encountered maximum wrong PIN attempts */
#define     MP_ERR_ENGINE_RESET                     7003

/* MobilePASS token has already been activated by generating an activation code */
#define     MP_ERR_TOKEN_ALREADY_ACTIVATED          7004

/* Requested token is already active */
#define     MP_ERR_TOKEN_ALREADY_ASSOCIATED         7005

/* Activation code is not generated as yet */
#define     MP_ERR_TOKEN_NOT_ACTIVATED              7006

/* Token is not available for any operation. Either not created as yet or already released */
#define     MP_ERR_TOKEN_NOT_AVAILABLE              7007 

/* Token is already activated with PIN */
#define     MP_ERR_TOKEN_PIN_ALREADY_SET            7008

#pragma mark -


#pragma mark -------- PIN and SoftPIN related errors: 7500 - 7999 --------

/* User PIN needs to be changed before performing any Ready-state operation. OTP can not be generated at this moment */
#define     MP_ERR_PIN_CHANGE_REQUIRED              7500

/* User PIN is not needed, as per assigned policy */
#define     MP_ERR_PIN_NOT_REQUIRED                 7501

/* User PIN is not set, indicates MobilePASS is not activated as yet */
#define     MP_ERR_PIN_NOT_SET                      7502

/* Soft PIN is required for auto-enrollment request */
#define     MP_ERR_SOFTPIN_REQUIRED                 7503

/* Soft PIN is NOT required for auto-enrollment request */
#define     MP_ERR_SOFTPIN_NOT_REQUIRED             7504

/* Operation can't be performed as user is logged off right now */
#define     MP_ERR_VALIDATION_REQUIRED              7505

/* Validating MobilePASS token with incorrect PIN. */
#define     MP_ERR_VERIFY_FAIL                      7506
#pragma mark -

#endif // __MP_RETCODES_H__
