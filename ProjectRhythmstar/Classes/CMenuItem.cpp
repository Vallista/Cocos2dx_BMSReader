#include "stdafx.h"

/**
 @brief : 생성자
*/
CMenuItem::CMenuItem()
{

}

/**
 @brief : 소멸자
*/
CMenuItem::~CMenuItem()
{
	Destroy();
}

void CMenuItem::Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType)
{

}


/**
 @brief : 초기화
*/
void CMenuItem::Init(CCLayer* pLayer)
{
	srand(time(NULL));

	m_pLayer		= pLayer;
	m_bActive		= true;
	m_bSwitch		= false;

	m_fBarRotate	= 0.0f;
	m_fSpriteAlpha	= 255.0f;

#pragma region 스프라이트 :: 초기화 구문
	m_pBackGround = CCSprite::create("Images/Game/BackGround/Black.png");
	m_pBackGround->setPosition(ccp(D_DESIGN_WIDTH / 2 , D_DESIGN_HEIGHT / 2));
	m_pLayer->addChild(m_pBackGround , 0);
	
	m_pMenu = CCSprite::create("Images/Game/MenuItem/back.png");
	m_pMenu->setPosition(ccp(D_DESIGN_WIDTH / 2 , 233 / 2));
	m_pLayer->addChild(m_pMenu , 30);
	
	m_pLeftLine = CCSprite::create("Images/Game/MenuItem/leftline.png");
	m_pLeftLine->setAnchorPoint(ccp(0.5f , 0.0f));
	m_pLeftLine->setPosition(ccp(D_START_POS - 27 , 233));
	m_pLayer->addChild(m_pLeftLine , 30);

	m_pRightLine = CCSprite::create("Images/Game/MenuItem/white.png");
	m_pRightLine->setAnchorPoint(ccp(0.5f , 0.0f));
	m_pRightLine->setScaleY(500.0f);
	m_pRightLine->setPosition(ccp(D_START_POS + 298 , 230));
	m_pLayer->addChild(m_pRightLine , 30);

	m_pBar = CCSprite::create("Images/Game/MenuItem/Circle.png");
	m_pBar->setAnchorPoint(ccp(0.5f , 0.5f));
	m_pBar->setScale(1.5f);
	m_pBar->setPosition(ccp(D_START_POS + 27 , 190));
	m_pLayer->addChild(m_pBar , 40);

	m_pSongTimeBar = CCSprite::create("Images/Game/MenuItem/SongTime.png");
	m_pSongTimeBar->setAnchorPoint(ccp(0.5f , 0.5f));
	m_pSongTimeBar->setPosition(ccp(D_START_POS - 15 , D_DESIGN_HEIGHT - 9));
	m_pLayer->addChild(m_pSongTimeBar , 40);

	m_ploadpersent = CCSprite::create("Images/Game/MenuItem/bar.png");
	m_ploadpersent->setAnchorPoint(ccp(0.5f , 0.5f));
	m_ploadpersent->setPosition(ccp(D_START_POS + 355 , 207));
	m_pLayer->addChild(m_ploadpersent , 40);

	m_pLeftYellowEffect = CCSprite::create("Images/Game/MenuItem/YellowEffect.png");
	m_pLeftYellowEffect->setAnchorPoint(ccp(0.5f , 0.5f));
	m_pLeftYellowEffect->setPosition(ccp(D_START_POS - 5 , 103));
	m_pLayer->addChild(m_pLeftYellowEffect , 40);
	
	m_pRightYellowEffect = CCSprite::create("Images/Game/MenuItem/YellowEffect.png");
	m_pRightYellowEffect->setAnchorPoint(ccp(0.5f , 0.5f));
	m_pRightYellowEffect->setPosition(ccp(D_DESIGN_WIDTH - 34 , 103));
	m_pLayer->addChild(m_pRightYellowEffect , 40);

	for(int i = 0 ; i < 50 ; i++)
	{
		if(i < 40)
			m_pNormalHpBar[i] = CCSprite::create("Images/Game/MenuItem/greenhp.png");
		else
			m_pNormalHpBar[i] = CCSprite::create("Images/Game/MenuItem/redhp.png");

		m_pNormalHpBar[i]->setAnchorPoint(ccp(0.5f , 0.5f));
		m_pNormalHpBar[i]->setPosition(ccp(D_START_POS + 10 + (i * 8.0f) , 130));
		m_pLayer->addChild(m_pNormalHpBar[i] , 40);
	}

	for(int i = 0 ; i < 7 ; i++)
	{
		m_pLine[i] = CCSprite::create("Images/Game/MenuItem/white.png");
		m_pLine[i]->setAnchorPoint(ccp(0.5f , 0.0f));
		m_pLine[i]->setScaleX(1.0f);
		m_pLine[i]->setScaleY(500.0f);
		m_pLine[i]->setOpacity(127.0f);
		switch(i)
		{
		case 0:
			m_pLine[i]->setPosition(ccp(D_START_POS + 65.0f  , 232.5f));
			break;
		default:
			if(i % 2 == 0)
				m_pLine[i]->setPosition(ccp(80 + (i / 2) * 64 , 232.5f));
			else
				m_pLine[i]->setPosition(ccp(171 + (i / 2) * 64 , 232.5f));
			break;
		}
		m_pLayer->addChild(m_pLine[i] , 15);
	}

#pragma endregion
#pragma region CNumber 클래스 구문
	m_pBPM = new CNumber();
	m_pBPM->Init(m_pLayer);

	m_pScore = new CNumber();
	m_pScore->Init(m_pLayer);

	m_pMaxCombo = new CNumber();
	m_pMaxCombo->Init(m_pLayer);

	m_pHppercent = new CNumber();
	m_pHppercent->Init(m_pLayer);
#pragma endregion

	m_nHeightTotal		= 0;
	m_fBarperSecond		= 0.0f;
	m_fBarDownTime		= 0.0f;
	m_fPos				= 0.0f;
	m_fFiniteTime		= 0.0f;
	m_fMaxFiniteTime	= 4.0f;
	m_nScore			= 0;

	if(D_GAME_MNG->getBarManager()->m_pBarTable.size())
	{
		for(int j = 0 ; j < D_GAME_MNG->getBarManager()->m_pBarTable.size() ; j++) 
			m_nHeightTotal += (D_GAME_MNG->getBarManager()->m_pBarTable[j]->getBarheight());
	}

}

