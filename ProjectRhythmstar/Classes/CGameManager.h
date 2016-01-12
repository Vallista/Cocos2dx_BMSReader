#pragma once

class CGameManager
{
private:
	//!< 게임매니저를 활성화 시킬건지 안시킬건지에 대한 변수
	bool					m_pActive;

	//!< 현재 게임 시간
	float					m_fGameTime;	
	float					m_fStopTime;

	//!< 사용할 클래스
	CCLayer*				m_pLayer;
	CBMSParser*				m_pLoadBmsData;

	CNoteManager*			m_pNoteManager;
	CBarManager*			m_pBarManager;
	CSongManager*			m_pSongManager;

	
public:
	CGameManager();			
	~CGameManager();

public:
	//!< 싱글톤
	static CGameManager *ins()
	{
		static CGameManager ins;
		return &ins;
	};

public:
	void Init(CCLayer* pLayer);
	void Update(float dt);
	void Destroy();

	void TouchDown(CCPoint pos);
	void TouchMove(CCPoint pos);
	void TouchUp(CCPoint pos);
	
	//!< Add 메소드들
	void AddCancelBlock(float fCanselTime , int nBarNum , double y);
	void AddBpmBlock(string sBpm , int nBarNum , double y);
	void AddBitmapBlock(string sBitmapnum , int nBarNum , double y);
	void AddWaveBlock(string sWavenum , int nBarNum , double y);
	void AddStopBlock(string sWavenum , int nBarNum , double y);
	void AddKeyboardBlock(int nKeyboard , int nBarNum , string sWavNum , double y , bool bVisible = false);

	//!< 게임 전체 관리
	void Miss();
	void Bad();
	void Good();
	void Great();
	void Perfect();

	//!< 매니저 get
	CNoteManager* getNoteManager();
	CBarManager* getBarManager();
	CSongManager* getSongManager();
	
private:
	//!< 마디 감속
	void UpdateStopNode(float dt);
	//!< init후 쓸모없어진 백터 삭제
	void VectorUnlock();
	//!< String 데이터 생성
	string CreateFullPathData(string sName);

public:
	//!< get set
	Auto_Set_Get_Make(float , GameTime , m_fGameTime);
};
