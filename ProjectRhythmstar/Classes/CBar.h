#pragma once

class CBar
{
private:
	int					m_nBarNum;
	float				m_fBarHeight;

public:
	vector<CKey*>		m_pVecKey;

public:
	CBar();
	~CBar();

public:
	//!< 노트 셋팅관련 함수들
	void AddKey(int nChannelFirst , int nChannelSecond , string data);
	void CreateNote(int nChannelFirst , int nChannelSecond , string data);
	void DefaultChannel(int nChannelNum , string data);
	void KeyboardChannel(int nChannelNum , string data , bool bVisible = false);

	void ChannelWave(int nType , string data);
	void ChannelCancel(int nChannelNum , string data);
	void ChannelBpm(int nType , string data);
	void ChannelBitmap(int nType , string data);
	void ChannelStop(int nType , string data);

	void BlockProcess(int nKeynum , string data , E_NOTE_TYPE eType , bool bVisible = false);

	Auto_Set_Get_Make(int , Barnum , m_nBarNum);
	Auto_Set_Get_Make(float , Barheight , m_fBarHeight);
};