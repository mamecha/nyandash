//
//  nyandashAppDelegate.cpp
//  nyandash
//
//  Created by 矢島 新太郎 on 2014/02/20.
//  Copyright __MyCompanyName__ 2014年. All rights reserved.
//

#include "AppDelegate.h"

#include "cocos2d.h"
#include "AppMacros.h"
#include "cocos-ext.h"
#include "SimpleAudioEngine.h"
#include "HelloWorldScene.h"

USING_NS_CC;
using namespace CocosDenshion;

AppDelegate::AppDelegate()
{

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching()
{
    // initialize director
  CCDirector *pDirector = CCDirector::sharedDirector();
  CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
  pDirector->setOpenGLView(pEGLView);
  
  // デザインサイズの設定
  pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionNoBorder);
  
  CCSize frameSize = pEGLView->getFrameSize();
  
  std::vector<std::string> searchPath;
  
  if (frameSize.height > largeResource.size.height) {
    // iPad retina 用リソース
    searchPath.push_back(xlargeResource.dirctory);
    pDirector->setContentScaleFactor(MIN(xlargeResource.size.height / designResolutionSize.height, xlargeResource.size.width / designResolutionSize.width));
  }
  else if (frameSize.height > smallResource.size.height){
    // iPad 用
    searchPath.push_back(largeResource.dirctory);
    pDirector->setContentScaleFactor(MIN(largeResource.size.height / designResolutionSize.height, largeResource.size.width / designResolutionSize.width));
  }
  else {
    // iPhone 用
    searchPath.push_back(smallResource.dirctory);
    pDirector->setContentScaleFactor(MIN(smallResource.size.height / designResolutionSize.height, smallResource.size.width / designResolutionSize.width));
  }
  
  // リソースディレクトリ
  CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);
  pDirector->setDisplayStats(true);
  pDirector->setAnimationInterval(1.0 / 60);
  
  CCScene *pScene  = HelloWorld::scene();
  pDirector->runWithScene(pScene);
  
  return true;
}

// This function will be called when the app is inactive. When comes a phone call,it's be invoked too
void AppDelegate::applicationDidEnterBackground()
{
    CCDirector::sharedDirector()->stopAnimation();
    SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->pauseAllEffects();
}

// this function will be called when the app is active again
void AppDelegate::applicationWillEnterForeground()
{
    CCDirector::sharedDirector()->startAnimation();
    SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
    SimpleAudioEngine::sharedEngine()->resumeAllEffects();
}
