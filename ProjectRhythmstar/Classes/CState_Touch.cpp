#include "stdafx.h"

/**
@brief : 초기화
@pNote : 노트 오브젝트 값
*/
void CState_Touch::Enter(INoteObject* pNote)
{
	m_pNote = pNote;
}

/**
@brief : 들어올때
@pos : 위치
*/
void CState_Touch::Execute(CCPoint pos)
{
	m_pNote->setPos(pos);
	m_fMoveTime = 0;
}

/**
@brief : 업데이트
@dt : delay time
*/
void CState_Touch::Update(float dt)
{

}

/**
@brief : 프레임당 움직이는 시간
@dy : 위치
*/
void CState_Touch::MoveTime(double dy)
{
	m_fMoveTime = dy;
}