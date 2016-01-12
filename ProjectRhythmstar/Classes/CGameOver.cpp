#include "stdafx.h"

CGameOver::CGameOver()
{

}

CGameOver::~CGameOver()
{
	Destroy();
}

void CGameOver::Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType)
{

}

void CGameOver::Init(CCLayer* pLayer)
{
	m_pLayer = pLayer;

	m_fSpeed = 200.0f;

	m_pSprite[E_GAMEOVER_UP] = CCSprite::create("Images/Game/GameOver/GameOverUp.png");
	m_pSprite[E_GAMEOVER_DOWN] = CCSprite::create("Images/Game/GameOver/GameOverDown.png");

	m_cPos[E_GAMEOVER_UP] = ccp(D_DESIGN_WIDTH / 2 , D_DESIGN_HEIGHT + 243);

	m_pSprite[E_GAMEOVER_UP]->setPosition(m_cPos[E_GAMEOVER_UP]);
	m_pSprite[E_GAMEOVER_UP]->setScale(2.0f);

	m_cPos[E_GAMEOVER_DOWN] = ccp(D_DESIGN_WIDTH / 2 , - 243);

	m_pSprite[E_GAMEOVER_DOWN]->setPosition(m_cPos[E_GAMEOVER_DOWN]);
	m_pSprite[E_GAMEOVER_DOWN]->setScale(2.0f);

	m_pLayer->addChild(m_pSprite[E_GAMEOVER_UP] , 120);
	m_pLayer->addChild(m_pSprite[E_GAMEOVER_DOWN] , 120);
}

void CGameOver::Update(float dt)
{
	if(!D_ASSET_MNG->getGameover() && !D_ASSET_MNG->getGameclear()) return;

	if(m_cPos[E_GAMEOVER_UP].y > D_DESIGN_HEIGHT - 160)
	{
		m_cPos[E_GAMEOVER_UP].y -= m_fSpeed * dt;
		m_pSprite[E_GAMEOVER_UP]->setPositionY(m_cPos[E_GAMEOVER_UP].y);
	}
	
	if(m_cPos[E_GAMEOVER_DOWN].y < 160)
	{
		m_cPos[E_GAMEOVER_DOWN].y += m_fSpeed * dt;
		m_pSprite[E_GAMEOVER_DOWN]->setPositionY(m_cPos[E_GAMEOVER_DOWN].y);
	}
}

void CGameOver::Destroy()
{
	for(int i = 0 ; i < E_GAMEOVER_MAX ; i++)
		CC_SAFE_DELETE(m_pSprite[i]);
}