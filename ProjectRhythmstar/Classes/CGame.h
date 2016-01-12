#pragma once

USING_NS_CC;

class CGame : public CCLayer
{
public:
    virtual bool init();  

	//!< 해당 씬에 대한 싱글톤을 정의 합니다.
    static CCScene* scene();

	//!< 메인 업데이트 루프
	void Update(float dt);

	//!< 터치 관련 함수
	virtual void registerWithTouchDispatcher(void);
	void ccTouchesBegan(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
	void ccTouchesMoved(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
	void ccTouchesEnded(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
	void ccTouchesCancelled(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
    
    CREATE_FUNC(CGame);
};
