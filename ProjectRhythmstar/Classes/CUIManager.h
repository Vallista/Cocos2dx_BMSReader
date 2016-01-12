#pragma once

class CUIManager
{
private:
	bool			m_bActive;

	CCLayer*		m_pLayer;

	vector<CBarLine*> m_vecBarLine;		//!< 마디 라인선

	iUI*			m_pUi[E_UI_MAX];	//!< UI

public:
	CUIManager();
	~CUIManager();

public:
	static CUIManager* ins()
	{
		static CUIManager ins;
		return &ins;
	}

	void Init(CCLayer* pLayer);
	void Update(float dt);
	void Destroy();

	iUI* getUI(E_UI eType);
};