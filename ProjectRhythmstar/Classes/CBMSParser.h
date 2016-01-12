#pragma once


class CBMSParser
{
private:
	CCLayer*		m_pLayer;

	// 파일 유틸 관련
	CCFileUtils*	m_pFileUtill;			//!< cocos2dx 파일 입출력
	unsigned long	m_BufferSize;			//!< 버퍼 사이즈
	string			m_pFileData;			//!< 저장 Data
	char*			m_strFilePath;			//!< 파일 경로

	//!< 라인 데이터
	string			m_sLineData;			//!< 라인 데이터 저장 변수

	int				m_nTotalCount;			//!< 현재 진행된 스택 갯수

	__ST_BMSSong_Info		m_BmsInfo;		//!< 사용자 정보 

	//!< 총 갯수
	int				m_nTotalWav;			//!< 웨이브 파일 갯수
	int				m_nTotalBmp;			//!< BMP 파일 갯수
	int				m_nTotalNote;			//!< 총 노트 갯수

	int				m_nThisCount;			//!< 현재 진행

public:
	CBMSParser();
	~CBMSParser();

public:
	//!< 기본적인 루트
	//!< Init 초기화 -> Parse 명령 -> Process 실행
	void Init(CCLayer* pLayer);
	void Parse(char* strFilePath);					//!< 파일안 전체 텍스트 로딩 및 전체적인 데이터 추출

	void LoadLine(string data);								//!< 라인 데이터 추출

	void Process(string name);						//!< 라인 데이터 비교

	//!< 문자열 split
	string* CutString(string data , char * target);
	string* CutString(string data , char * target , char * subTarget);

private:
	int GetBarNum(string data);
	int GetChannelFirst(string data);
	int GetChannelSecond(string data);
};