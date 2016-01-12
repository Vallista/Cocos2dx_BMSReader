#pragma once

class CState_Move : public INoteState
{
private:
	double				m_dMoveTime;
	INoteObject*		m_pNote;

public:
	CState_Move() : INoteState(E_STATE_MOVE) {}
	void Enter(INoteObject* pNote);
	void Update(float dt);
	void Execute(CCPoint pos);
	void MoveTime(double dy);
};