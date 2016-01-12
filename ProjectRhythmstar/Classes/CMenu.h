#pragma once

USING_NS_CC;

class CMenu : public CCLayer
{
public:
    virtual bool init();  

	//!< ÇØ´ç ¾À¿¡ ´ëÇÑ ½Ì±ÛÅæÀ» Á¤ÀÇ ÇÕ´Ï´Ù.
    static CCScene* scene();

	void Update(float dt);
    
    CREATE_FUNC(CMenu);
};
