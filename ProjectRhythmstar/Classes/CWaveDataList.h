#pragma once

class CWaveDataList : public IFormatList
{
private:
	map<int , __ST_BMSINFO_RETUNE>				m_pTable;

public:
	CWaveDataList();
	~CWaveDataList();

public:
	void Init();
	void Update();
	
	void addData(__ST_BMSINFO_RETUNE data);
	
	void eraseData(__ST_BMSINFO_RETUNE data);

	int getSize();
	
	map<int , __ST_BMSINFO_RETUNE> getTable();

	//void Destroy();

};