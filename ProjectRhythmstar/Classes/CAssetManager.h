#pragma once

class CAssetManager
{
private:
	//!< 현재 BMS 플레이 곡의 상태들 
	//!< Song Info
	int			m_nPlayer;				//!< 해당 BMS 파일의 플레이 방법을 의미한다. 
										//!< 1. Player 1 채널 사용 (1인 플레이)
										//!< 2. Player 1과 2 채널 모두 사용 (2인 플레이)
										//!< 3. Player 1과 2 채널 결합하여 사용 (1인 더블 플레이)
										//!< 4. Player 1 채널만을 사용, Player 2채널에는 Player 1채널과 같은 데이터가 들어있는 것으로 간주 (2인 플레이)

	int			m_nPlayerLevel;			//!< 난이도
	int			m_nRank;				//!< 플레이어의 입력을 얼마나 엄격히 판정할 것인지 (기본값 2)
										//!< 0: 아주어려움 1: 어려움 2: 보통 3: 쉬움

	int			m_nTotal;				//!< 전체 오브젝트 수를 수동으로 지정 판정 난이도를 조정하는데 사용
	int			m_nVolWav;				//!< 사운드 파일의 소리 크기를 지정한다. 기본값은 100
	int			m_nDifficulty;			//!< 난이도
	int			m_nJointValue;			//!< 마디 감속 값
	int			m_nTotalNote;			//!< 토탈 노트 값
	int			m_nNowNote;				//!< 현재 재생 노트 값
	int			m_nHP;					//!< 체력
	int			m_nScore;				//!< 점수
	int			m_nCombo;				//!< 현재 콤보
	int			m_nMaxCombo;			//!< 최대 도달 콤보
	int			m_nNowNode;				//!< 현재 노드

	int			m_nEffect[E_EFFECT_MAX]; //!< 이펙트 번호

	char		m_sGenre[256];			//!< 장르
	char		m_sTitle[256];			//!< 노래 이름
	char		m_sArtist[256];			//!< 작곡가
	char		m_sMidifile[256];		//!< 배경음으로 재생될 미디 파일 지정
	char		m_sStageFile[256];		//!< 곡의 데이터를 읽어들일 때 보여줄 이미지 지정
	char		m_sVideoFile[256];		//!< BGA대신에 재생될 동영상 파일 지정 , 이 명령이 지정되면 다른 BGA 관련 명령 무시
	char		m_sSubArtist[256];		//!< 서브 작곡가
	char		m_sBanner[256];			//!< 배너 파일

	float		m_fAttachment;			//!< 배속
	float		m_fDistance;			//!< Bar에서 연산할 값
	float		m_fDelayTime;			//!< dt 값
	float		m_fFPS;					//!< FPS 값
	float		m_fStopTime;			//!< 정지 시간

	__ST_JUDGEMENT_TYPE	m_stJudgement;	//!< 판정목록

	double		m_dJointMul;			//!< 마디 값
	double		m_dBpm;					//!< BPM실수 기본값 130 , 중간에 BPM 값 바뀌면 처음으로 BPM값이 바뀌기 직전까지 적용됨

	bool		m_bCDRotate;			//!< CD돌아가는거 체크
	bool		m_bGameOver;			//!< 게임 오버
	bool		m_bDieActive;			//!< 게임 오버를 활성화 할건지
	bool		m_bGameClear;			//!< 게임 클리어

	string		m_strPath;				//!< 경로

	//!< Wav File Info
	CWaveDataList*	m_pWaveDataList;	//!< Wave 파일 데이터 리스트
	CNoteDataList*	m_pNoteDataList;	//!< 노트 싱크 데이터 리스트
	CBmpDataList*	m_pBmpDataList;		//!< BMP 데이터 리스트

	int			m_nJudgementValue[E_JUDGEMENT_TYPE_MAX];

	

public:
	CAssetManager()
	{
		
	}

	~CAssetManager()
	{
		Destroy();
	} 

public:
	static CAssetManager *ins()
	{
		static CAssetManager ins;
		return &ins;
	};

	void Init();
	void Destroy();

	void Setting(char * player , char * genre , char * title , char * artist , char * bpm
		, char * playLevel , char * rank , char * volwav , char * stagefile , char * total
		, char * midifile , char * vidiofile , char * subartist , char * banner , char * difficulty);

	Auto_Set_Get_Make(string , Path , m_strPath);
	Auto_Set_Get_Make(double , JointMul , m_dJointMul);
	Auto_Set_Get_Make(int , JointValue , m_nJointValue);
	Auto_Set_Get_Make(float , Attachment , m_fAttachment);
	Auto_Set_Get_Make(int , TotalNote , m_nTotalNote);
	Auto_Set_Get_Make(double , FBPM , m_dBpm);
	Auto_Set_Get_Make(bool , CDRotate , m_bCDRotate);
	Auto_Set_Get_Make(int , HP , m_nHP);
	Auto_Set_Get_Make(int , Score , m_nScore);
	Auto_Set_Get_Make(int , MaxCombo , m_nMaxCombo);
	Auto_Set_Get_Make(int , Combo , m_nCombo);
	Auto_Set_Get_Make(int , NowNote , m_nNowNote);
	Auto_Set_Get_Make(int , NowNode , m_nNowNode);
	Auto_Set_Get_Make(float , Distance , m_fDistance);
	Auto_Set_Get_Make(__ST_JUDGEMENT_TYPE , Judge , m_stJudgement);
	Auto_Set_Get_Make(bool , Gameclear , m_bGameClear);
	Auto_Set_Get_Make(bool , Gameover , m_bGameOver);
	Auto_Set_Get_Make(bool , DieActive , m_bDieActive);
	Auto_Set_Get_Make(float , FPS , m_fFPS);
	Auto_Set_Get_Make(float , DelayTime , m_fDelayTime);
	Auto_Set_Get_Make(float , StopTime , m_fStopTime);


	//!< set
	void setJudgementValue(int i , E_JUDGEMENT_TYPE eType);
	void setEffectNum(int i , int value);
	void setPlayer(char* temp);
	void setPlayerLevel(char* temp);
	void setRank(char* temp);
	void setTotal(char* temp);
	void setVolwav(char* temp);
	void setBPM(char* temp);
	void setGenre(char* data);
	void setTitle(char* data);
	void setArtist(char* data);
	void setMidifile(char* data);
	void setStageFile(char* data);
	void setVideoFile(char* data);
	void setSubArtist(char* data);
	void setBanner(char* data);
	void setDifficulty(char* data);

	//!< get
	int getEffectNum(int i);
	int getJudgementValue(int i);
	int getPlayer();
	int getPlayerLevel();
	int getRank();
	int getVolwav();
	int getTotal();
	int getDifficulty();
	double getBPM();
	char* getGenre();
	char* getTitle();
	char* getArtist();
	char* getMidifile();
	char* getStageFile();
	char* getVideoFile();
	char* getSubArtist();
	char* getBanner();
	CWaveDataList* getWaveDataList();
	CNoteDataList* getNoteDataList();
	CBmpDataList* getBmpDataList();
};