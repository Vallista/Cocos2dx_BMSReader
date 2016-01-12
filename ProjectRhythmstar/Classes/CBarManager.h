#pragma once

class CBarManager
{
public:
	int				m_nBarCursor;
	vector<CBar*>	m_pBarTable;

public:
	CBarManager();
	~CBarManager();

public:
	void Init();
	void AddBar(int nBarNum , int nChannelFirst , int nChannelSecond , string data);
	void Destroy();
};