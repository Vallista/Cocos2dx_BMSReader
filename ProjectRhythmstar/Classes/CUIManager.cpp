#include "stdafx.h"

/**
 @brief : 생성자
*/
CUIManager::CUIManager()
{
	
}

/**
 @brief : 소멸자
*/
CUIManager::~CUIManager()
{
	//Destroy();
}

/**
 @brief : 초기화 함수
 @param : 씬의 정보
*/
void CUIManager::Init(CCLayer* pLayer)
{
	m_bActive = true;
	m_pLayer = pLayer;

	m_pUi[E_UI_MENUITEM] = new CMenuItem();
	m_pUi[E_UI_MENUITEM]->Init(m_pLayer);

	m_pUi[E_UI_JUDGE] = new CJudge();
	m_pUi[E_UI_JUDGE]->Init(m_pLayer);

	m_pUi[E_UI_VIDEO] = new CVideo();
	m_pUi[E_UI_VIDEO]->Init(pLayer);

	m_pUi[E_UI_KEYBOARD] = new CKeyboard();
	m_pUi[E_UI_KEYBOARD]->Init(m_pLayer);
	
	m_pUi[E_UI_SHOW] = new CShowJudge();
	m_pUi[E_UI_SHOW]->Init(m_pLayer);
	
	m_pUi[E_UI_GAMEOVER] = new CGameOver();
	m_pUi[E_UI_GAMEOVER]->Init(m_pLayer);
	
	m_pUi[E_UI_FONT] = new CFont();
	m_pUi[E_UI_FONT]->Init(m_pLayer);
	
	m_pUi[E_UI_BACKGROUND] = new CBackGround();
	m_pUi[E_UI_BACKGROUND]->Init(m_pLayer);

	for(int i = 0 ; i < D_GAME_MNG->getBarManager()->m_pBarTable.size() ; i++)
	{
		CBarLine * pLine = new CBarLine();
		pLine->Init(m_pLayer);
		pLine->Create( (D_GAME_MNG->getBarManager()->m_pBarTable[i]->getBarnum() * D_GAME_MNG->getBarManager()->m_pBarTable[i]->getBarheight()) + 400 + D_JUDGE_POSITIONY);

		m_vecBarLine.push_back(pLine);
	}
}

/**
 @brief : 업데이트
 @param : delay Time
*/
void CUIManager::Update(float dt)
{
	if(!m_bActive) return;

	for(int i = 0 ; i < E_UI_MAX ; i++)
		m_pUi[i]->Update(dt);

	for(int i = 0 ; i < m_vecBarLine.size() ; i++)
		m_vecBarLine[i]->Update(dt);
}

/**
 @brief : 삭제 함수
*/
void CUIManager::Destroy()
{
	for(int i = 0 ; i <E_UI_MAX ; i++)
	{
		m_pUi[i]->Destroy();
		CC_SAFE_DELETE(m_pUi[i]);
	}
}

iUI* CUIManager::getUI(E_UI eType)
{
	return m_pUi[eType];
}