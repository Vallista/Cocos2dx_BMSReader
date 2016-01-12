#include "stdafx.h"

CEffect::CEffect(CCLayer* pLayer)
{
	m_pLayer = pLayer;
}

CEffect::~CEffect()
{
	Destroy();
}

void CEffect::Create(CCPoint pos)
{
	m_bActive = true;

	m_pEffect->setPosition(pos);
	m_pEffect->setFrame(0);
}

void CEffect::Init(string strPath , string strImagePath , string strExtension , int nLayer , int nMaxFrame , float aniMaxFrame , bool bFrameOnce)
{
	m_bActive = false;

	m_pEffect = new cGHAnimation(m_pLayer);
	m_pEffect->Init_Vector(strPath , strImagePath , ccp(0,0) , strExtension , nLayer , nMaxFrame , aniMaxFrame , bFrameOnce);
}

void CEffect::Update(float dt)
{
	if(!m_bActive) return;

	m_pEffect->AnimationUpdate(dt);
}

void CEffect::Destroy()
{
	m_pEffect->Destroy();
	CC_SAFE_DELETE(m_pEffect);
}