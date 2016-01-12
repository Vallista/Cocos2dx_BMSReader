#include "stdafx.h"

USING_NS_CC;

CCScene* CGame::scene()
{
    //!< 씬을 생성합니다 ^^
    CCScene *scene = CCScene::create();
    
    //!< HelloWorld 씬을 만듭니다 ^^
    CGame *layer = CGame::create();

    //!< Scene 싱글톤에 추가시켜줍니다 ^^
    scene->addChild(layer);

    //!< scene 을 return 합니다.
    return scene;
}

//!<  초기화 해주는 곳 입니다.
bool CGame::init()
{
	//!< 만약 부모의 Init이 제대로 활성화 안되있다면 return false 를 돌립니다.
    if ( !CCLayer::init() )
    {
        return false;
    }
    
	this->setTouchEnabled(true);

	D_GAME_MNG->Init(this);

	//!< 스케쥴 등록
	schedule(schedule_selector(CGame::Update), 0.0f);

    return true;
} 

void CGame::Update(float dt)
{
	D_GAME_MNG->Update(dt);
}

void CGame::registerWithTouchDispatcher(void)
{
    CCDirector* pDirector = CCDirector::sharedDirector();
    pDirector->getTouchDispatcher()->addStandardDelegate(this, 0);
}

void CGame::ccTouchesBegan(CCSet* pTouches, CCEvent* event)
{
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);
    CCPoint touchPoint = touch->getLocation();
    
	D_GAME_MNG->TouchDown(touchPoint);
}

void CGame::ccTouchesMoved(CCSet* pTouches, CCEvent* event)
{
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);
    CCPoint touchPoint = touch->getLocation();
    
	D_GAME_MNG->TouchMove(touchPoint);
}
void CGame::ccTouchesEnded(CCSet* pTouches, CCEvent* event)
{
    CCSetIterator it = pTouches->begin();
    CCTouch* touch = (CCTouch*)(*it);
    CCPoint touchPoint = touch->getLocation();
    
	D_GAME_MNG->TouchUp(touchPoint);
}
void CGame::ccTouchesCancelled(CCSet* pTouches, CCEvent* event)
{
    CCLog("Touch cancelled");
}