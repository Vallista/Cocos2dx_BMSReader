#pragma once

class iPopup : public iUI
{
private:

public:
	iPopup();
	virtual ~iPopup();

public:
	virtual void Create(CCPoint pos , CCPoint scale) = 0;
	virtual void Init(CCLayer* pLayer) = 0;
	virtual void Update(float dt) = 0;
	virtual void Destroy() = 0;
};