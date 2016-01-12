#include "stdafx.h"

/**
 @brief : 생성자
*/
CJudge::CJudge()
{

}

/**
 @brief : 소멸자
*/
CJudge::~CJudge()
{
	Destroy();
}

void CJudge::Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType)
{

}
/**
 @brief : 초기화
 @pLayer : 해당 씬의 정보
 */
void CJudge::Init(CCLayer * pLayer)
{
	m_bActive		= true;
	m_bSwitch		= false;
	m_pLayer		= pLayer;
	m_fSpriteAlpha	= 255.0f;

	m_pSprite = CCSprite::create("Images/Game/Line/Line.png");
	m_pSprite->setAnchorPoint(ccp(0.0f , 0.5f));
	m_pSprite->setScaleX(4.65f);
	m_pSprite->setPosition(ccp(D_START_POS , D_JUDGE_POSITIONY + 23));
	m_pSprite->setOpacity(m_fSpriteAlpha);
	m_pLayer->addChild(m_pSprite , 10);

	m_pSpriteBar = CCSprite::create("Images/Game/Line/bar.png");
	m_pSpriteBar->setAnchorPoint(ccp(0.0f , 0.5f));
	m_pSpriteBar->setScaleX(1.03f);
	m_pSpriteBar->setPosition(ccp(D_START_POS , D_JUDGE_POSITIONY));
	m_pLayer->addChild(m_pSpriteBar , 15);
}

/**
 @brief : 업데이트
 @dt : delay time
*/
void CJudge::Update(float dt)
{
	if(!m_bActive) return;

	SpriteOpacityAni(dt);
}

/**
 @brief : 삭제 함수
*/
void CJudge::Destroy()
{
	CC_SAFE_DELETE(m_pSprite);
}

/**
 @brief : SPrite Opacity Animation
 @dt : delay time
*/
void CJudge::SpriteOpacityAni(float dt)
{
	if(m_fSpriteAlpha > 0.0f && !m_bSwitch)
	{
		m_fSpriteAlpha -= 700 * dt;

		if(m_fSpriteAlpha < 0.0f)
			m_fSpriteAlpha = 0.0f;
	}
	else
	{
		m_fSpriteAlpha = 255.0f;
	}
	

	m_pSprite->setOpacity(m_fSpriteAlpha);
}