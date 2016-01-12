#pragma once

class CJudge : public iNoPopup
{
private:
	bool			m_bActive;
	bool			m_bSwitch;

	float			m_fSpriteAlpha;

	CCSprite*		m_pSpriteBar;
	CCSprite*		m_pSprite;
	CCLayer*		m_pLayer;
	
public:
	CJudge();
	~CJudge();

public:
	void Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType);
	void Init(CCLayer* pLayer);
	void Update(float dt);
	void Destroy();

	void SpriteOpacityAni(float dt);
	void ChangeBackGround(string sImageName){};

};