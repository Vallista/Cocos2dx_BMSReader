#pragma once

class iNoPopup : public iUI
{
private:

public:
	iNoPopup();
	virtual ~iNoPopup();

public:
	virtual void Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType) = 0;
	virtual void Init(CCLayer* pLayer) = 0;
	virtual void Update(float dt) = 0;
	virtual void Destroy() = 0;
	virtual void ChangeBackGround(string sImageName) = 0;
};