#include "stdafx.h"

CBackGround::CBackGround()
{

}

CBackGround::~CBackGround()
{

}

void CBackGround::Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType)
{

}

void CBackGround::Init(CCLayer* pLayer)
{
	m_pLayer = pLayer;

	m_pBackGround = CCSprite::create("Images/Game/BackGround/Black.png");//"songs/[sasakuration]AVALON(MQ)/a00000.bmp");//
	m_pBackGround->setPosition(ccp(D_DESIGN_WIDTH / 2 , D_DESIGN_HEIGHT / 2));
	
	m_pLayer->addChild(m_pBackGround , 0);

	m_pPoorGround = CCSprite::create("Images/Game/BackGround/Black.png");
	m_pPoorGround->setPosition(ccp(D_DESIGN_WIDTH / 2 , D_DESIGN_HEIGHT / 2));
	m_pPoorGround->setVisible(false);
	m_pLayer->addChild(m_pPoorGround , 1);
}

void CBackGround::Update(float dt)
{

}

void CBackGround::Destroy()
{
	CC_SAFE_DELETE(m_pBackGround);
	CC_SAFE_DELETE(m_pPoorGround);
}

void CBackGround::ChangeSprite(CCSprite* pSprite , string sImageName)
{
	CCTexture2D *pTexture = CCTextureCache::sharedTextureCache()->addImage(sImageName.c_str());
	pSprite->setTexture(pTexture);
	pSprite->setTextureRect(CCRectMake(0, 0, pTexture->getContentSize().width , pTexture->getContentSize().height));
}

void CBackGround::ChangeBackGround(string sImageName)
{
	ChangeSprite(m_pBackGround , sImageName);
}