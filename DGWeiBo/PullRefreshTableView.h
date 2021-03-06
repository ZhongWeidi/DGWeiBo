//
//  PullRefreshTableView.h
//  demo0425
//
//  Created by zhongweidi on 14-4-25.
//  Copyright (c) 2014年 hnqn. All rights reserved.
//

#import <UIKit/UIKit.h>

@class PullRefreshTableView;
@protocol PullRefreshDelegate <NSObject>

@required
/*下拉刷新触发方法*/
- (void)upLoadDataWithTableView:(PullRefreshTableView *)tableView;

/*上拉加载触发方法*/
- (void)refreshDataWithTableView:(PullRefreshTableView *)tableView;

@end

@interface PullRefreshTableView : UITableView

/*
 如果未使用storyboard或者Nib拖拽的方式创建UITableView,需要使用此方法初始化
 */
- (id)initWithFrame:(CGRect)frame withDelegate:(id)delegate;

/*
 需要实现UITableView的<UIScrollViewDelegate>代理方法scrollViewDidScroll: 传回scrollView对象,否则无法实现上拉功能
 */
-(void)pullScrollViewDidScroll:(UIScrollView *)scrollView;

/*
 需要实现UITableView的<UIScrollViewDelegate>代理方法scrollViewWillBeginDragging: 传回scrollView对象
 */
- (void)pullScrollViewWillBeginDragging:(UIScrollView *)scrollView;

@property (weak ,nonatomic)id<PullRefreshDelegate>pDelegate;

- (void)setPDelegate:(id<PullRefreshDelegate>)pDelegate;

/*
 默认为YES,表示支持继续上拉加载更多数据,触发upLoadDataWithTableView:方法。
 reachedTheEnd = NO : 表示所有数据全部加载完毕,继续上拉将不触发加载数据方法
 */
@property (assign ,nonatomic)BOOL reachedTheEnd;

/*
 默认为NO,如果设为YES,下拉刷新还未处理完毕时，不可继续往下滚动collectionView
 */
@property (assign ,nonatomic)BOOL isUpDataingScrollEnabled;

/*
 默认为NO,数据加载错误或者失败时,如果设置为YES,将在当前视图中心点显示“加载失败”Label,并可以点击当前Label触发
 upLoadDataWithCollectionView:方法。重新刷新数据
 */
@property (assign ,nonatomic)BOOL isUpdataError;

//你可以自定义中心的显示内容
@property (strong ,nonatomic)UILabel * labelCenter;

/*
 刷新数据
 */
- (void)reloadData;

/*
 第一次初始化collectionView后,并调用此方法会在当前视图中心显示“数据正在加载”Label与活动指示器
 */
- (void)reloadDataFirst;

@end


@interface bottomView : UIView{
    
}

@property (strong ,nonatomic)UIActivityIndicatorView * activityBtm;

@property (strong ,nonatomic)UILabel *labelBtm;

@end