/**
 @brief : 업데이트
 @dt : delay time
*/
void CMenuItem::Update(float dt)
{
	if(!m_bActive) return;

	RotateCD(dt);
	PlayTime(dt);
	HpBarAni(dt);
	SpriteOpacityAniMng(dt);
	NumberAni(dt);
}

/**
 @brief : 삭제 함수
*/
void CMenuItem::Destroy()
{
	CC_SAFE_DELETE(m_pBackGround);
	CC_SAFE_DELETE(m_pMenu);
	CC_SAFE_DELETE(m_pRightLine);
	CC_SAFE_DELETE(m_pLeftLine);
	CC_SAFE_DELETE(m_pBar);
	CC_SAFE_DELETE(m_ploadpersent);
	
	CC_SAFE_DELETE(m_pLeftYellowEffect);
	CC_SAFE_DELETE(m_pRightYellowEffect);
	CC_SAFE_DELETE(m_pSongTimeBar);

	for(int i = 0 ; i < 50 ; i++)
		CC_SAFE_DELETE(m_pNormalHpBar[i]);

	for(int i = 0 ; i < 7 ; i++)
		CC_SAFE_DELETE(m_pLine[i]);

	m_pBPM->Destroy();
	CC_SAFE_DELETE(m_pBPM);
	m_pScore->Destroy();
	CC_SAFE_DELETE(m_pScore);
	m_pMaxCombo->Destroy();
	CC_SAFE_DELETE(m_pMaxCombo);
	m_pHppercent->Destroy();
	CC_SAFE_DELETE(m_pHppercent);
}

#pragma region Private :: 함수

/**
 @brief : Sprite Opacity Animation 모음 함수
 @dt : delay Time
*/
void CMenuItem::SpriteOpacityAniMng(float dt)
{
	SpriteOpacityAni(m_pLeftYellowEffect , 500 , dt);
	SpriteOpacityAni(m_pRightYellowEffect , 500 , dt);
	SpriteOpacityAni(m_ploadpersent , 1000 , dt);
}

