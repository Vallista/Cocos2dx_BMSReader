#include "stdafx.h"

/**
@brief : 생성자
*/
CNoteManager::CNoteManager()
{

}

/**
@brief : 소멸자
*/
CNoteManager::~CNoteManager()
{
	//Destroy();
}

/**
@brief : 초기화
@pLayer : 씬의 정보
*/
void CNoteManager::Init(CCLayer* pLayer)
{
	m_bActive = true;
	m_nCreateCount = 0;
}

/**
@brief : 업데이트
@dt : delay time
*/
void CNoteManager::Update(float dt)
{
	if(!m_bActive) return;

	//LoadNextNoteDatas(D_GAME_MNG->getNextNode());

	for(int i = 0 ; i < m_pNoteTable.size() ; i++)
	{
		if(!m_pNoteTable[i]->getActive()) return;
		m_pNoteTable[i]->Update(dt);
		m_pNoteTable[i]->MoveTime(dt);
	}
}

/**
@brief : 삭제 함수
*/
void CNoteManager::Destroy()
{
	for(int i=0;i<m_pNoteTable.size();i++)
	{
		delete m_pNoteTable[i];
	}
}