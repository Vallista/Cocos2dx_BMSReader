#pragma once

class CState_Touch : public INoteState
{
private:
	float				m_fMoveTime;
	INoteObject*		m_pNote;

public:
	CState_Touch() : INoteState(E_STATE_TOUCH) {}
	void Enter(INoteObject* pNote);
	void Update(float dt);
	void Execute(CCPoint pos);
	void MoveTime(double dy);
};