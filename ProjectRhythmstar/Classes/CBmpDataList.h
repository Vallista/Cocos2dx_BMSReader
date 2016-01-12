#pragma once

class CBmpDataList : public IFormatList
{ 
public:
	map<int , __ST_BMSINFO_RETUNE>				m_pTable;

public:
	CBmpDataList();
	~CBmpDataList();

public:
	void Init();
	void Update();
	
	void addData(__ST_BMSINFO_RETUNE data);
	
	void eraseData(__ST_BMSINFO_RETUNE data);

	int getSize();
	
	map<int , __ST_BMSINFO_RETUNE> getTable();
	//void Destroy();
};