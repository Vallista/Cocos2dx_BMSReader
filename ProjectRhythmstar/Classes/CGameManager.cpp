#include "stdafx.h"

/**
 @brief : 생성자
*/
CGameManager::CGameManager()
{

}

/**
 @brief : 소멸자
*/
CGameManager::~CGameManager()
{
	Destroy();
}

#pragma region Add :: 추가 구문

void CGameManager::AddCancelBlock(float fCanselTime , int nBarNum , double y)
{
	INoteObject * pNote = new CShortNote();
	
	pNote->Init(m_pLayer , D_CANSELBLOCK_NUM , y);
	
	pNote->setCanselTime(fCanselTime);
	pNote->setBarNum(nBarNum);
	
	pNote->Create();
	 
	pNote->setPrivateNum(D_CANSELBLOCK_NUM);

	m_pNoteManager->m_pNoteTable.push_back(pNote);
}

void CGameManager::AddBpmBlock(string sBpm , int nBarNum , double y)
{
	INoteObject * pNote = new CShortNote();
	
	pNote->Init(m_pLayer , D_BPMBLOCK_NUM , y);
	
	pNote->setBarNum(nBarNum);
	pNote->setIndex((int)strtol(sBpm.c_str() , NULL , 10));
	pNote->setBpm((int)strtol(sBpm.c_str() , NULL , 16));
	
	pNote->Create();

	pNote->setPrivateNum(D_BPMBLOCK_NUM);

	m_pNoteManager->m_pNoteTable.push_back(pNote);
}

void CGameManager::AddBitmapBlock(string sBitmapnum , int nBarNum , double y)
{
	INoteObject * pNote = new CShortNote();
	
	pNote->Init(m_pLayer , D_BITMAPBLOCK_NUM , y);
	
	pNote->Create();
	pNote->setBarNum(nBarNum);
	pNote->setIndex((int)strtol(sBitmapnum.c_str() , NULL , 36));
	pNote->setPrivateNum(D_BITMAPBLOCK_NUM);

	string name;
	name = D_ASSET_MNG->getPath();
	name += "/";
	name += D_ASSET_MNG->getBmpDataList()->m_pTable[pNote->getIndex()].sDataTarget;
	name += D_ASSET_MNG->getBmpDataList()->m_pTable[pNote->getIndex()].sExtensionTarget;

	pNote->setTextureName(name);

	m_pNoteManager->m_pNoteTable.push_back(pNote);
}

void CGameManager::AddWaveBlock(string sWavenum , int nBarNum , double y)
{
	INoteObject * pNote = new CShortNote();

	pNote->Init(m_pLayer , D_WAVEBLOCK_NUM , y);
	pNote->Create();

	pNote->setBarNum(nBarNum);
	pNote->setIndex((int)strtol(sWavenum.c_str() , NULL , 36));
	pNote->setPrivateNum(D_WAVEBLOCK_NUM);
	pNote->setSoundNum(D_GAME_MNG->getSongManager()->CreateSound(CreateFullPathData(sWavenum)));

	m_pNoteManager->m_pNoteTable.push_back(pNote);
}

void CGameManager::AddStopBlock(string sWavenum , int nBarNum , double y)
{
	INoteObject * pNote = new CShortNote();

	pNote->Init(m_pLayer , D_STOPBLOCK_NUM , y);
	pNote->Create();

	pNote->setBarNum(nBarNum);
	pNote->setIndex((int)strtol(sWavenum.c_str() , NULL , 10));
	pNote->setPrivateNum(D_STOPBLOCK_NUM);

	m_pNoteManager->m_pNoteTable.push_back(pNote);
}

