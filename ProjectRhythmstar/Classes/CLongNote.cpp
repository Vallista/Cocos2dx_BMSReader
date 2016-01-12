#include "stdafx.h"

CLongNote::CLongNote()
{

}

CLongNote::~CLongNote()
{
	Destroy();
}

//// 상태 변경

void CLongNote::ChangeState(E_NOTE_STATE state)
{
	ChangeState(m_pState_Pool[state]);
}

void CLongNote::ChangeState( INoteState * pState )
{
	m_pState = pState;
}

void CLongNote::Init(CCLayer* pLayer , int nNotePos , double dY , bool bVisible)
{
	m_pLayer		= pLayer;
	m_bActive		= false;
	m_cPos			= ccp(0,0);

	m_pState = new CState_Die();
	
	m_pState_Pool[E_STATE_MOVE] = new CState_Move();
	m_pState_Pool[E_STATE_TOUCH] = new CState_Touch();
	m_pState_Pool[E_STATE_DIE] = new CState_Die();
	
	m_pState_Pool[E_STATE_MOVE]->Enter(this);
	m_pState_Pool[E_STATE_TOUCH]->Enter(this);
	m_pState_Pool[E_STATE_DIE]->Enter(this);

}

void CLongNote::Create()
{
	m_bActive = true;
}

void CLongNote::Update(float dt)
{
	if(m_pState->GetState() == E_STATE_DIE) return;

	m_pState->Update(dt);
}

void CLongNote::Destroy()
{
	delete m_pState;

	for(int i = 0 ; i < E_STATE_MAX ; i++)
		CC_SAFE_DELETE(m_pState_Pool[i]);
}

//// 이벤트

void CLongNote::Move(CCPoint pos)
{
	ChangeState(m_pState_Pool[E_STATE_MOVE]);
		m_pState->Execute(pos);
}

void CLongNote::Touch(CCPoint pos)
{
	ChangeState(m_pState_Pool[E_STATE_TOUCH]);
	m_pState->Execute(pos);
}

void CLongNote::Die(CCPoint pos)
{
	ChangeState(m_pState_Pool[E_STATE_DIE]);
	m_pState->Execute(pos);
}