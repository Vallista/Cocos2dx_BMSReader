#include "stdafx.h"

/**
 @brief : 생성자
*/
CBarLine::CBarLine()
{

}

/**
 @brief : 소멸자
*/
CBarLine::~CBarLine()
{
	Destroy();
}

/**
 @brief : 생성 함수
 @fY : Y좌표 위치
*/
void CBarLine::Create(float fY)
{
	m_bActive		= true;
	m_cPos			= ccp(D_START_POS , fY);
	m_pSprite->setPosition(ccp(m_cPos.x , m_cPos.y * D_ASSET_MNG->getAttachment()));
}


void CBarLine::Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType)
{

}
 
/**
 @brief : 초기화 함수
 @pLayer : 씬의 레이어
*/
void CBarLine::Init(CCLayer * pLayer)
{
	m_bActive		= false;
	m_pLayer		= pLayer;

	m_pSprite = CCSprite::create("Images/Game/Line/white.png");
	m_pSprite->setAnchorPoint(ccp(0.0f , 0.5f));
	m_pSprite->setVisible(false);
	m_pSprite->setScaleX(298.0f);
	m_pSprite->setOpacity(129);
	m_pLayer->addChild(m_pSprite , 10);
}

/**
 @brief : 업데이트 함수
*/
void CBarLine::Update(float dt)
{
	//!< 서비스 On 안되있으면 return
	if(!m_bActive) return;
	if(D_ASSET_MNG->getGameover()) return;

	//!< 충돌처리 라인까지 가면 없어지도록
	if(m_pSprite->getPositionY() < D_JUDGE_POSITIONY) { D_ASSET_MNG->setNowNode(D_ASSET_MNG->getNowNode()+1); m_bActive = false; m_pSprite->setVisible(false); return; }

	//!< 마디 , 초당 마디 , BPM 관련해서 이동속도 지정
	double dBarperSecond = ((4 * 60) / D_ASSET_MNG->getBPM());
	double dBarDownTime = D_MAX_NOTEFIELD_HEIGHT * (dt / dBarperSecond);

	//!< 현재 좌표 임시 저장소
	float fTemp = m_cPos.y;

	//!< 이동
	fTemp -= dBarDownTime;
	
	//!< 좌표 지정
	m_cPos.y = fTemp;

	//!< 좌표 지정
	m_pSprite->setPositionY((m_cPos.y - D_JUDGE_POSITIONY) * D_ASSET_MNG->getAttachment() + D_JUDGE_POSITIONY);

	//!< 이미지 위치가 화면 밖이면
	if(m_pSprite->isVisible() || m_pSprite->getPosition().y > D_DESIGN_HEIGHT) return;
	
	//!< fade 처리
	m_pSprite->setVisible(true);
}

void CBarLine::Destroy()
{
	CC_SAFE_DELETE(m_pSprite);
}