/**
 @brief : HP Bar 관련
 @dt : delay Time
*/
void CMenuItem::HpBarAni(float dt)
{
	for(int i = 0 ; i < 50 ; i++)
	{
		if(i < D_ASSET_MNG->getHP() / 2)
			m_pNormalHpBar[i]->setVisible(true);
		else
			m_pNormalHpBar[i]->setVisible(false);

		if(i >= D_ASSET_MNG->getHP() / 2 - 3 && i <= D_ASSET_MNG->getHP() / 2 - 1)
			SpriteOpacityAni(m_pNormalHpBar[i] , rand()%500 + 1000 , dt);
		else
			m_pNormalHpBar[i]->setOpacity(255);
	}
}

/**
 @brief : 숫자 애니메이션 관련
 @dt : delay Time
*/
void CMenuItem::NumberAni(float dt)
{
	m_pBPM->setSize(ccp(0.8f , 0.8f));
	m_pScore->setSize(ccp(0.8f , 0.8f));
	m_pMaxCombo->setSize(ccp(0.8f , 0.8f));
	m_pHppercent->setSize(ccp(0.7f , 1.15f));

	m_nScore = CSurportManager::Lerp(m_nScore , D_ASSET_MNG->getScore() , 0.1f);
	
	m_pBPM->UpdateNumber("Images/Game/Number/" , "png" , D_ASSET_MNG->getBPM() , 40 , 32 , ccp(D_DESIGN_WIDTH / 2 , 25) , dt);
	m_pScore->UpdateNumber("Images/Game/Number/" , "png" , m_nScore , 40 , 32 , ccp(280 , 85) , dt , 2);
	m_pMaxCombo->UpdateNumber("Images/Game/Number/combo_" , "png" , D_ASSET_MNG->getMaxCombo() , 40 , 32 , ccp(280 , 63) , dt , 2);
	m_pHppercent->UpdateNumber("Images/Game/Number/" , "png" , D_ASSET_MNG->getHP() , 40 , 32 , ccp(415 , 171) , dt , 2);
}

/**
 @brief : Sprite Opacity Animation
 @pSprite : 타겟 스프라이트
 @fSpeed : 속도
 @dt : delay Time
*/
void CMenuItem::SpriteOpacityAni(CCSprite * pSprite , float fSpeed , float dt)
{
	float fAlpha = pSprite->getOpacity();

	if(fAlpha > 0.0f)
	{
		fAlpha -= fSpeed * dt;
	
		pSprite->setOpacity(fAlpha);
	}
	else
		pSprite->setOpacity(255.0f);
}

/**
 @brief : 플레이 시간 보여주는 바
 @dt : delay Time
*/
void CMenuItem::PlayTime(float dt)
{
	if(m_fPos >= m_nHeightTotal)
	{
		m_fFiniteTime += dt;

		if(m_fFiniteTime >= m_fMaxFiniteTime)
			D_ASSET_MNG->setGameclear(true);

		return;
	}

	m_fBarperSecond = ((4 * 60) / D_ASSET_MNG->getBPM());
	m_fBarDownTime = D_MAX_NOTEFIELD_HEIGHT * (dt / m_fBarperSecond);

	m_fPos += m_fBarDownTime;

	float temp = m_fPos / (float)m_nHeightTotal;

	////!< 현재 바와 토탈 바를 가져옵니다.
	//float tempNow = (float)D_ASSET_MNG->getNowNode();
	//float tempTotal = (float)D_GAME_MNG->getBarManager()->m_pBarTable.size();
	//
	////!< 바 갯수에 비례해서 재생시간을 가져옵니다.
	//float temp = tempNow / tempTotal;
	////!< 만약 바 갯수나 토탈 바 갯수가 1보다 작은 0 이면 연산이 안되므로 0으로 초기화
	//if(tempTotal < 1 || tempNow < 1) temp = 0;
	
	//!< 위치 지정합니다.
	m_pSongTimeBar->setPositionY( ( (D_DESIGN_HEIGHT - 297.0f) - ((D_DESIGN_HEIGHT - 297.0f) * temp ) ) - 9.0f + 297.0f);
}

/**
 @brief : CD 돌리기
 @dt : delay Time
*/
void CMenuItem::RotateCD(float dt)
{
	//!< CD 이미지 의 회전을 돌립니다.
	if(!D_ASSET_MNG->getCDRotate()) { m_fBarRotate += 200 * dt; m_pBar->setRotation(m_fBarRotate); }
	else { m_fBarRotate -= 200 * dt; m_pBar->setRotation(m_fBarRotate); }
}

#pragma endregion