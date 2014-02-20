//
//  AppMacros.h
//  nyandash
//
//  Created by 矢島 新太郎 on 2014/02/20.
//
//

#ifndef __nyandash__AppMacros__
#define __nyandash__AppMacros__

#include "cocos2d.h"

typedef struct tagResource
{
  cocos2d::CCSize size;
  char dirctory[100];
} Resource ;

static Resource smallResource = { cocos2d::CCSizeMake(512, 384), "resources-small"  };
static Resource largeResource = { cocos2d::CCSizeMake(1024, 768), "resources-large"  };
static Resource xlargeResource = { cocos2d::CCSizeMake(2048, 1536), "resources-xlarge"  };

static cocos2d::CCSize designResolutionSize = cocos2d::CCSizeMake(1024, 577);

#endif /* defined(__nyandash__AppMacros__) */
