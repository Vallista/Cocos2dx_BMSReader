#pragma once

class CKey
{
private:
	int m_nChannelFirst;
	int m_nChannelSecond;
	string m_sData;

public:
	CKey();
	CKey(int nChannelFirst , int nChannelSecond , string sData);
	~CKey();

	Auto_Set_Get_Make(int , Channelfirst , m_nChannelFirst);
	Auto_Set_Get_Make(int , Channelsecond , m_nChannelSecond);
	Auto_Set_Get_Make(string , Data , m_sData);

};