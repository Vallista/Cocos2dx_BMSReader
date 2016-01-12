#include "stdafx.h"

/**
 @brief : 생성자
*/
CBarManager::CBarManager()
{
	m_nBarCursor = 0;
}

/**
 @brief : 소멸자
*/
CBarManager::~CBarManager()
{

}

/**
 @brief : 초기화
*/
void CBarManager::Init()
{
}

/**
 @brief : 바 추가
*/
void CBarManager::AddBar(int nBarNum , int nChannelFirst , int nChannelSecond , string data)
{
	//!< 만약 바번호가 동일한게 있다면 동일한거 바 하나에 추가
	for(int i = 0 ; i < m_pBarTable.size() ; i++)
	{
		if(m_pBarTable[i]->getBarnum() == nBarNum)
		{
			m_pBarTable[i]->AddKey(nChannelFirst , nChannelSecond , data);
			return;
		}
	}

	if(m_nBarCursor != nBarNum)
	{
		for(int i = 0 ; i < m_pBarTable[m_nBarCursor]->m_pVecKey.size(); i++)
		{
			m_pBarTable[m_nBarCursor]->CreateNote(m_pBarTable[m_nBarCursor]->m_pVecKey[i]->getChannelfirst(),
				m_pBarTable[m_nBarCursor]->m_pVecKey[i]->getChannelsecond(),
				m_pBarTable[m_nBarCursor]->m_pVecKey[i]->getData());
		}
	}
	
	//!< 만약 바 번호 중간중간 번호가 없으면 그 번호 매꾸는 작업
	if(m_pBarTable.size())
	{
		int nTemp = (nBarNum - m_pBarTable[m_pBarTable.size() - 1]->getBarnum()) - 1;

		for(int i = 0 ; i < nTemp ; i++)
		{
			CBar * bar = new CBar();
			bar->setBarnum((nBarNum - nTemp) + i);
			bar->setBarheight(D_MAX_NOTEFIELD_HEIGHT);
			m_pBarTable.push_back(bar);
		}
	}

	CBar * bar = new CBar();
	bar->setBarnum(nBarNum);
	bar->setBarheight(D_MAX_NOTEFIELD_HEIGHT);
	bar->AddKey(nChannelFirst , nChannelSecond , data);
	m_pBarTable.push_back(bar);
	m_nBarCursor = nBarNum;
}

void CBarManager::Destroy()
{
	for(int i=0;i<m_pBarTable.size();i++)
	{
		CBar* temp = m_pBarTable[i];

		delete m_pBarTable[i];
	}
}