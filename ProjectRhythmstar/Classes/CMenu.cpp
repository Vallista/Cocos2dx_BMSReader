#include "stdafx.h"

USING_NS_CC;

CCScene* CMenu::scene()
{
    //!< 씬을 생성합니다 ^^
    CCScene *scene = CCScene::create();
    
    //!< HelloWorld 씬을 만듭니다 ^^
    CMenu *layer = CMenu::create();

    //!< Scene 싱글톤에 추가시켜줍니다 ^^
    scene->addChild(layer);

    //!< scene 을 return 합니다.
    return scene;
}

//!<  초기화 해주는 곳 입니다.
bool CMenu::init()
{
	//!< 만약 부모의 Init이 제대로 활성화 안되있다면 return false 를 돌립니다.
    if ( !CCLayer::init() )
    {
        return false;
    }
    

	//!< 스케쥴 등록
	schedule(schedule_selector(CMenu::Update) , 0.0);

    return true;
} 

void CMenu::Update(float dt)
{
	
}