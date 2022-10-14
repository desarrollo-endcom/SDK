//
//  PinComplexityValidator.h
//  MobilePASS-SDK
//
//  Created by Irina Epshteyn on 2/11/13.
//
//

#import <Foundation/Foundation.h>

@protocol PinComplexity <NSObject>

- (NSPredicate*) getValidationTest;

@optional
- (BOOL) isContainSequentalOrRepetetive:(NSString*) sPin;

@end

@interface AlphaNumeric : NSObject <PinComplexity>
@end

@interface SimpleNumeric : NSObject <PinComplexity>
@end

@interface StrongNumeric : NSObject <PinComplexity>
@end

@interface StrongAlphaNumeric : NSObject <PinComplexity>
@end

@interface PinComplexityValidator : NSObject

+ (BOOL) isValid: (NSString*)pin complexityType:(id<PinComplexity>) complexityType;

@end

