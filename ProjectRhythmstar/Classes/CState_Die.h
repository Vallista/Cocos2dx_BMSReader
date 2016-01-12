#pragma once

class CState_Die : public INoteState
{
private:
	double				m_dMoveTime;
	INoteObject*		m_pNote;
	string				m_strData;

public:
	CState_Die() : INoteState(E_STATE_DIE) {}
	void Enter(INoteObject* pNote);
	void Update(float dt);
	void Execute(CCPoint pos);
	void MoveTime(double dy);
};