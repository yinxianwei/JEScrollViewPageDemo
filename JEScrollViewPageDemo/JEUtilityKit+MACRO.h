//
//  JEUtilityKit+MACRO.h
//  JEUtilityKitDemo
//
//  Created by 尹现伟 on 15-1-8.
//

#ifndef JEUtilityKitDemo_JEUtilityKit_MACRO_h
#define JEUtilityKitDemo_JEUtilityKit_MACRO_h

#pragma mark - Log Flag

#ifdef DEBUG
#	define NSLog(fmt, ...) NSLog((fmt),##__VA_ARGS__)
#else
#	define NSLog(...)
#endif

#define LogFrame(frame) NSLog(@"frame[X=%.1f,Y=%.1f,W=%.1f,H=%.1f",frame.origin.x,frame.origin.y,frame.size.width,frame.size.height)
#define LogPoint(point) NSLog(@"Point[X=%.1f,Y=%.1f]",point.x,point.y)


#pragma mark - Object create

#define String(fmt, ...)    [NSString stringWithFormat:(fmt),##__VA_ARGS__]
#define	URL(fmt, ...)	    [NSURL URLWithString:String((fmt),##__VA_ARGS__)]


#pragma mark - Time Setup

#if TARGET_IPHONE_SIMULATOR
#import <objc/objc-runtime.h>
#else
#import <objc/runtime.h>
#endif

#ifdef	_DEBUG
#define	DNSLog(...);	NSLog(__VA_ARGS__);
#define DNSLogMethod	NSLog(@"[%s] %@", class_getName([self class]), NSStringFromSelector(_cmd));
#define DNSLogPoint(p)	NSLog(@"%f,%f", p.x, p.y);
#define DNSLogSize(p)	NSLog(@"%f,%f", p.width, p.height);
#define DNSLogRect(p)	NSLog(@"%f,%f %f,%f", p.origin.x, p.origin.y, p.size.width, p.size.height);

CFAbsoluteTime startTime;
#define D_START			startTime=CFAbsoluteTimeGetCurrent();
#define D_END			DNSLog(@"[%s] %@ %f seconds", class_getName([self class]), NSStringFromSelector(_cmd), CFAbsoluteTimeGetCurrent() - startTime );
#else
#define DNSLog(...);
#define DNSLogMethod
#define DNSLogPoint(p)
#define DNSLogSize(p)
#define DNSLogRect(p)

#define D_START
#define D_END               
#endif

#define SAFE_FREE(p) { if(p) { free(p); (p)=NULL; } }

#pragma mark - AppDelegate
//AppDelegate
#define APPDELEGATE [(AppDelegate*)[UIApplication sharedApplication]  delegate]
//UIApplication
#define APPD        [UIApplication sharedApplication]
//UIWindow
#define WINDOW      [APPD.windows objectAtIndex:0]
#define rootNavVC   (UINavigationController*)[[[[UIApplication sharedApplication] delegate] window] rootViewController]

#pragma mark - is iPhone

#define isIOS7 ([[[UIDevice currentDevice] systemVersion] floatValue] >=7.0 ? YES : NO)
#define isPad  ([[UIDevice currentDevice] userInterfaceIdiom] == UIUserInterfaceIdiomPad)
#define isiPhone5 ([[UIScreen mainScreen]bounds].size.height == 568)
#define isSimulator (NSNotFound != [[[UIDevice currentDevice] model] rangeOfString:@"Simulator"].location)
#define isRetina ([UIScreen instancesRespondToSelector:@selector(currentMode)] ? CGSizeEqualToSize(CGSizeMake(640, 960), [[UIScreen mainScreen] currentMode].size) : NO)

#define isEmail(emailStr) [[[NSRegularExpression regularExpressionWithPattern:@"[\\w!#$%&'*+/=?^_`{|}~-]+(?:\\.[\\w!#$%&'*+/=?^_`{|}~-]+)*@(?:[\\w](?:[\\w-]*[\\w])?\\.)+[\\w](?:[\\w-]*[\\w])?" options:NSRegularExpressionCaseInsensitive error:nil] matchesInString:emailStr options:0 range:NSMakeRange(0, [emailStr length])] count]

