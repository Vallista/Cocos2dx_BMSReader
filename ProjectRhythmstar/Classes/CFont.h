#pragma once

class CFont : public iUI
{
private:
	CCLayer*	m_pLayer;

	CCLabelTTF * m_pFPS;
	CCLabelTTF * m_pDelayTime;
	CCLabelTTF * m_pSpeed;

public:
	CFont();
	~CFont();

public:
	void Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType);
	void Init(CCLayer* pLayer);
	void Update(float dt);
	void Destroy();
	
	void ChangeBackGround(string sImageName){};
};