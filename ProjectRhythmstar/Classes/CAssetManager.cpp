#include "stdafx.h"

/**
 @brief : 초기화
*/
void CAssetManager::Init()
{
	memset(m_sGenre		, NULL , 256);
	memset(m_sTitle		, NULL , 256);
	memset(m_sArtist	, NULL , 256);
	memset(m_sMidifile	, NULL , 256);
	memset(m_sStageFile	, NULL , 256);
	memset(m_sVideoFile , NULL , 256);
	memset(m_sSubArtist , NULL , 256);
	memset(m_sBanner	, NULL , 256);

	m_nPlayer			= 0;
	m_dJointMul			= 1.0;
	m_nPlayerLevel		= 0;	
	m_nRank				= 0;		
	m_nTotal			= 0;
	m_nTotalNote		= 0;
	m_nNowNote			= 0;
	m_nVolWav			= 0;	
	m_nJointValue		= -1;
	m_nHP				= 20;
	m_fAttachment		= 1.0f;
	m_nNowNode			= 0;
	m_fDelayTime		= 0.0f;
	m_fFPS				= 0.0f;

	m_stJudgement.fPerfect[E_JUDGEMENT_MAX] = 0.18f;
	m_stJudgement.fPerfect[E_JUDGEMENT_MIN] = -0.18f;

	m_stJudgement.fGreat[E_JUDGEMENT_MAX] = 0.24f;
	m_stJudgement.fGreat[E_JUDGEMENT_MIN] = -0.24f;
	
	m_stJudgement.fGood[E_JUDGEMENT_MAX] = 0.34f;
	m_stJudgement.fGood[E_JUDGEMENT_MIN] = -0.34f;
	
	m_stJudgement.fBad[E_JUDGEMENT_MAX] = 0.44f;
	m_stJudgement.fBad[E_JUDGEMENT_MIN] = -0.44f;
	
	m_stJudgement.fMiss[E_JUDGEMENT_MAX] = 0.44f;
	m_stJudgement.fMiss[E_JUDGEMENT_MIN] = -0.44f;

	m_nCombo			= 0;
	m_nMaxCombo			= 0;
	m_dBpm				= 0;
	m_nScore			= 0;

	m_bCDRotate			= false;
	m_bGameOver			= false;
	m_bGameClear		= false;
	m_bDieActive		= false;

	m_pWaveDataList		= new CWaveDataList();
	m_pNoteDataList		= new CNoteDataList();
	m_pBmpDataList		= new CBmpDataList();

	for(int i = 0 ; i < E_JUDGEMENT_TYPE_MAX ; i++) m_nJudgementValue[i] = 0;
	for(int i = 0 ; i < E_EFFECT_MAX ; i++) m_nEffect[i] = 0;
}

/**
 @brief : 삭제
*/
void CAssetManager::Destroy()
{
	CC_SAFE_DELETE(m_pWaveDataList);
	CC_SAFE_DELETE(m_pNoteDataList);
	CC_SAFE_DELETE(m_pBmpDataList);
}

#pragma region Setting :: 한번에 묶어버리는 구문 입니다.
/**
 @brief : 셋팅
 @player : 플레이어 값
 @genre : 장르
 @title : 타이틀 이미지
 @artist : 아티스트
 @bpm : bpm
 @playLevel : 난이도
 @rank : 난이도
 @volwav : 모름
 @stagefile : 모름
 @total : 판정값
 @midifile : 동영상 관련 파일들
 @vidiofile : 비디오 파일
 @subartist : 서브 아티스트
 @banner : 배너 이미지
 @difficulty : 난이도 관련
*/
void CAssetManager::Setting(char * player , char * genre , char * title , char * artist , char * bpm
		, char * playLevel , char * rank , char * volwav , char * stagefile , char * total
		, char * midifile , char * vidiofile , char * subartist , char * banner , char * difficulty)
{
	setPlayer(player);
	setGenre(genre);
	setTitle(title);
	setArtist(artist);
	setBPM(bpm);
	setPlayerLevel(playLevel);
	setRank(rank);
	setVolwav(volwav);
	setStageFile(stagefile);
	setTotal(total);
	setMidifile(midifile);
	setVideoFile(vidiofile);
	setSubArtist(subartist);
	setBanner(banner);
	setDifficulty(difficulty);
}
#pragma endregion

#pragma region Set :: 설정 구문들 입니다.

void CAssetManager::setEffectNum(int i , int value)
{
	m_nEffect[i] = value;
}