void CGameManager::AddKeyboardBlock(int nKeyboard , int nBarNum , string sWavNum , double y , bool bVisible)
{
	INoteObject * pNote = new CShortNote();
	int nTempValue = 0;

	switch(nKeyboard)
	{
	case E_KEYBOARD_SIX:
		nTempValue = 7;
		pNote->Init(m_pLayer , 0 , y , bVisible);
		pNote->setColor(E_NOTE_RED);
		break;
	case E_KEYBOARD_ONE:	//!< 흰색 노트
		nTempValue = 0;
		pNote->Init(m_pLayer , 1 , y, bVisible);
		pNote->setColor(E_NOTE_WHITE);
		break;
	case E_KEYBOARD_TWO:	//!< 파란색 노트
		nTempValue = 1;
		pNote->Init(m_pLayer , 2 , y, bVisible);
		pNote->setColor(E_NOTE_BLUE);
		break;
	case E_KEYBOARD_THREE:	//!< 흰색 노트
		nTempValue = 2;
		pNote->Init(m_pLayer , 3 , y, bVisible);
		pNote->setColor(E_NOTE_WHITE);
		break;
	case E_KEYBOARD_FOUR:	//!< 파란색 노트
		nTempValue = 3;
		pNote->Init(m_pLayer , 4 , y, bVisible);
		pNote->setColor(E_NOTE_BLUE);
		break;
	case E_KEYBOARD_FIVE:	//!< 흰색 노트
		nTempValue = 4;
		pNote->Init(m_pLayer , 5 , y, bVisible);
		pNote->setColor(E_NOTE_WHITE);
		break;
	case E_KEYBOARD_EIGHT:
		nTempValue = 5;
		pNote->Init(m_pLayer , 6 , y, bVisible);
		pNote->setColor(E_NOTE_BLUE);
		break;
	case E_KEYBOARD_NINE:
		nTempValue = 6;
		pNote->Init(m_pLayer , 7 , y, bVisible);
		pNote->setColor(E_NOTE_WHITE);
		break;
	}

	pNote->Create();

	pNote->setIndex((int)strtol(sWavNum.c_str() , NULL , 36));
	pNote->setBarNum(nBarNum);
	pNote->setKeyboard(nKeyboard);
	pNote->setPrivateNum(D_KEYBOARD_NUM);
	pNote->setSoundNum(D_GAME_MNG->getSongManager()->CreateSound(CreateFullPathData(sWavNum)));
	
	m_pNoteManager->m_pNoteTable.push_back(pNote);
}

#pragma endregion

void CGameManager::Miss()
{
	if(D_ASSET_MNG->getHP() > 0)
		D_ASSET_MNG->setHP(D_ASSET_MNG->getHP() - 6 );
	else
	{
		if(D_ASSET_MNG->getDieActive())
			D_ASSET_MNG->setGameover(true);
		D_ASSET_MNG->setHP(0);
	}

	D_ASSET_MNG->setJudgementValue(D_ASSET_MNG->getJudgementValue(E_JUDGEMENT_MISS) + 1 , E_JUDGEMENT_MISS);
}

void CGameManager::Bad()
{
	if(D_ASSET_MNG->getHP() > 0)
		D_ASSET_MNG->setHP(D_ASSET_MNG->getHP() - 4);
	else
	{
		if(D_ASSET_MNG->getDieActive())
			D_ASSET_MNG->setGameover(true);
		D_ASSET_MNG->setHP(0);
	}

	D_ASSET_MNG->setJudgementValue(D_ASSET_MNG->getJudgementValue(E_JUDGEMENT_BAD) + 1 , E_JUDGEMENT_BAD);
	D_ASSET_MNG->setCombo(0);
}

void CGameManager::Good()
{
	D_ASSET_MNG->setJudgementValue(D_ASSET_MNG->getJudgementValue(E_JUDGEMENT_GOOD) + 1 , E_JUDGEMENT_GOOD);
	D_ASSET_MNG->setCombo(D_ASSET_MNG->getCombo() + 1);

	if(D_ASSET_MNG->getCombo() >= D_ASSET_MNG->getMaxCombo())
		D_ASSET_MNG->setMaxCombo(D_ASSET_MNG->getCombo());

	D_ASSET_MNG->setScore((D_ASSET_MNG->getScore() + 50) + (D_ASSET_MNG->getCombo()));
}

void CGameManager::Great()
{
	if(D_ASSET_MNG->getHP() < 100)
	{
		float fTemp = (float)D_ASSET_MNG->getTotal() * (1 / (float)D_ASSET_MNG->getTotalNote());
		if(fTemp < 1)
			fTemp = 1.0f;

		D_ASSET_MNG->setHP(D_ASSET_MNG->getHP() + (int)fTemp);
	}
	else
		D_ASSET_MNG->setHP(100);

	D_ASSET_MNG->setJudgementValue(D_ASSET_MNG->getJudgementValue(E_JUDGEMENT_GREAT) + 1 , E_JUDGEMENT_GREAT);
	D_ASSET_MNG->setCombo(D_ASSET_MNG->getCombo() + 1);
	
	if(D_ASSET_MNG->getCombo() >= D_ASSET_MNG->getMaxCombo())
		D_ASSET_MNG->setMaxCombo(D_ASSET_MNG->getCombo());

	D_ASSET_MNG->setScore((D_ASSET_MNG->getScore() + 100) + (D_ASSET_MNG->getCombo()));
}

