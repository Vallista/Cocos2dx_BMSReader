#pragma once

class CShowJudge : public iNoPopup
{
private:
	bool			m_bActive;
	CCLayer*		m_pLayer;

	CNumber*		m_pCombo;
	cGHAnimation*	m_pJudge[E_JUDGEMENT_TYPE_MAX];

	CCPoint			m_cPos;
	CCPoint			m_cScale;

	float			m_fSpeed;
	float			m_fTime;
	float			m_fMaxTime;
	
	E_JUDGEMENT_TYPE	m_eType;

public:
	CShowJudge();
	virtual ~CShowJudge();

public:
	void Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType);
	void Init(CCLayer* pLayer);
	void Update(float dt);
	void Destroy();

	void DownEffect(float dt);
	void ScaleUp(float dt);
	void ChangeBackGround(string sImageName){};
};