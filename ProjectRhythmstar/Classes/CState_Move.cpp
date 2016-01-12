#include "stdafx.h"

/**
@brief : 초기화
@pNote : 노트 오브젝트
*/
void CState_Move::Enter(INoteObject* pNote)
{
	m_pNote = pNote;
}

/**
@brief : 들어올때
@pos : 위치값
*/
void CState_Move::Execute(CCPoint pos)
{
	m_pNote->setPos(pos);
	m_dMoveTime = 0.0;
}

/**
@brief : 업데이트
@dt : delay time
*/
void CState_Move::Update(float dt)
{
	//!< 충돌위치 - 10까지 보이게 처리
	if(m_pNote->getPos().y > D_JUDGE_POSITIONY - 10 && m_pNote->getPos().y < D_DESIGN_HEIGHT) {
	//!< 백그라운드 음악 노트를 보여줄건지 말껀지 Define에서 처리
#if (D_BACKGROUNDBAR_SHOW == FALSE) 
		if(m_pNote->getPrivateNum() == D_KEYBOARD_NUM) m_pNote->getAnimation()->setVisible(true);
#else 
		m_pNote->getAnimation()->setVisible(true);  
#endif 
	}
	else{
		m_pNote->getAnimation()->setVisible(false); 
	}

	//!< 노트 타입이 10보다 작으면 (9까지 키보드 노트 들)
	if(m_pNote->getPrivateNum() < 10) 
	{ 
		if(m_pNote->getPos().y  > D_JUDGE_POSITIONY - 40) 
		{ 
			double dTemp = m_pNote->getPos().y; 
			dTemp -= m_dMoveTime; 
			m_pNote->setPos(ccp(m_pNote->getPos().x , dTemp)); 
			m_pNote->getAnimation()->setPosition(ccp(m_pNote->getPos().x, (dTemp - D_JUDGE_POSITIONY) * D_ASSET_MNG->getAttachment() + D_JUDGE_POSITIONY )); 
		} 
		else 
		{
			m_pNote->setMissCheck(true);
			D_ASSET_MNG->setCombo(0);
			m_pNote->Die(m_pNote->getPos()); 
		}
	}
	else 
	{ 
		if(m_pNote->getPos().y  > D_JUDGE_POSITIONY) 
		{ 
			double dTemp = m_pNote->getPos().y; 
			dTemp -= m_dMoveTime; 
			m_pNote->setPos(ccp(m_pNote->getPos().x , dTemp)); 
			m_pNote->getAnimation()->setPosition(ccp(m_pNote->getPos().x , dTemp)); 
		} 
		else 
		{
			m_pNote->setDestTime(2.0f);
			m_pNote->Die(m_pNote->getPos()); 
		}
	}
}

/**
@brief : 프레임당 움직이는 위치
@dy : 움직이는 위치
*/
void CState_Move::MoveTime(double dy)
{
	m_dMoveTime = dy;
}
