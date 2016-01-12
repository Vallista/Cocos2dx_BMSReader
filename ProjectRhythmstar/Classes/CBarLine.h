#pragma once

class CBarLine : public iNoPopup
{
private:
	bool			m_bActive;
	CCSprite*		m_pSprite;
	CCLayer*		m_pLayer;
	CCPoint			m_cPos;

public:
	CBarLine();
	~CBarLine();

public:
	void Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType);
	void Create(float fY);
	void Init(CCLayer* pLayer);
	void Update(float dt);
	void Destroy();
	void ChangeBackGround(string sImageName){};
};