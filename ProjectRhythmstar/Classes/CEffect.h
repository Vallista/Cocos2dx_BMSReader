#pragma once

class CEffect
{
private:
	CCLayer*			m_pLayer;
	cGHAnimation*		m_pEffect;
	bool				m_bFrameOnce;
	bool				m_bActive;

public:
	CEffect(CCLayer* pLayer);
	~CEffect();

public:
	void Create(CCPoint pos);
	void Init(string strPath , string strImagePath , string strExtension , int nLayer , int nMaxFrame , float aniMaxFrame , bool bFrameOnce);
	void Update(float dt);
	void Destroy();
	
};