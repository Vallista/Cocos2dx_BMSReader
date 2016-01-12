#pragma once

class CNoteManager
{
private:
	bool					m_bActive;
	int						m_nCreateCount;

public:
	vector<INoteObject*>	m_pNoteTable;

public:
	CNoteManager();
	~CNoteManager();

public:
	void Init(CCLayer* pLayer);
	void Update(float dt);
	void Destroy();
};