void CGameManager::Perfect()
{
	if(D_ASSET_MNG->getHP() < 100)
	{
		float fTemp = (float)D_ASSET_MNG->getTotal() * (1 / (float)D_ASSET_MNG->getTotalNote());
		if(fTemp < 1)
			fTemp = 1.0f;

		D_ASSET_MNG->setHP(D_ASSET_MNG->getHP() + (int)fTemp);
	}
	else
		D_ASSET_MNG->setHP(100);

	D_ASSET_MNG->setJudgementValue(D_ASSET_MNG->getJudgementValue(E_JUDGEMENT_PERFECT) + 1 , E_JUDGEMENT_PERFECT);
	D_ASSET_MNG->setCombo(D_ASSET_MNG->getCombo() + 1);
	
	if(D_ASSET_MNG->getCombo() >= D_ASSET_MNG->getMaxCombo())
		D_ASSET_MNG->setMaxCombo(D_ASSET_MNG->getCombo());

	D_ASSET_MNG->setScore((D_ASSET_MNG->getScore() + 200) + (D_ASSET_MNG->getCombo()));
}

#pragma region Path :: 전체 경로 반환 함수
string CGameManager::CreateFullPathData(string sName)
{
	string tempData;
	string tempName;
	string findData;

	findData = D_ASSET_MNG->getWaveDataList()->getTable()[(int)strtol(sName.c_str() , NULL , 36)].sDataTarget;
	//findData = sName;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
	tempName += D_ASSET_MNG->getPath() ;
	tempName += "/";
	tempName += findData;
	tempName += ".ogg";
	tempData = CCFileUtils::sharedFileUtils()->fullPathForFilename(tempName.c_str());

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
	tempData = D_ASSET_MNG->getPath() ;
	tempData += "/";
	tempData += findData;
	tempData += ".ogg";
#endif

	return tempData;
}
#pragma endregion

/**
 @brief : 초기화
 @pLayer : 씬
*/
void CGameManager::Init(CCLayer* pLayer)
{
	//!<================================================================
	//!< 기본 사용 변수
	m_pActive			= true;
	m_pLayer			= pLayer;
	m_fStopTime			= 0.0f;

	//!<================================================================
	//!< 자원관리 매니저 셋팅
	D_ASSET_MNG->Init();
	
	//!< 절대경로 셋팅
	D_ASSET_MNG->setPath("songs/kronos");//setPath("songs/sakuzyo_vallista_ogg");//setPath("songs/Akasagarbha_ogg");//setPath("songs/crystal-world_r_ogg");//setPath("songs/[sasakuration]AVALON(MQ)");//setPath("songs/[BOF2013]-+[ColorTeller]");//setPath("songs/kronos");//setPath("songs/void - Valedict");//
	
	//!< Song 로드
	m_pSongManager = new CSongManager();
	m_pSongManager->Init();

	D_ASSET_MNG->setEffectNum(E_EFFECT_CLEAR , m_pSongManager->CreateSound("Sounds/claer.ogg"));
	D_ASSET_MNG->setEffectNum(E_EFFECT_FAIL , m_pSongManager->CreateSound("Sounds/fail.ogg"));
	D_ASSET_MNG->setEffectNum(E_EFFECT_SPEED , m_pSongManager->CreateSound("Sounds/o-change.ogg"));

	//!< 노트 데이터 로드
	m_pNoteManager = new CNoteManager();
	m_pNoteManager->Init(pLayer);
	
	//!< 마디 매니저 셋팅pppp
	m_pBarManager = new CBarManager();
	m_pBarManager->Init();

	//!< BMS 파일 로드
	m_pLoadBmsData = new CBMSParser();
	m_pLoadBmsData->Init(pLayer);
	m_pLoadBmsData->Parse("songs/kronos/kronos_normal.bms"); //Parse("songs/sakuzyo_vallista_ogg/vallista_normal.bms");//Parse("songs/Akasagarbha_ogg/_akasagarbha_7h.bme");//Parse("songs/crystal-world_r_ogg/_crystal-world_r_7h.bme");//Parse("songs/[sasakuration]AVALON(MQ)/02_avalon[7key].bme");//Parse("songs/[BOF2013]-+[ColorTeller]/-+_H.bme");//

	D_UI_MNG->Init(m_pLayer);
	//!<================================================================
	
	//!< 쓸모없는 vector 제거
	VectorUnlock();
}

