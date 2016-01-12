#pragma once

/**
@brief :: 노트 상태 최상위 함수
노트의 상태 최상위를 나타내는 함수입니다.
상태에 따라 클래스를 변경해주는 함수입니다.
*/

class INoteObject;

class INoteState
{
private:
	const E_NOTE_STATE m_eState;

public:
	INoteState(E_NOTE_STATE state) : m_eState( state )
	{}

	E_NOTE_STATE GetState()
	{
		return m_eState;
	}

public:
	virtual void Enter(INoteObject* pNote) = 0;
	virtual void Update(float dt) = 0;
	virtual void Execute(CCPoint pos) = 0;
	virtual void MoveTime(double dy) = 0;
};
