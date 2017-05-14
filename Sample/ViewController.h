//
//  ViewController.h
//  Sample
//
//  Created by M Usman Saeed on 14/05/2017.
//  Copyright © 2017 M Usman Saeed. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <GrowableTextField/GrowableTextField.h>

@interface ViewController : UIViewController<GrowableTextViewDelegate>{
}

@property (weak, nonatomic) IBOutlet UIView *containerView;
@property (weak, nonatomic) IBOutlet TextField *textView;

- (IBAction)btnDone:(id)sender;




@end

