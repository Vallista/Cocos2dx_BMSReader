#include "stdafx.h"

CNoteDataList::CNoteDataList()
{

}

CNoteDataList::~CNoteDataList()
{

}

void CNoteDataList::Init()
{
	
}

void CNoteDataList::Update()
{

}

void CNoteDataList::addData(__ST_BMSDATA_RETURN* data)
{
	m_pTable.push_back(data);
}

void CNoteDataList::eraseData(__ST_BMSDATA_RETURN* data)
{
	//vector<__ST_BMSDATA_RETURN*>::iterator itr = find(m_pTable.begin() , m_pTable.end() , data);
	//m_pTable.erase(itr);
}

int CNoteDataList::getSize()
{
	return m_pTable.size();
}

vector<__ST_BMSDATA_RETURN*> CNoteDataList::getTable()
{
	return m_pTable;
}

//
//void CNoteDataList::Destroy()
//{
//	m_pTable.clear();
//}