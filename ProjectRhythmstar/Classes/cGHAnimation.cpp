#include "stdafx.h"

/**
@brief : plist 가 있는 경우 애니메이션을 돌리는 Init 입니다.
@plistPath : plist 경로를 가져옵니다.
@imageGetpath : image 경로를 가져옵니다.
@maxFrame : 최대 프레임 수를 가져옵니다.
*/
void cGHAnimation::Init(string plistPath , string imageGetpath , CCPoint vPosition , string extension , int nLayer , int maxFrame , float aniMaxTime , bool bFrameOnce)
{
	m_bFrameOnce	= bFrameOnce;
	m_fTumTime		= aniMaxTime;
	m_nMaxFrame		= maxFrame;
	m_fMaxTime		= m_fTumTime * (float)m_nMaxFrame;

	//star-ani_default.plist 를 읽어 각각의 이미지들, 캐시에 넣는다.
	CCString *plistStringName = CCString::createWithFormat("%s.plist" , plistPath.c_str());
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile(plistStringName->getCString());

	pAnimFrames = CCArray::createWithCapacity(maxFrame);

	// 캐시 해놓은 이미지를 하나씩 가져와서 
	for (int i=1; i<=maxFrame; i++) {
		CCString *stringName = CCString::createWithFormat("%s%d%s" , imageGetpath.c_str() , i , extension.c_str());
		CCSpriteFrame* frame = cache->spriteFrameByName(stringName->getCString());
		// 만들어진 파일명의 이미지를 캐시에서 가져와 animFrames 에다가 넣는다.
		pAnimFrames->addObject(frame);
	}

	//최초로 화면에 찍힐 스프라이트를 만들어 준다.
	CCString *stringName = CCString::createWithFormat("%s%d%s" , imageGetpath.c_str() , 1 , extension.c_str());
	pSprite = CCSprite::createWithSpriteFrameName(stringName->getCString());
	pSprite->setPosition(vPosition);
	m_pLayer->addChild(pSprite , nLayer);

	// 여기서부터는 애니메이션을 만드는 과정    
	
	// 애니메이션에 사용할 이미지들이 준비되었다.
	// Animation이랑 Animate 가 이름이 비슷하면서 역할이 헤깔릴 수 있는데, 
	// Animation은 설정이라고 생각하고 움직이도록 하는 액션은 Animate 라고 생각하면 될거 같다.
	// 준비된 이미지 프레임들을 0.1초마다 바꿔보여주도록 설정해서 animation을 만든다.    
	pAnimation = CCAnimation::createWithSpriteFrames(pAnimFrames , m_fTumTime);
	// animation 설정을 이용해서 Animate 액션을 만든다.
	CCAnimate *animate = CCAnimate::create(pAnimation);

	// 계속 까딱까딱 움직이도록 RepeatForever 로 잡아준다. 
	if(m_bFrameOnce)
	{
		m_pActionStar = CCRepeat::create(animate , 1);
		// 혼자 덜렁 만들어져 있던 스프라이트에 에니메이션 액션을 실행하도록 시킨다.
		pSprite->runAction(m_pActionStar);
	}
	else
	{
		m_pActionStar2 = CCRepeatForever::create(animate);
		// 혼자 덜렁 만들어져 있던 스프라이트에 에니메이션 액션을 실행하도록 시킨다.
		pSprite->runAction(m_pActionStar2);
	}

}

/**
@brief : plist 가 있는 경우 애니메이션을 돌리는 Init 입니다.
@plistPath : plist 경로를 가져옵니다.
@imageGetpath : image 경로를 가져옵니다.
@maxFrame : 최대 프레임 수를 가져옵니다.
*/
void cGHAnimation::Init_Vector(string plistPath , string imageGetpath , CCPoint vPosition , string extension , int nLayer , int maxFrame , float aniMaxTime , bool bFrameOnce , int nLoopCount)
{
	m_bFrameOnce	= bFrameOnce;
	m_fTumTime		= aniMaxTime;
	m_nMaxFrame		= maxFrame;
	m_fMaxTime		= m_fTumTime * (float)m_nMaxFrame;
	m_nNowFrame		= 0;
	m_fNowTime		= 0.0f;
	m_nLoop			= 1;
	m_nLoopCount	= nLoopCount;


	//star-ani_default.plist 를 읽어 각각의 이미지들, 캐시에 넣는다.
	CCString *plistStringName = CCString::createWithFormat("%s.plist" , plistPath.c_str());
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile(plistStringName->getCString());

	//pAnimFrames = CCArray::createWithCapacity(maxFrame);

	// 캐시 해놓은 이미지를 하나씩 가져와서 
	for (int i=1; i<=maxFrame; i++) {
		CCString *stringName = CCString::createWithFormat("%s%d%s" , imageGetpath.c_str() , i , extension.c_str());
		CCSpriteFrame* frame = cache->spriteFrameByName(stringName->getCString());
		
		CCSprite * pTempSprite; 
		pTempSprite = CCSprite::createWithSpriteFrame(frame);
		pTempSprite->setPosition(vPosition);
		pTempSprite->setVisible(false);
		m_pLayer->addChild(pTempSprite , nLayer);	
		m_pVectorTable.push_back(pTempSprite);
	}
}

