#pragma once

class CNoteDataList : public IFormatList
{
private:
	vector<__ST_BMSDATA_RETURN*>				m_pTable;

public:
	CNoteDataList();
	~CNoteDataList();

public:
	void Init();
	void Update();
	
	void addData(__ST_BMSDATA_RETURN* data);
	
	void eraseData(__ST_BMSDATA_RETURN* data);

	int getSize();
	
	vector<__ST_BMSDATA_RETURN*> getTable();
	//void Destroy();
};