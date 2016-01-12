#pragma once

class CMenuItem: public iNoPopup 
{
private:
	int				m_nHeightTotal;
	int				m_nScore;

	float			m_fBarperSecond;
	float			m_fBarDownTime;
	float			m_fPos;

	float			m_fFiniteTime;
	float			m_fMaxFiniteTime;

	bool			m_bActive;
	bool			m_bSwitch;

	float			m_fBarRotate;
	float			m_fSpriteAlpha;

	CCLayer*		m_pLayer;
	CCSprite*		m_pBackGround;
	CCSprite*		m_pMenu;

	CCSprite*		m_pRightLine;
	CCSprite*		m_pLeftLine;
	CCSprite*		m_pBar;
	CCSprite*		m_ploadpersent;

	CCSprite*		m_pLeftYellowEffect;
	CCSprite*		m_pRightYellowEffect;
	CCSprite*		m_pNormalHpBar[50];
	
	CCSprite*		m_pSongTimeBar;
	CCSprite*		m_pLine[7];

	CNumber*		m_pBPM;
	CNumber*		m_pScore;
	CNumber*		m_pMaxCombo;
	CNumber*		m_pHppercent;

public:
	CMenuItem();
	~CMenuItem();

public:
	void Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType);
	void Init(CCLayer* pLayer);
	void Update(float dt);
	void Destroy();

private:
	void SpriteOpacityAni(CCSprite * pSprite , float fSpeed , float dt);
	void SpriteOpacityAniMng(float dt);
	void NumberAni(float dt);
	void HpBarAni(float dt);
	void PlayTime(float dt);
	void RotateCD(float dt);
	void ChangeBackGround(string sImageName){};
};