/**
@brief : plist 없이 애니메이션을 돌리는 Init 입니다.
@filePath : 경로 불러옵니다.
@frameMax : 최대 프레임 입니다.
@aniMaxTime : 애니 재생 시간입니다.
*/
void cGHAnimation::Init(string filePath , CCPoint vPos , string extension  , int nLayer , int frameMax , float aniMaxTime , bool bFrameOnce)
{
	m_bFrameOnce	= bFrameOnce;
	m_fTumTime		= aniMaxTime;
	m_nMaxFrame		= frameMax;
	m_fMaxTime		= m_fTumTime * (float)m_nMaxFrame;

	pAnimation = CCAnimation::create();
	CCString *fileName;

	for(int i = 1 ; i <= m_nMaxFrame ; i++)
	{
		fileName = CCString::createWithFormat("%s%d%s" , filePath.c_str() , i , extension.c_str());
		pAnimation->addSpriteFrameWithFileName(fileName->getCString());
	}

	pAnimation->setDelayPerUnit(m_fTumTime);
	pAnimation->setRestoreOriginalFrame(!m_bFrameOnce);

	fileName = CCString::createWithFormat("%s%d%s" , filePath.c_str() , 1 , extension.c_str());
	pSprite = CCSprite::create(fileName->getCString());
	pSprite->setPosition(vPos);

	CCAnimate *animate = CCAnimate::create(pAnimation);

	if(m_bFrameOnce)
	{
		m_pActionStar = CCRepeat::create(animate , 1);
		m_pLayer->addChild(pSprite , nLayer);
		pSprite->runAction(m_pActionStar);
	}
	else
	{
		m_pActionStar2 = CCRepeatForever::create(animate);
		m_pLayer->addChild(pSprite , nLayer);
		pSprite->runAction(m_pActionStar2);
	}

}

/**
 @brief : 애니메이션 업데이트 클래스
 @param : delay time
*/
void cGHAnimation::AnimationUpdate(float dt)
{
	if(m_pVectorTable.size())
	{
		switch(m_bFrameOnce)
		{
		case 0:
			m_fNowTime += dt;

			if(m_fNowTime >= m_fTumTime)
			{
				m_pVectorTable[m_nNowFrame]->setVisible(false);
				m_nNowFrame ++;
				if(m_nNowFrame >= m_nMaxFrame)
					m_nNowFrame = 0;
				m_pVectorTable[m_nNowFrame]->setVisible(true);
				m_fNowTime = 0.0f;
			}

			break;
		case 1:
			m_fNowTime += dt;
			
			if(m_fNowTime >= m_fTumTime)
			{
				m_pVectorTable[m_nNowFrame]->setVisible(false);
				m_nNowFrame ++;

				if(m_nNowFrame >= m_nMaxFrame)
				{
					if(m_nLoop >= m_nLoopCount)
						m_nNowFrame = m_nMaxFrame - 1;
					else
					{
						m_nLoop++;
						m_nNowFrame = 0;
					}
				}
				else
					m_pVectorTable[m_nNowFrame]->setVisible(true);

				m_fNowTime = 0.0f;
			}
			break;
		}
	}
}

void cGHAnimation::setPosition(CCPoint pos)
{
	for(int i = 0 ; i < m_nMaxFrame ; i++)
		m_pVectorTable[i]->setPosition(pos);
}

CCPoint cGHAnimation::getPosition()
{
	return pSprite->getPosition();
}

void cGHAnimation::setAnchorPositon(CCPoint pos)
{
	pSprite->setAnchorPoint(pos);
}

CCPoint cGHAnimation::getAnchorPosition()
{
	return pSprite->getAnchorPoint();
}

void cGHAnimation::setRect(CCRect pos)
{
	pSprite->setTextureRect(pos);
}

CCRect cGHAnimation::getRect()
{
	return pSprite->getTextureRect();
}

void cGHAnimation::setVisible(bool bChk)
{
	pSprite->setVisible(bChk);
}

void cGHAnimation::setVisible2(bool bChk)
{
	for(int i = 0 ; i < m_nMaxFrame ; i++)
		m_pVectorTable[i]->setVisible(bChk);
}

bool cGHAnimation::getVisible()
{
	return pSprite->isVisible();
}

void cGHAnimation::setScale(CCPoint pos)
{
	pSprite->setScaleX(pos.x);
	pSprite->setScaleY(pos.y);
}

void cGHAnimation::setScale2(CCPoint pos)
{
	for(int i = 0 ; i < m_nMaxFrame ; i++)
	{
		m_pVectorTable[i]->setScaleX(pos.x);
		m_pVectorTable[i]->setScaleY(pos.y);
	}
}

CCPoint cGHAnimation::getScale()
{
	CCPoint tempSize;
	tempSize.x = pSprite->getScaleX();
	tempSize.y = pSprite->getScaleY();

	return tempSize;
}

void cGHAnimation::Destroy()
{
	CC_SAFE_DELETE(pSprite);
	CC_SAFE_DELETE(pAnimFrames);
	CC_SAFE_DELETE(pAnimation);
}

void cGHAnimation::setFrame(int nFrame)
{
	m_nNowFrame = nFrame;
	//pAnimation->setFrames(&pAnimFrames[nFrame]);
}

void cGHAnimation::setLoop(int nLoop)
{
	m_nLoop = nLoop;
}