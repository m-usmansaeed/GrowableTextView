//
//  GrowableTextView.h
//
//  Created by M Usman Saeed on 28/01/2016.
//  Copyright © 2016 M Usman Saeed. All rights reserved.
//

//#BCBCC2 Apple's PlaceHolder Text Color
//#F9F9F9 Apple's Message Text Field Background Color
//#BBBAC1 Apple's Message Text Field Border Color
// Standard Apple's TextField Hight 30

#import <UIKit/UIKit.h>

#if __IPHONE_OS_VERSION_MAX_ALLOWED < 60000
#define NSTextAlignment UITextAlignment
#endif

@class TextField;
@class InternalTextView;

@protocol GrowableTextViewDelegate

@optional
- (BOOL)growingTextViewShouldBeginEditing:(TextField *)growingTextView;
- (BOOL)growingTextViewShouldEndEditing:(TextField *)growingTextView;

- (void)growingTextViewDidBeginEditing:(TextField *)growingTextView;
- (void)growingTextViewDidEndEditing:(TextField *)growingTextView;

- (BOOL)growingTextView:(TextField *)growingTextView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;
- (void)growingTextViewDidChange:(TextField *)growingTextView;

- (void)growingTextView:(TextField *)growingTextView willChangeHeight:(float)height;
- (void)growingTextView:(TextField *)growingTextView didChangeHeight:(float)height;

- (void)growingTextViewDidChangeSelection:(TextField *)growingTextView;
- (BOOL)growingTextViewShouldReturn:(TextField *)growingTextView;
@end

IB_DESIGNABLE
@interface TextField : UIView <UITextViewDelegate> {
    InternalTextView *internalTextView;
    
    int minHeight;
    int maxHeight;
    
    
    int maxNumberOfLines;
    int minNumberOfLines;
    
    BOOL animateHeightChange;
    NSTimeInterval animationDuration;
    
    
    NSObject <GrowableTextViewDelegate> *__unsafe_unretained delegate;
    NSTextAlignment textAlignment;
    NSRange selectedRange;
    BOOL editable;
    UIDataDetectorTypes dataDetectorTypes;
    UIReturnKeyType returnKeyType;
    UIKeyboardType keyboardType;
    
    UIEdgeInsets contentInset;
}

@property (nonatomic ,strong)  UITextView *internalTextView;

@property (nonatomic ,assign) IBInspectable int maxNumberOfLines;
@property (nonatomic ,assign) IBInspectable int minNumberOfLines;
@property (nonatomic ,assign) IBInspectable int maxHeight;
@property (nonatomic ,assign) IBInspectable int minHeight;
@property (nonatomic ,assign) IBInspectable BOOL animateHeightChange;
@property (nonatomic ,assign) IBInspectable NSTimeInterval animationDuration;

@property  IBInspectable NSString *placeholder;
@property  IBInspectable UIColor *placeholderColor;


@property (nonatomic) IBInspectable NSInteger borderWidth;
@property (nonatomic) IBInspectable CGFloat cornerRadius;
@property (nonatomic) IBInspectable BOOL masksToBounds;
@property IBInspectable UIColor *borderColor;


@property(unsafe_unretained) NSObject<GrowableTextViewDelegate> *delegate;

@property(nonatomic,strong) NSString *text;
@property IBInspectable UIFont *font;
@property IBInspectable UIColor *textColor;
@property(nonatomic ,assign) IBInspectable NSTextAlignment textAlignment;
@property(nonatomic) NSRange selectedRange;            // only ranges of length 0 are supported
@property(nonatomic,getter=isEditable) BOOL editable;
@property(nonatomic) UIDataDetectorTypes dataDetectorTypes __OSX_AVAILABLE_STARTING(__MAC_NA, __IPHONE_3_0);
@property (nonatomic, assign) IBInspectable UIReturnKeyType returnKeyType;
@property (nonatomic, assign) IBInspectable UIKeyboardType keyboardType;
@property (nonatomic, assign) IBInspectable UIEdgeInsets contentInset;
@property (nonatomic) IBInspectable BOOL isScrollable;
@property(nonatomic) IBInspectable BOOL enablesReturnKeyAutomatically;

#if __IPHONE_OS_VERSION_MIN_REQUIRED >= 70000
- (id)initWithFrame:(CGRect)frame textContainer:(NSTextContainer *)textContainer;
#endif

- (BOOL)becomeFirstResponder;
- (BOOL)resignFirstResponder;
- (BOOL)isFirstResponder;

- (BOOL)hasText;
- (void)scrollRangeToVisible:(NSRange)range;


- (void)refreshHeight;

@end

@interface InternalTextView : UITextView
@property (nonatomic, strong) NSString *placeholder;
@property (nonatomic, strong) UIColor *placeholderColor;
@property (nonatomic) BOOL displayPlaceHolder;

@end



