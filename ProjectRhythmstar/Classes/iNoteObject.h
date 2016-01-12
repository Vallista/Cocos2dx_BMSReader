#pragma once

USING_NS_CC;

class INoteState;

class INoteObject : public iGameObject
{
protected:
	CCLayer*				m_pLayer;

	//!< 상태 패턴 관련
	INoteState*				m_pState;					//!< 현재 타겟팅 된 상태
	INoteState*				m_pState_Pool[D_MAX_STATE];	//!< 상태의 저장공간입니다.

	//!< Note 관련 변수 관련
	bool					m_bActive;					//!< false 면 전체 업데이트 false
	bool					m_bSong;					//!< 체크 했는지
	bool					m_bMiss;					//!< 미스 체크
	bool					m_bVisibleNote;				//!< 노트가 안보이는 노트인지 체크

	int						m_nIndex;					//!< 정보 값
	int						m_nKeyboard;				//!< 키보드 값
	int						m_nPrivateNumber;			//!< 아이디 값
	int						m_nBarNum;					//!< 바 값
	int						m_nNotePos;					//!< 노트 값
	int						m_nSoundNum;				//!< 음 아이디 값

	float					m_fBpm;						//!< 노트의 BPM 정보
	float					m_fCanselTime;				//!< 변속 감속 시간 정보
	float					m_fDestTime;				//!< 목적지 까지 떨어지는 시간

	double					m_dBarperSecond;			//!< BPM 속도로 인해 한 마디당 내려오는 시간
	double					m_dBarDownTime;				//!< 프레임당 노트가 내려오는 시간

	CCPoint					m_cPos;						//!< 위치
	E_NOTE_COLOR			m_eColor;					//!< 색

	string					m_strTextureName;			//!< 텍스쳐 이름

public:
	INoteObject();
	virtual ~INoteObject();

public:
	//!< 상태 변경
	virtual void ChangeState(E_NOTE_STATE state) = 0;
	virtual void ChangeState(INoteState *) = 0;

	//!< 이벤트
	virtual void Move(CCPoint pos) = 0;
	virtual void Touch(CCPoint pos) = 0;
	virtual void Die(CCPoint pos) = 0;

	//!< 고유 업데이트 및 목록
	virtual void Init(CCLayer* pLayer , int nNotePos , double dY , bool bVisible = false) = 0;
	virtual void Create() = 0;
	virtual void Update(float dt) = 0;
	virtual void Destroy() = 0;
	
	virtual void MoveTime(float dt) = 0;

	virtual CCSprite* getAnimation() = 0;

	//!< Set Get 함수들
	Auto_Set_Get_Make_Virtual(bool , Active , m_bActive);
	Auto_Set_Get_Make_Virtual(int , Index , m_nIndex);
	Auto_Set_Get_Make_Virtual(int , Keyboard , m_nKeyboard);
	Auto_Set_Get_Make_Virtual(int , PrivateNum , m_nPrivateNumber);
	Auto_Set_Get_Make_Virtual(int , BarNum , m_nBarNum);
	Auto_Set_Get_Make_Virtual(int , SoundNum , m_nSoundNum);
	Auto_Set_Get_Make_Virtual(float , Bpm , m_fBpm);
	Auto_Set_Get_Make_Virtual(float , CanselTime , m_fCanselTime);
	Auto_Set_Get_Make_Virtual(CCPoint , Pos , m_cPos);
	Auto_Set_Get_Make_Virtual(E_NOTE_COLOR , Color , m_eColor);
	Auto_Set_Get_Make_Virtual(bool , SongCheck , m_bSong);
	Auto_Set_Get_Make_Virtual(float , DestTime , m_fDestTime);
	Auto_Set_Get_Make_Virtual(bool , MissCheck , m_bMiss);
	Auto_Set_Get_Make_Virtual(bool , VisibleNote , m_bVisibleNote);
	Auto_Set_Get_Make_Virtual(string , TextureName , m_strTextureName);
};