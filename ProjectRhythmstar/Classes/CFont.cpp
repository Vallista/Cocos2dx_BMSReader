#include "stdafx.h"

CFont::CFont()
{

}

CFont::~CFont()
{

}

void CFont::Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType)
{

}

void CFont::Init(CCLayer* pLayer)
{
	m_pLayer = pLayer;

	//m_pFPS = CCLabelTTF::create("Game FPS         : " , "Thonburi" , 20 , ccp(300,0) , kCCTextAlignmentLeft);
	//m_pFPS->setPosition(ccp( 500 , 700 ));
	//m_pFPS->setColor(ccc3(255,255,255));
	//m_pLayer->addChild(m_pFPS , 90);

	//m_pDelayTime = CCLabelTTF::create("Game DelayTime  : " , "Thonburi" , 20 , ccp(300,0) , kCCTextAlignmentLeft);
	//m_pDelayTime->setPosition(ccp( 500 , 650 ));
	//m_pDelayTime->setColor(ccc3(255,255,255));
	//m_pLayer->addChild(m_pDelayTime , 90);
	//
	//m_pSpeed = CCLabelTTF::create("Game SpeedRate : " , "Thonburi" , 20 , ccp(300,0) , kCCTextAlignmentLeft);
	//m_pSpeed->setPosition(ccp( 500 , 600 ));
	//m_pSpeed->setColor(ccc3(255,255,255));
	//m_pLayer->addChild(m_pSpeed , 90);
}

void CFont::Update(float dt)
{
	//D_ASSET_MNG->setDelayTime(dt);

	//char tempName[256];

	//sprintf(tempName , "Game FPS         : %f" , D_ASSET_MNG->getFPS());
	//m_pFPS->setString(tempName);
	//sprintf(tempName , "Game DelayTime  : %f" , D_ASSET_MNG->getDelayTime());
	//m_pDelayTime->setString(tempName);
	//sprintf(tempName , "Game SpeedRate : %f" , D_ASSET_MNG->getAttachment());
	//m_pSpeed->setString(tempName);
}

void CFont::Destroy()
{
	//CC_SAFE_DELETE(m_pFPS);
	//CC_SAFE_DELETE(m_pDelayTime);
	//CC_SAFE_DELETE(m_pSpeed);
}