#pragma once

class CKeyboard : public iNoPopup
{
private:
	CCLayer*		m_pLayer;
	CCSprite*		m_pKeyboard[8];
	CCSprite*		m_pLine[9];

	bool			m_bActive;
	bool			m_bCheckLineSound[9];

	float			m_fLineSizeX[9];
	float			m_fLineOpacity[9];
	float			m_fTimer;

	CEffect*		m_pEffect[8];
public:
	CKeyboard();
	~CKeyboard();

public:
	void Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType);
	void Init(CCLayer* pLayer);
	void Update(float dt);
	void Destroy();

public:
	void setKey(E_KEYBOARD_TYPE eType , E_KEYBOARD_ANITYPE eAniType);
	void setChk(E_KEYBOARD_TYPE eType);
	void ChangeBackGround(string sImageName){};
};