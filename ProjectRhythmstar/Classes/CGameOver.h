#pragma once

enum E_GAMEOVER_STATE
{
	E_GAMEOVER_UP = 0,
	E_GAMEOVER_DOWN ,
	E_GAMEOVER_MAX,
};


class CGameOver : public iUI
{
private:
	float			m_fSpeed;
	CCLayer*		m_pLayer;
	CCSprite*		m_pSprite[E_GAMEOVER_MAX];

	CCPoint			m_cPos[E_GAMEOVER_MAX];

public:
	CGameOver();
	virtual ~CGameOver();

public:
	void Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType);
	void Init(CCLayer* pLayer);
	void Update(float dt);
	void Destroy();
	void ChangeBackGround(string sImageName){};
};