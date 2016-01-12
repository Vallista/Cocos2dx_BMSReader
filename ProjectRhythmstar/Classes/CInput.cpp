#include "stdafx.h"

/**
 @brief : 생성자
*/
CInput::CInput()
{
	memset(m_eKeyState , DEFAULT , sizeof(m_eKeyState));
}

/**
 @brief : 소멸자
*/
CInput::~CInput()
{

}

/**
 @brief : inline 함수 키 누를때
 @vk : 키
*/
bool CInput::KeyDown(int vk)
{
	return ((GetAsyncKeyState(vk) & 0x8000) ? true : false);
}

/**
 @brief : inline 함수 키 땔때
 @vk : 키
*/
bool CInput::KeyUp(int vk)
{
	return ((GetAsyncKeyState(vk) & 0x8000) ? false : true);
}

/**
 @brief : 키 정보 가져오는거 누를때
 @vk : 키
*/
bool CInput::GetKeyDown(int vk)
{
	if(m_eKeyState[vk] == DOWN)
		return true;

	return false;
}

/**
 @brief : 키 정보 가져오는거 땔때
 @vk : 키
*/
bool CInput::GetKeyUp(int vk)
{
	if(m_eKeyState[vk] == UP)
		return true;

	return false;
}

/**
 @brief : 업데이트 함수
*/
void CInput::Update()
{
	for(int i = 0 ; i < 256 ; i++)
	{
		if(m_eKeyState[i] == DOWN && KeyUp(i))
			m_eKeyState[i] = UP;
		else if(KeyDown(i))
			m_eKeyState[i] = DOWN;
		else
			m_eKeyState[i] = DEFAULT;
	}
}