#pragma once

#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class cGHAnimation
{
private:
	CCSprite			*pSprite;
	CCArray				*pAnimFrames;
	CCAnimation			*pAnimation;
	vector<CCSprite*>	m_pVectorTable;

	CCRect				m_vRect;
	CCLayer*			m_pLayer;
	CCRepeat*			m_pActionStar;
	CCRepeatForever*	m_pActionStar2;

	bool				m_bFrameOnce;

	float				m_fTumTime;
	float				m_fMaxTime;
	float				m_fNowTime;
	int					m_nMaxFrame;
	int					m_nNowFrame;
	int					m_nLoopCount;
	int					m_nLoop;

public:
	cGHAnimation(CCLayer* pLayer)
	{
		m_pLayer = pLayer;
	}

	~cGHAnimation()
	{
		Destroy();
	}

public:

	void Init(string plistPath , string imageGetpath , CCPoint vPosition , string extension = ".png" , int nLayer = 0 , int maxFrame = 1, float aniMaxTime = 0.1f , bool bFrameOnce = false);
	void Init_Vector(string plistPath , string imageGetpath , CCPoint vPosition , string extension = ".png" , int nLayer = 0 , int maxFrame = 1, float aniMaxTime = 0.1f , bool bFrameOnce = false , int nLoopCount = 1);
	void Init(string filePath , CCPoint vPos , string extension = ".png" , int nLayer = 0  , int frameMax = 1 , float aniMaxTime = 0.1f , bool bFrameOnce = false);
	
	void AnimationUpdate(float dt);

	void setPosition(CCPoint pos);
	CCPoint getPosition();

	void setAnchorPositon(CCPoint pos);
	CCPoint getAnchorPosition();

	void setRect(CCRect pos);
	CCRect getRect();

	void setVisible(bool bChk);
	bool getVisible();

	void setVisible2(bool bChk);
	bool getVisible2();

	void setScale(CCPoint pos);
	CCPoint getScale();
	
	void setScale2(CCPoint pos);
	CCPoint getScale2();

	void Destroy();

	void setFrame(int nFrame);
	void setLoop(int nLoop);
};