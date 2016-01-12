#pragma once

class INoteState;

class CLongNote : public INoteObject
{

public:
	CLongNote();
	virtual ~CLongNote();

public:
	void ChangeState(E_NOTE_STATE state);
	// 상태 변경
	void ChangeState(INoteState *);
	
	// 이벤트
	void Move(CCPoint pos);
	void Touch(CCPoint pos);
	void Die(CCPoint pos);

	// 고유 업데이트
	void Init(CCLayer* pLayer , int nNotePos , double dY , bool bVisible = false);
	void Create();
	void Update(float dt);
	void Destroy();
	
};