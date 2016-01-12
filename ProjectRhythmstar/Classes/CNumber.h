#pragma once

class CNumber
{
private:
	bool					m_bVisible;

	int						m_nScore;
	int						m_nLayer;

	CCLayer*				m_pLayer;
	CCPoint					m_cPos;
	CCSize					m_cSize;
	vector<CCSprite*>		m_pVectable;

public:
	CNumber();
	~CNumber();

public:
	void Init(CCLayer* pLayer);
	void Destroy();
	void UpdateNumber(string strPath , string strExtension , int nScore , int nLayer , float fBetweenX , CCPoint cPos , float dt , int type = 0);
	
	void setPos(CCPoint pos);
	void setSize(CCSize pos);
	void setVisible(bool bChk);
	
	CCPoint getPos();
	CCSize getSize();
	bool getVisible();
};