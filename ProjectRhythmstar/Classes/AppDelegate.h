#pragma once

#include "stdafx.h"

/**
@brief    AppDelegate의 Header 부분 입니다.

여기서 CCDirector를 불러옵니다.
*/
class  AppDelegate : private cocos2d::CCApplication
{
public:
	//!< 생성자
    AppDelegate();
	//!< 소멸자
    virtual ~AppDelegate();

    /**
    @brief    CCDirector 및 CCScene의 소스가 이 안에 있습니다.
    @return true    true가 반환되면 정상적으로 Initialize를 한 것 입니다.
    @return false   false가 반환되면 정상적이지 못하게 Initialize를 한것 입니다.
    */
    virtual bool applicationDidFinishLaunching();

    /**
	설명은 cpp에 있습니다.
    */
    virtual void applicationDidEnterBackground();

    /**
	설명은 cpp에 있습니다.
    */
    virtual void applicationWillEnterForeground();
};