void CAssetManager::setJudgementValue(int i , E_JUDGEMENT_TYPE eType)
{
	m_nJudgementValue[eType] = i;
}

void CAssetManager::setPlayer(char* temp)
{
	if(temp == NULL) return;

	m_nPlayer = atoi(temp);
}

void CAssetManager::setPlayerLevel(char* temp)
{
	if(temp == NULL) return;

	m_nPlayerLevel = atoi(temp);
}

void CAssetManager::setRank(char* temp)
{
	if(temp == NULL) return;

	m_nRank = atoi(temp);
}

void CAssetManager::setTotal(char* temp)
{
	if(temp == NULL) return;

	m_nTotal = atoi(temp);
}

void CAssetManager::setVolwav(char* temp)
{
	if(temp == NULL) return;

	m_nVolWav = atoi(temp);
}

void CAssetManager::setDifficulty(char* data)
{
	if(data == NULL) return;

	m_nDifficulty = atoi(data);
}

void CAssetManager::setBPM(char* temp)
{
	if(temp == NULL) return;

	m_dBpm = atof(temp);
}

void CAssetManager::setGenre(char* data)
{
	if(data == NULL) return;

	memset(m_sGenre , NULL , 256);
	sprintf(m_sGenre , "%s" , data);
}

void CAssetManager::setTitle(char* data)
{
	if(data == NULL) return;
	
	memset(m_sTitle , NULL , 256);
	sprintf(m_sTitle , "%s" , data);
}

void CAssetManager::setArtist(char* data)
{
	if(data == NULL) return;
	
	memset(m_sArtist , NULL , 256);
	sprintf(m_sArtist , "%s" , data);
}

void CAssetManager::setMidifile(char* data)
{
	if(data == NULL) return;
	
	memset(m_sMidifile , NULL , 256);
	sprintf(m_sMidifile , "%s" , data);
}

void CAssetManager::setStageFile(char* data)
{
	if(data == NULL) return;
	
	memset(m_sStageFile , NULL , 256);
	sprintf(m_sStageFile , "%s" , data);
}

void CAssetManager::setVideoFile(char* data)
{
	if(data == NULL) return;
	
	memset(m_sVideoFile , NULL , 256);
	sprintf(m_sVideoFile , "%s" , data);
}

void CAssetManager::setSubArtist(char* data)
{
	if(data == NULL) return;
	
	memset(m_sSubArtist , NULL , 256);
	sprintf(m_sSubArtist , "%s" , data);
}

void CAssetManager::setBanner(char* data)
{
	if(data == NULL) return;

	memset(m_sBanner , NULL , 256);
	sprintf(m_sBanner , "%s" , data);
}

#pragma endregion

#pragma region Get :: 가져오는 함수

int CAssetManager::getEffectNum(int i)
{
	return m_nEffect[i];
}

int CAssetManager::getJudgementValue(int i)
{
	return m_nJudgementValue[i];
}

int CAssetManager::getPlayer()
{
	return m_nPlayer;
}

int CAssetManager::getVolwav()
{
	return m_nVolWav;
}

int CAssetManager::getPlayerLevel()
{
	return m_nPlayerLevel;
}

int CAssetManager::getRank()
{
	return m_nRank;
}

int CAssetManager::getDifficulty()
{
	return m_nDifficulty;
}

int CAssetManager::getTotal()
{
	return m_nTotal;
}

double CAssetManager::getBPM()
{
	return m_dBpm;
}

char* CAssetManager::getGenre()
{
	return m_sGenre;
}

char* CAssetManager::getTitle()
{
	return m_sTitle;
}

char* CAssetManager::getArtist()
{
	return m_sArtist;
}

char* CAssetManager::getMidifile()
{
	return m_sMidifile;
}

char* CAssetManager::getStageFile()
{
	return m_sStageFile;
}

char* CAssetManager::getVideoFile()
{
	return m_sVideoFile;
}

char* CAssetManager::getSubArtist()
{
	return m_sSubArtist;
}

char* CAssetManager::getBanner()
{
	return m_sBanner;
}

CWaveDataList* CAssetManager::getWaveDataList()
{
	return m_pWaveDataList;
}

CNoteDataList* CAssetManager::getNoteDataList()
{
	return m_pNoteDataList;
}

CBmpDataList* CAssetManager::getBmpDataList()
{
	return m_pBmpDataList;
}
#pragma endregion