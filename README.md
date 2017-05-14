

## Objective-c
``` objective-c
#import <GrowableTextField/GrowableTextField.h>
```
#### Growable TextField Like Message App

Usage:

 - Make User Interface  
   
   Follow below example to make your user interface and add IBOutlet's.
   
   ``` objective-c
   @property (weak, nonatomic) IBOutlet UIView *containerView;
   ```
``` objective-c
   @property (weak, nonatomic) IBOutlet TextField *textView;
```
<p align="center" >
    <img src="https://github.com/soarlabs/Growable-TextField/blob/master/Sample/3.png">
</p>

- Setup Properties.

 Set properties according to your requirements in **- (void)viewDidLoad**

```objective-c
    _textView.contentInset = UIEdgeInsetsMake(5, 5, 5, 2);
    _textView.returnKeyType = UIReturnKeyDefault;
    _textView.font = [UIFont systemFontOfSize:15.0f];
    _textView.delegate = self;
    _textView.internalTextView.scrollIndicatorInsets = UIEdgeInsetsMake(5, 0, 5, 0);
```

  You can also set properties through **Interface Builder**.

<p align="center" >
    <img src="https://github.com/soarlabs/Growable-TextField/blob/master/Sample/1.png">
</p>
<p align="center" >
    <img src="https://github.com/soarlabs/Growable-TextField/blob/master/Sample/2.png">
</p>

- Adding Keyboard Notification Observer's in **- (void)viewDidLoad**
 
```objective-c
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardWillShow:)
                                                 name:UIKeyboardWillShowNotification
                                               object:nil];
    
    [[NSNotificationCenter defaultCenter] addObserver:self
                                             selector:@selector(keyboardWillHide:)
                                                 name:UIKeyboardWillHideNotification
                                               object:nil];
                                               
```

- Keyboard Notification Handeling

```objective-c

-(void) keyboardWillShow:(NSNotification *)note{
    
    CGRect keyboardBounds;
    [[note.userInfo valueForKey:UIKeyboardFrameEndUserInfoKey] getValue: &keyboardBounds];
    NSNumber *duration = [note.userInfo objectForKey:UIKeyboardAnimationDurationUserInfoKey];
    NSNumber *curve = [note.userInfo objectForKey:UIKeyboardAnimationCurveUserInfoKey];
    keyboardBounds = [self.view convertRect:keyboardBounds toView:nil];
    
    CGRect containerFrame = _containerView.frame;
    containerFrame.origin.y = self.view.bounds.size.height - (keyboardBounds.size.height + containerFrame.size.height);
    
    [UIView beginAnimations:nil context:NULL];
    [UIView setAnimationBeginsFromCurrentState:YES];
    [UIView setAnimationDuration:[duration doubleValue]];
    [UIView setAnimationCurve:[curve intValue]];
    _containerView.frame = containerFrame;
    
    [UIView commitAnimations];
}

-(void) keyboardWillHide:(NSNotification *)note{
    
    NSNumber *duration = [note.userInfo objectForKey:UIKeyboardAnimationDurationUserInfoKey];
    NSNumber *curve = [note.userInfo objectForKey:UIKeyboardAnimationCurveUserInfoKey];
    
    CGRect containerFrame = _containerView.frame;
    containerFrame.origin.y = self.view.bounds.size.height - containerFrame.size.height;
    
    [UIView beginAnimations:nil context:NULL];
    [UIView setAnimationBeginsFromCurrentState:YES];
    [UIView setAnimationDuration:[duration doubleValue]];
    [UIView setAnimationCurve:[curve intValue]];
    _containerView.frame = containerFrame;
    
    [UIView commitAnimations];
}
```

- Delegate to update **TextView** and **ContainerView** Hight.

```objective-c

- (void)growingTextView:(TextField *)growingTextView willChangeHeight:(float)height
{
    float diff = (growingTextView.frame.size.height - height);
    CGRect r = _containerView.frame;
    r.size.height -= diff;
    r.origin.y += diff;
    _containerView.frame = r;
}
```

- Other Delegate's.


```objective-c
- (BOOL)growingTextViewShouldBeginEditing:(TextField *)growingTextView;
- (BOOL)growingTextViewShouldEndEditing:(TextField *)growingTextView;
- (void)growingTextViewDidBeginEditing:(TextField *)growingTextView;
- (void)growingTextViewDidEndEditing:(TextField *)growingTextView;
- (BOOL)growingTextView:(TextField *)growingTextView shouldChangeTextInRange:(NSRange)range replacementText:(NSString *)text;
- (void)growingTextViewDidChange:(TextField *)growingTextView;
- (void)growingTextView:(TextField *)growingTextView didChangeHeight:(float)height;
- (void)growingTextViewDidChangeSelection:(TextField *)growingTextView;
- (BOOL)growingTextViewShouldReturn:(TextField *)growingTextView;

```
