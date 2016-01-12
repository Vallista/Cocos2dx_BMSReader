#pragma once

class INoteState;

class CShortNote : public INoteObject
{
private:
	CCSprite*			m_pSpNote[3];

public:
	CShortNote();
	virtual ~CShortNote();

public:
	// 상태 변경
	void ChangeState(E_NOTE_STATE state);
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

	void MoveTime(float dt);

	CCSprite* getAnimation();
};