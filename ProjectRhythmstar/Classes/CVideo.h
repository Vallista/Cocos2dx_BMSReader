#pragma once

class CVideo : public iNoPopup
{
private:
	//AVCodec*		m_pCodec;
	//AVFormatContext*	m_pContext;

	//AVFormatContext		*fmt_ctx;

	int					m_nError;

public:
	CVideo();
	~CVideo();

public:
	void Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType);
	void Init(CCLayer* pLayer);
	void Update(float dt);
	void Destroy();

private:
	int FileOpen(string fileName);
	int FindStream();
	
	void ChangeBackGround(string sImageName){};
};