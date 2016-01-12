#include "stdafx.h"

CWaveDataList::CWaveDataList()
{

}

CWaveDataList::~CWaveDataList()
{

}

void CWaveDataList::Init()
{
	
}

void CWaveDataList::Update()
{

}

void CWaveDataList::addData(__ST_BMSINFO_RETUNE data)
{
	m_pTable[data.nNameTarget] = data;
}

void CWaveDataList::eraseData(__ST_BMSINFO_RETUNE data)
{
	//vector<__ST_BMSINFO_RETUNE*>::iterator itr = find(m_pTable.begin() , m_pTable.end() , data);
	//m_pTable.erase(itr);
}

int CWaveDataList::getSize()
{
	return m_pTable.size();
}

map<int , __ST_BMSINFO_RETUNE> CWaveDataList::getTable()
{
	return m_pTable;
}
//
//void CWaveDataList::Destroy()
//{
//	//m_pTable.clear();
//}