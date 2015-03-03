//
//  ViewController.m
//  JEScrollViewPageDemo
//
//  Created by 尹现伟 on 15-3-3.
//  Copyright (c) 2015年 DNE Technology Co.,Ltd. All rights reserved.
//

#import "ViewController.h"
#import "JEUtilityKit+MACRO.h"

@interface ViewController ()<UIScrollViewDelegate>

@property (nonatomic, strong) UIScrollView *scrollView;

@property (nonatomic, strong) UIImageView *imageView;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.scrollView = [[UIScrollView alloc]initWithFrame:ccr(20, SCREEN_HEIGHT/2-150/2, SCREEN_WIDTH-40, 150)];
    [self.view addSubview:self.scrollView];
    
    self.scrollView.delegate = self;
    self.scrollView.clipsToBounds = NO;
    self.scrollView.pagingEnabled = YES;
    self.scrollView.showsHorizontalScrollIndicator = NO;
    self.scrollView.contentSize = ccs(VIEW_W(self.scrollView) * 3, VIEW_H(self.scrollView));
    
    
    for (int i = 0; i<3; i++) {
        
        CGFloat xPos = 10+i*20 + i * (VIEW_W(self.scrollView)-20);
        
        UIImageView *imageView = [[UIImageView alloc]initWithFrame:ccr(xPos, 0, (VIEW_W(self.scrollView)-20), VIEW_H(self.scrollView))];
        imageView.backgroundColor = [UIColor lightGrayColor];
        [self.scrollView addSubview:imageView];
        
        imageView.tag = 100+i;
    }
    
    UIImageView *imageView = (UIImageView *)[self.scrollView viewWithTag:100];
    self.imageView = imageView;
    [self amplification];
    
}

- (void)scrollViewWillEndDragging:(UIScrollView *)scrollView withVelocity:(CGPoint)velocity targetContentOffset:(inout CGPoint *)targetContentOffset{
    int index = targetContentOffset->x / VIEW_W(self.scrollView);
    UIImageView *imageView = (UIImageView *)[self.scrollView viewWithTag:100+index];
    if (imageView != self.imageView) {
        [self narrow];
        
        self.imageView = imageView;
        [self amplification];
    }
}



- (void)amplification{
    if(self.imageView){
        [UIView animateWithDuration:0.1 animations:^{
            self.imageView.frame = ccr(VIEW_TX(self.imageView), -5, VIEW_W(self.imageView), VIEW_H(self.scrollView)+10);
            self.imageView.backgroundColor = [UIColor blackColor];
        }];
    }
}

- (void)narrow{
    if(self.imageView){
        [UIView animateWithDuration:0.1 animations:^{
            self.imageView.frame = ccr(VIEW_TX(self.imageView), 0, VIEW_W(self.imageView), VIEW_H(self.scrollView));
            self.imageView.backgroundColor = [UIColor lightGrayColor];
        }];
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
