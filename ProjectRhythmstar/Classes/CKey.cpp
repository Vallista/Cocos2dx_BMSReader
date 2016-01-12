#include "stdafx.h"

CKey::CKey()
{

}

CKey::CKey(int nChannelFirst , int nChannelSecond , string sData)
{
	m_nChannelFirst = nChannelFirst;
	m_nChannelSecond = nChannelSecond;
	m_sData = sData;
}

CKey::~CKey()
{

}