#define isPhoneNum(mobile) [[NSPredicate predicateWithFormat:@"SELF MATCHES %@",@"^(13[0-9]|15[0|1|2|3|5|6|7|8|9]|18[0-9]|17[0|6|7]|14[5])\\d{8}$"] evaluateWithObject:mobile]

#define isCarNo(CarNo)  [[NSPredicate predicateWithFormat:@"SELF MATCHES %@",@"^[A-Za-z]{1}[A-Za-z_0-9]{5}$"] evaluateWithObject:CarNo]

#pragma mark - font
#define FONT(font) [UIFont systemFontOfSize:font]

#pragma mark - String  functions
#define EMPTY_STRING        @""
#define STR(key)            NSLocalizedString(key, nil)

#pragma mark - UIImage  UIImageView  functions
#define IMG(name) [UIImage imageNamed:name]
#define IMGF(name) [UIImage imageNamedFixed:name]

#pragma mark - File  functions
#define PATH_OF_APP_HOME    NSHomeDirectory()
#define PATH_OF_TEMP        NSTemporaryDirectory()
#define PATH_OF_DOCUMENT    [NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES) objectAtIndex:0]

#pragma mark - Color Functions
#define RGBCOLOR(r,g,b) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:1]
#define RGBACOLOR(r,g,b,a) [UIColor colorWithRed:(r)/255.0f green:(g)/255.0f blue:(b)/255.0f alpha:(a)]

#define UIColorFromRGB(rgbValue) [UIColor \
colorWithRed:((float)((rgbValue & 0xFF0000) >> 16))/255.0 \
green:((float)((rgbValue & 0xFF00) >> 8))/255.0 \
blue:((float)(rgbValue & 0xFF))/255.0 alpha:1.0]

#pragma mark - Size ,X,Y, View ,Frame

#define ccp(__X__,__Y__) CGPointMake(__X__, __Y__)
#define ccs(__W__,__H__) CGSizeMake(__W__, __H__)
#define ccr(__X__,__Y__,__W__,__H__) CGRectMake(__X__,__Y__,__W__,__H__)

//get the  size of the Screen
#define SCREEN_HEIGHT [[UIScreen mainScreen]bounds].size.height
#define SCREEN_WIDTH [[UIScreen mainScreen]bounds].size.width
#define HEIGHT_SCALE  ([[UIScreen mainScreen]bounds].size.height/480.0)

//get the  size of the Application
#define APP_HEIGHT [[UIScreen mainScreen]applicationFrame].size.height
#define APP_WIDTH [[UIScreen mainScreen]applicationFrame].size.width

#define APP_SCALE_H  ([[UIScreen mainScreen]applicationFrame].size.height/480.0)
#define APP_SCALE_W  ([[UIScreen mainScreen]applicationFrame].size.width/320.0)

//get the left top origin's x,y of a view
#define VIEW_TX(view) (view.frame.origin.x)
#define VIEW_TY(view) (view.frame.origin.y)

//get the width size of the view:width,height
#define VIEW_W(view)  (view.frame.size.width)
#define VIEW_H(view)  (view.frame.size.height)

//get the right bottom origin's x,y of a view
#define VIEW_BX(view) (view.frame.origin.x + view.frame.size.width)
#define VIEW_BY(view) (view.frame.origin.y + view.frame.size.height )

//get the x,y of the frame
#define FRAME_TX(frame)  (frame.origin.x)
#define FRAME_TY(frame)  (frame.origin.y)
//get the size of the frame
#define FRAME_W(frame)  (frame.size.width)
#define FRAME_H(frame)  (frame.size.height)

#define DistanceFloat(PointA,PointB) sqrtf((PointA.x - PointB.x) * (PointA.x - PointB.x) + (PointA.y - PointB.y) * (PointA.y - PointB.y))

#pragma mark - shared

#define SYNTHESIZE_SINGLETON_FOR_CLASS(classname) \
\
static classname *shared##classname = nil; \
\
+ (classname *)shared##classname \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [[self alloc] init]; \
} \
} \
\
return shared##classname; \
} \
\
+ (id)allocWithZone:(NSZone *)zone \
{ \
@synchronized(self) \
{ \
if (shared##classname == nil) \
{ \
shared##classname = [super allocWithZone:zone]; \
return shared##classname; \
} \
} \
\
return nil; \
} \
\
- (id)copyWithZone:(NSZone *)zone \
{ \
return self; \
}


#endif
