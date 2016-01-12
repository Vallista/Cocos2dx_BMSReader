#pragma once

class CBackGround : public iNoPopup
{
private:
	CCLayer*			m_pLayer;

	CCSprite*			m_pBackGround;
	CCSprite*			m_pPoorGround;

public:
	CBackGround();
	virtual ~CBackGround();

public:
	void Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType);
	void Init(CCLayer* pLayer);
	void Update(float dt);
	void Destroy();
	void ChangeBackGround(string sImageName);

private:
	void ChangeSprite(CCSprite* pSprite , string sImageName);
};