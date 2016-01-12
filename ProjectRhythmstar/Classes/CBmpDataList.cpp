#include "stdafx.h"

CBmpDataList::CBmpDataList()
{

}

CBmpDataList::~CBmpDataList()
{

}

void CBmpDataList::Init()
{
	
}

void CBmpDataList::Update()
{

}

void CBmpDataList::addData(__ST_BMSINFO_RETUNE data)
{
	
}

void CBmpDataList::eraseData(__ST_BMSINFO_RETUNE data)
{
	//vector<__ST_BMSINFO_RETUNE*>::iterator itr = find(m_pTable.begin() , m_pTable.end() , data);
	//m_pTable.erase(itr);
	
}

int CBmpDataList::getSize()
{
	return m_pTable.size();
}

map<int , __ST_BMSINFO_RETUNE> CBmpDataList::getTable()
{
	return m_pTable;
}


//void CBmpDataList::Destroy()
//{
//	m_pTable.clear();
//}