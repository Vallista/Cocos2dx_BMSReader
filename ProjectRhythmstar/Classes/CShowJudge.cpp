#include "stdafx.h"

CShowJudge::CShowJudge()
{

}

CShowJudge::~CShowJudge()
{
	Destroy();
}

void CShowJudge::Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType)
{
	m_cScale = scale;
	m_cPos = pos;
	m_fTime = 0.0f;
	m_pJudge[m_eType]->setScale2(m_cScale);
	m_pJudge[m_eType]->setVisible2(false);
	m_eType = eType;
	m_bActive = true;
	m_pJudge[m_eType]->setVisible2(true);
	m_pJudge[m_eType]->setScale2(m_cScale);
	m_pJudge[m_eType]->setFrame(0);
	m_pJudge[m_eType]->setLoop(0);
	m_pCombo->setPos(m_cPos);
	m_pCombo->setVisible(true);
}

void CShowJudge::Init(CCLayer* pLayer)
{
	m_pLayer	= pLayer;

	m_bActive	= false;
	m_fMaxTime	= 2.0f;
	m_fTime		= 0.0f;
	m_eType		= E_JUDGEMENT_PERFECT;

	m_fSpeed	= 900.0f;
	m_cPos		= ccp(190.0f , 530.0f); // 530 -> 500
	m_cScale	= ccp(0.2f , 0.2f);

	m_pCombo = new CNumber();
	m_pCombo->Init(m_pLayer);
	
	m_pJudge[E_JUDGEMENT_PERFECT] = new cGHAnimation(m_pLayer);
	m_pJudge[E_JUDGEMENT_PERFECT]->Init_Vector("Images/Game/Judge/judge_list" , "PGreat_" , ccp(190.0f , 400.0f) , ".png" , 100 , 3 , 0.02f , true , 5);

	m_pJudge[E_JUDGEMENT_GREAT] = new cGHAnimation(m_pLayer);
	m_pJudge[E_JUDGEMENT_GREAT]->Init_Vector("Images/Game/Judge/judge_list" , "Great_" , ccp(190.0f , 400.0f) , ".png" , 100 , 1 , 0.1f , false);

	m_pJudge[E_JUDGEMENT_GOOD] = new cGHAnimation(m_pLayer);
	m_pJudge[E_JUDGEMENT_GOOD]->Init_Vector("Images/Game/Judge/judge_list" , "Good_" , ccp(190.0f , 400.0f) , ".png" , 100 , 1 , 0.1f , false);

	m_pJudge[E_JUDGEMENT_BAD] = new cGHAnimation(m_pLayer);
	m_pJudge[E_JUDGEMENT_BAD]->Init_Vector("Images/Game/Judge/judge_list" , "Bad_" , ccp(190.0f , 400.0f) , ".png" , 100 , 1 , 0.1f , false);

	m_pJudge[E_JUDGEMENT_MISS] = new cGHAnimation(m_pLayer);
	m_pJudge[E_JUDGEMENT_MISS]->Init_Vector("Images/Game/Judge/judge_list" , "Poor_" , ccp(190.0f , 400.0f) , ".png" , 100 , 1 , 0.1f , false);
	
}

void CShowJudge::Update(float dt)
{
	if(m_bActive)
	{
		m_fTime += dt;
		ScaleUp(dt);
		//DownEffect(dt);
		m_pCombo->UpdateNumber("Images/Game/Judge/Combo_" , "png" , D_ASSET_MNG->getCombo() , 100 , 34 , ccp(m_cPos.x , m_cPos.y) , dt);
		m_pJudge[m_eType]->AnimationUpdate(dt);

		if(m_fTime >= 0.3f)
			m_pJudge[m_eType]->setVisible2(false);

		if(m_fTime >= m_fMaxTime) 
		{
			m_bActive = false;
			m_pCombo->setVisible(false);

			m_pCombo->UpdateNumber("Images/Game/Judge/Combo_" , "png" , D_ASSET_MNG->getCombo() , 100 , 34 , ccp(m_cPos.x , m_cPos.y) , dt);
			m_fTime = 0.0f;
		}
	}
}

void CShowJudge::Destroy()
{
	m_pCombo->Destroy();
	CC_SAFE_DELETE(m_pCombo);

	for(int i = 0 ; i < E_JUDGEMENT_TYPE_MAX ; i++)
	{
		m_pJudge[i]->Destroy();
		CC_SAFE_DELETE(m_pJudge[i]);
	}
}

void CShowJudge::DownEffect(float dt)
{
	if(m_cPos.y < 530.0f)
	{
		m_cPos.y += m_fSpeed * dt;

		m_pCombo->setPos(ccp(m_cPos.x , m_cPos.y));
	}
}

void CShowJudge::ScaleUp(float dt)
{
	if(m_cScale.x < 1.0f)
	{
		m_cScale.x += 10 * dt;
		m_cScale.y += 10 * dt;

		m_pJudge[m_eType]->setScale2(m_cScale);
		m_pCombo->setSize(ccp(2.3f - m_cScale.x , 2.3f - m_cScale.y));
	}
}