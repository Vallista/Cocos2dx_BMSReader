#pragma once

class CSongManager
{
private:
	FMOD_SYSTEM*				m_pSystem;
	map<int , FMOD_SOUND*>		m_pVecSound;
	map<int , FMOD_CHANNEL*>	m_pVecChannel;

	FMOD_SOUND*					m_pBackSound;
	FMOD_CHANNEL*				m_pBack;

	bool						m_bOverlapChk;
	vector<string>				m_vecTempName;

	FMOD_RESULT					m_nResult;
	int							m_nCount;


public:
	CSongManager();
	~CSongManager();

public:
	void Init();
	void Update(float dt);
	void Destroy();
	
	int CreateSound(string sData);
	void Play(int value);
	void AllStop();

	void ErrorChk(FMOD_RESULT result);
};