/**
 @brief : 업데이트
 @dt : delay time
*/
void CGameManager::Update(float dt)
{
	//!< UI 업데이트
	D_UI_MNG->Update(dt);

	if(!m_pActive) return;

	if(D_ASSET_MNG->getGameover()) {m_pSongManager->AllStop(); D_GAME_MNG->getSongManager()->Play(D_ASSET_MNG->getEffectNum(E_EFFECT_FAIL)); m_pActive = false;  return; }
	if(D_ASSET_MNG->getGameclear()) {D_GAME_MNG->getSongManager()->Play(D_ASSET_MNG->getEffectNum(E_EFFECT_CLEAR)); m_pActive = false;  return; }

	//!< 게임 플레이 시간
	m_fGameTime += dt;
	
	//!< 노래 업데이트
	m_pSongManager->Update(dt);
	//!< 노트 업데이트
	m_pNoteManager->Update(dt);
	//!< 마디 감속 , 증속 이벤트
	UpdateStopNode(dt);
}

/**
 @brief : 노트 정지 시간
 @dt : delay time
*/
void CGameManager::UpdateStopNode(float dt)
{
	if(D_ASSET_MNG->getJointValue() == -1) return;
	m_fStopTime += dt;
	//double dBarperSecond = ((4 * 60) / D_ASSET_MNG->getBPM()) * D_ASSET_MNG->getJointMul();

	if(m_fStopTime >= D_ASSET_MNG->getStopTime())
	{
		m_fStopTime = 0.0;
		D_ASSET_MNG->setJointValue(-1);
	}
}

/**
 @brief : 삭제 함수
*/
void CGameManager::Destroy()
{
	//VectorUnlock();
	CC_SAFE_DELETE(m_pLoadBmsData);
	m_pNoteManager->Destroy();
	CC_SAFE_DELETE(m_pNoteManager);
	m_pBarManager->Destroy();
	CC_SAFE_DELETE(m_pBarManager);
	m_pSongManager->Destroy();
	CC_SAFE_DELETE(m_pSongManager);
	//D_UI_MNG->Destroy();
	D_ASSET_MNG->Destroy();
}

/**
 @brief : 백터값 삭제
*/
void CGameManager::VectorUnlock()
{
	D_ASSET_MNG->Destroy();
}

/**
 @brief : 터치 다운
 @pos : 위치
*/
void CGameManager::TouchDown(CCPoint pos)
{
	//m_pActive = !m_pActive;

	if(!m_pActive) return;
	
	//for(int i = 0 ; i < 7 ; i++)
	//	m_pNote[i]->Touch(ccp(0,0));
}

/**
 @brief : 터치 이동
 @pos : 위치
*/
void CGameManager::TouchMove(CCPoint pos)
{
	if(!m_pActive) return;
	
	//for(int i = 0 ; i < 7 ; i++)
	//	m_pNote[i]->Move(ccp(0,0));
}

/**
 @brief : 터치 업
 @pos : 위치
*/
void CGameManager::TouchUp(CCPoint pos)
{
	if(!m_pActive) return;
	
	//for(int i = 0 ; i < 7 ; i++)
	//	m_pNote[i]->Die(ccp(0,0));
}

#pragma region get :: 가져오는 메소드들
/**
 @brief : 노트매니저 가져옴
*/
CNoteManager* CGameManager::getNoteManager()
{
	return m_pNoteManager;
}

/**
 @brief : Bar 매니저 가져옴
*/
CBarManager* CGameManager::getBarManager()
{
	return m_pBarManager;
}

/**
 @brief : Song 매니저 가져옴
*/
CSongManager* CGameManager::getSongManager()
{
	return m_pSongManager;
}
#pragma endregion