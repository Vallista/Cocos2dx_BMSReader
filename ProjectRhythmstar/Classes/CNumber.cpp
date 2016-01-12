#include "stdafx.h"

/**
 @brief : 생성자
*/
CNumber::CNumber()
{

}

/**
 @brief : 소멸자
*/
CNumber::~CNumber()
{
	Destroy();
}

/**
 @brief : 초기화
 @pLayer : 씬의 정보
*/
void CNumber::Init(CCLayer* pLayer)
{
	m_pLayer		= pLayer;

	m_bVisible		= true;
	m_nScore		= 0;
	m_nLayer		= 0;

	m_cPos			= ccp(0,0);
	m_cSize			= ccp(1,1);
}

/**
 @brief : 삭제 함수
*/
void CNumber::Destroy()
{
	vector<CCSprite*>::iterator itr;
	if(m_pVectable.size())
	{
		for(itr = m_pVectable.begin(); itr != m_pVectable.end() ;)
		{
			m_pLayer->removeChild((*itr) , true);
			itr = m_pVectable.erase(itr);
		}
	}

	m_pVectable.clear();
}

/**
 @brief : 업데이트 함수
 @strPath : 경로
 @strExtension : 확장자
 @nScore : 점수
 @nLayer : z 레이어 값
 @fBetweenX : x 사이 값
 @cPos : 위치
 @dt : delay time
 @type : default = 0  (0이면 중앙 정렬 , 1이면 오른쪽 정렬 , 2면 왼쪽 정렬)
*/
void CNumber::UpdateNumber(string strPath , string strExtension , int nScore , int nLayer , float fBetweenX , CCPoint cPos , float dt , int type)
{
	string strTemp;
	string strNameTemp;
	int nCount = 0;
	int nCountNumber = 0;

	m_nScore = nScore;
	nCountNumber = m_nScore;
	m_cPos = cPos;
	m_nLayer = nLayer;

	vector<CCSprite*>::iterator itr;
	if(m_pVectable.size())
	{
		for(itr = m_pVectable.begin(); itr != m_pVectable.end() ;)
		{
			m_pLayer->removeChild((*itr) , true);
			itr = m_pVectable.erase(itr);
		}
	}

	m_pVectable.clear();

	do
	{
		strTemp = strPath;
		int nTemp = (int)nCountNumber%10;
		if(nTemp < 0) nTemp = 0;
		strTemp += itoa( nTemp , (char*)strNameTemp.c_str() , 10);
		strTemp += ".";
		strTemp += strExtension;

		CCSprite * pTempSprite = CCSprite::create(strTemp.c_str());
		if(type == 0)
			pTempSprite->setPosition( ccp( (m_cPos.x - (fBetweenX * m_cSize.width) * nCount) , m_cPos.y ) );
		else if(type == 1)
			pTempSprite->setPosition( ccp( (m_cPos.x + (fBetweenX * m_cSize.width) * nCount) , m_cPos.y ) );
		else if(type == 2)
			pTempSprite->setPosition( ccp( (m_cPos.x - (fBetweenX * m_cSize.width) * nCount) , m_cPos.y ) );
		pTempSprite->setScaleX(m_cSize.width);
		pTempSprite->setScaleY(m_cSize.height);
		pTempSprite->setVisible(m_bVisible);
		m_pLayer->addChild(pTempSprite , m_nLayer);
		m_pVectable.push_back(pTempSprite);
		nCount++;

	}while((nCountNumber /= 10) > 0);

	nCount-=1;

	if(nCount >= 1)
	{
		for(itr = m_pVectable.begin(); itr != m_pVectable.end(); itr++)
		{ if(type == 0) (*itr)->setPositionX( (*itr)->getPositionX() + (((30*m_cSize.width) * (nCount))/2)); }
	}
}

/**
 @brief : 좌표 지정
 @pos = 위치
*/
void CNumber::setPos(CCPoint pos)
{
	m_cPos = pos;
}

/**
 @brief : 크기 지정
 @pos = 크기
*/
void CNumber::setSize(CCSize pos)
{
	m_cSize = pos;
}

/**
 @brief : 보여주는지 체크
 @bChk : 설정
*/
void CNumber::setVisible(bool bChk)
{
	m_bVisible = bChk;
}

/**
 @brief : 좌표 가져옴
*/
CCPoint CNumber::getPos()
{
	return m_cPos;
}

/**
 @brief : 사이즈 가져옴
*/
CCSize CNumber::getSize()
{
	return m_cSize;
}

/**
 @brief : 보여주는지 가져옴
*/
bool CNumber::getVisible()
{
	return m_bVisible;
}