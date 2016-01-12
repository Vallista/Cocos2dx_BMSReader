#include "stdafx.h"

#pragma region 생성자 / 초기화 :: 생성자 초기화 부분입니다.
/**
 @brief : 생성자
*/
CBMSParser::CBMSParser()
{

}

/**
 @brief : 소멸자
*/
CBMSParser::~CBMSParser()
{

}
#pragma endregion

#pragma region Init :: 초기화 합니다.
/**
 @brief : 초기화
 @pLayer : 해당 씬의 정보
*/
void CBMSParser::Init(CCLayer* pLayer)
{
	m_pLayer				= pLayer;

	m_pFileUtill			= CCFileUtils::sharedFileUtils();

	m_nTotalCount			= 0;
	m_nTotalWav				= 0;
	m_nTotalBmp				= 0;
	m_nTotalNote			= 0;
}
#pragma endregion

#pragma region Parsing :: 데이터들을 파싱합니다.
/**
 @brief : 전체 불러오고 나서 데이터를 파싱합니다.
 @strFilePath : 전체 문자열
*/
void CBMSParser::Parse(char* strFilePath)
{	
	m_strFilePath			= strFilePath;
	m_pFileData				= (char*)m_pFileUtill->getFileData(m_strFilePath , "r" , &m_BufferSize); 

	while( m_nTotalCount < m_BufferSize)
	{ 
		LoadLine(m_pFileData);

		m_nTotalCount++;
	}

	D_ASSET_MNG->Setting(m_BmsInfo.cPlayer , m_BmsInfo.cGenre , m_BmsInfo.cTitle , m_BmsInfo.cArtist
		, m_BmsInfo.cBpm , m_BmsInfo.cPlaylevel , m_BmsInfo.cRank , m_BmsInfo.cVolwav , m_BmsInfo.cStagefile
		, m_BmsInfo.cTotal , m_BmsInfo.cMidifile , m_BmsInfo.cVideofile , m_BmsInfo.cSubartist , m_BmsInfo.cBanner , m_BmsInfo.cDifficulty);

	D_ASSET_MNG->setTotalNote(m_nTotalNote);

#pragma region 디버그시 콘솔에 현재 곡 정보 띄우는 메서드
#ifdef DEBUG
	CCLog("Player       : %d" , D_ASSET_MNG->getPlayer());
	CCLog("Genre        : %s" , D_ASSET_MNG->getGenre());
	CCLog("Title        : %s" , D_ASSET_MNG->getTitle());
	CCLog("Artist       : %s" , D_ASSET_MNG->getArtist());
	CCLog("BPM          : %f" , D_ASSET_MNG->getBPM());
	CCLog("Playlevel    : %d" , D_ASSET_MNG->getPlayerLevel());
	CCLog("Rank         : %d" , D_ASSET_MNG->getRank());
	CCLog("Volwav       : %d" , D_ASSET_MNG->getVolwav());
	CCLog("StageFile    : %s" , D_ASSET_MNG->getStageFile());
	CCLog("Total        : %d" , D_ASSET_MNG->getTotal());
	CCLog("Midifile     : %s" , D_ASSET_MNG->getMidifile());
	CCLog("VideoFile    : %s" , D_ASSET_MNG->getVideoFile());
	CCLog("SubArtist    : %s" , D_ASSET_MNG->getSubArtist());
	CCLog("Banner       : %s" , D_ASSET_MNG->getBanner());
	CCLog("Total Wave   : %d" , m_nTotalWav);
	CCLog("Total Bmp    : %d" , m_nTotalBmp);
	CCLog("Total Note   : %d" , m_nTotalNote);
#endif
	#pragma endregion
}
#pragma endregion

#pragma region LoadLine :: 라인을 읽어옵니다.
/**
 @brief : 모든 문자열을 불러오고 나서 해당 문자열을 한줄씩 잘라주는 함수 입니다.
 @data : 전체 문자열 데이터
 @info : 한줄씩 읽어오는 메소드
*/
void CBMSParser::LoadLine(string data)
{
	int nCount = 0;
	char cTemp[D_MAX_ARRAY_SIZE];
	memset(cTemp , NULL , D_MAX_ARRAY_SIZE);

	if(data[m_nTotalCount] == '#')
	{ 
		while( data[m_nTotalCount] != '\\' && data[m_nTotalCount] != '\n')
		{
			cTemp[nCount] = data[m_nTotalCount];

			m_nTotalCount++;
			nCount ++;
		}
		
		m_sLineData = cTemp;

		m_nThisCount = nCount;
		Process(cTemp);
	}
}
#pragma endregion

#pragma region CutString :: 문자열을 자르는 구문 들 입니다.
/**
 @brief : 문자열을 가져와서 자릅니다
 @data : 문자열 데이터
 @target : 문자열을 자를 첫번째 구문자
 @subTarget : 두번째 자를 구분자
 @string : 반환형, 배열을 구분으로 자른 데이터를 전송합니다.
 @info : 이 함수는 최초 한번만 자르고 그 후부터는 target 이나 subTarget에 대응하는 문자열 안짜릅니다.
  기존에 CSurportManager에 SPlit을 만들어 놓은게 있으나 버그가 있어서 새로 만들었습니다. 쿨럭
*/
string* CBMSParser::CutString(string data , char *target)
{
	int nCount = 0;		//!< 맨끝까지 읽었는지 확인할 변수
	bool bChk = false;	//!< 중복체크
	string * tempData = new string[2];	//!< 던질 데이터
	
	while (nCount <= data.length())	//!< 문자열 길이만큼
	{
		if(bChk == false && data[nCount] == *target) { nCount ++; bChk = true; } //!< 중복되면 처리
			
		if(bChk)
			tempData[1] += data[nCount];	//!< 중복됐으면 그 이후부터는 무조껀 2번째에 다 들어감
		else
			tempData[0] += data[nCount];

		nCount ++;
	}

	return tempData;
}

/**
 @brief : 문자열을 가져와서 자릅니다
 @data : 문자열 데이터
 @target : 문자열을 자를 첫번째 구문자
 @subTarget : 두번째 자를 구분자
 @string : 반환형, 배열을 구분으로 자른 데이터를 전송합니다.
 @info : 이 함수는 최초 한번만 자르고 그 후부터는 target 이나 subTarget에 대응하는 문자열 안짜릅니다.
  기존에 CSurportManager에 SPlit을 만들어 놓은게 있으나 버그가 있어서 새로 만들었습니다. 쿨럭
*/
string* CBMSParser::CutString(string data , char *target , char * subTarget)
{
	int nCount = 0;
	bool bChk[2] = {false , false};
	string * tempData = new string[3];
	
	while (nCount <= data.length())
	{
		if(bChk[0] == false && data[nCount] == *target) { nCount ++; bChk[0] = true; }
		if(bChk[0] == true && data[nCount] == *subTarget) { bChk[1] = true; }
			
		if(bChk[0] && !bChk[1])
			tempData[1] += data[nCount];
		else if(!bChk[0] && !bChk[1])
			tempData[0] += data[nCount];
		else if(bChk[0] && bChk[1])
			tempData[2] += data[nCount];

		nCount ++;
	}

	return tempData;
}
#pragma endregion

#pragma region Process :: 핵심적인 프로세스 부분 입니다.
/**
 @brief : 줄마다 데이터를 읽어들여 줄 타입에 맞는 셋팅을 유도합니다.
 @name : 줄의 문자열을 가져옵니다.
 @info : 핵심 프로세스 입니다.
*/
void CBMSParser::Process(string name)
{
	//!< 해당줄에 시작이 #인지 확인 
	//!< 시작이 # 아니면 다음줄로
	if(name[0] != '#') return;

	//!< 문자열 자릅니다.
	string * sTempData = CutString(name , " ");

	/////////////////////////////////////////////////////////////////
	//!< 해당 데이터들 가져오는 부분 핵심
	if(sTempData[0] == "#PLAYER")
		sprintf(m_BmsInfo.cPlayer , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#GENRE")
		sprintf(m_BmsInfo.cGenre , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#TITLE")
		sprintf(m_BmsInfo.cTitle , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#ARTIST")
		sprintf(m_BmsInfo.cArtist , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#BPM")
		sprintf(m_BmsInfo.cBpm , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#PLAYLEVEL")
		sprintf(m_BmsInfo.cPlaylevel , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#RANK")
		sprintf(m_BmsInfo.cRank , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#VOLWAV")
		sprintf(m_BmsInfo.cVolwav , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#STAGEFILE")
		sprintf(m_BmsInfo.cStagefile , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#TOTAL")
		sprintf(m_BmsInfo.cTotal , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#MIDIFILE")
		sprintf(m_BmsInfo.cMidifile , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#VIDEOFILE")
		sprintf(m_BmsInfo.cVideofile , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#SUBARTIST")
		sprintf(m_BmsInfo.cSubartist , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#BANNER")
		sprintf(m_BmsInfo.cBanner , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#DIFFICULTY")
		sprintf(m_BmsInfo.cDifficulty , "%s" , sTempData[1].c_str());
	else if(sTempData[0] == "#BACKBMP")
		sprintf(m_BmsInfo.cBackBmp , "%s" , sTempData[1].c_str());

	else //!< 이외 나머지는 따로 더 추가를 해주어야할게 있는 것들
	{
		
#pragma region WAVFILE :: 웨이브 파일 읽는 구문 입니다.
		//!< 웨이브 파일 데이터 읽습니다.
		if(sTempData[0].substr(0,4) == "#WAV")
		{
			__ST_BMSINFO_RETUNE info;

			//!< 구간 두개로 자릅니다.
			//!< 이유는 #WAV0U uptec - Marker #59.wav 이러한 형식으로 되어있기 때문에 
			//!< #WAVOU // uptec - Marker #59 //.wav 이렇게 잘라버립니다.
			//!< 그리고 또 substr로 문자열을 잘라버립니다.
			//!< #WAVOU 에서 OU가 해당 wav의 번호이기 때문입니다. 

			string * sTempData = CutString(name , " " , ".");

			//!< 웨이브 파일 번호
			info.nNameTarget = (int)strtol(sTempData[0].substr(4,2).c_str() , NULL , 36);
			//!< 파일이름
			sprintf(info.sDataTarget , "%s" , sTempData[1].c_str());
			//!< 확장자
			sprintf(info.sExtensionTarget , "%s" , sTempData[2].c_str());

			D_ASSET_MNG->getWaveDataList()->addData(info);

			m_nTotalWav++;
		}
#pragma endregion
#pragma region BMPFILE :: BMP 파일 읽는 구문 입니다.
		//!< 뒷배경에서 돌려줄 동영상 입니다.
		else if(sTempData[0].substr(0,4) == "#BMP")
		{
			//!< 구간 두개로 자릅니다.
			//!< 이유는 #WAV0U uptec - Marker #59.wav 이러한 형식으로 되어있기 때문에 
			//!< #WAVOU // uptec - Marker #59 //.wav 이렇게 잘라버립니다.
			//!< 그리고 또 substr로 문자열을 잘라버립니다.
			//!< #WAVOU 에서 OU가 해당 wav의 번호이기 때문입니다. 

			__ST_BMSINFO_RETUNE info;

			string * sTempData = CutString(name , " " , ".");

			//!< BMP 파일 번호
			info.nNameTarget = (int)strtol(sTempData[0].substr(4,2).c_str() , NULL , 36);
			//!< 파일이름
			sprintf(info.sDataTarget , "%s" , sTempData[1].c_str());
			//!< 확장자
			sprintf(info.sExtensionTarget , "%s" , sTempData[2].c_str()); 

			D_ASSET_MNG->getBmpDataList()->m_pTable.insert(map<int , __ST_BMSINFO_RETUNE>::value_type(info.nNameTarget , info));

			//D_ASSET_MNG->getBmpDataList()->getTable()[info.nNameTarget].nNameTarget = info.nNameTarget;//->addData(info);
			//sprintf(D_ASSET_MNG->getBmpDataList()->getTable()[info.nNameTarget].sDataTarget , "%s" , info.sDataTarget);
			//sprintf(D_ASSET_MNG->getBmpDataList()->getTable()[info.nNameTarget].sExtensionTarget , "%s" , info.sExtensionTarget);

			m_nTotalBmp++;
		}
#pragma endregion
#pragma region NOTEFILE :: 노트데이터 읽는 구문 입니다.
		//!< 그외의 데이터면 노트 데이터 입니다.
		else
		{
			//!< 노트데이터는 #06718:0000CT0000CW008N000000000000008O 이러한 형식으로 되어있습니다.
			//!< 해당 데이터의 구분은 # 이후로 이루어 지며 # 이후 3개 , 그 이후 1개로 되어있고
			//!< 각각 Bar 번호 , 채널번호 로 나누어지며 채널번호에서 첫번째 인자가 1이면 건반채널,
			//!< 0이면 채널 로직입니다.
			__ST_BMSDATA_RETURN data;

			string * sTempData = CutString(name , ":");

			//!< 전부 인트형으로 한번 걸러주어야 합니다.
			//!< Bar의 번호 가져옮
			data.nNodeNumber = GetBarNum(sTempData[0]);
			//!< 채널 앞번호 가져옵니다.
			data.nChannelFirstValue = GetChannelFirst(sTempData[0]);
			//!< 채널 뒷번호 가져옵니다.
			data.nChannelSecondValue = GetChannelSecond(sTempData[0]);

			//!< 데이터 가져옵니다.
			//!< #03101:2947294712471247 설명하면
			//!< Bar 번호가 31번이고 채널 앞번호가 0번 , 뒷번호가 1번이므로 배경음을 뜻하는 블록입니다.
			//!< : (콜론) 이후의 data 들은 어떻게 출력되는지를 조정합니다.

			//!< 해당 데이터를 꾸겨넣습니다.
			sprintf(data.sData , "%s" , sTempData[1].c_str());
			
			D_GAME_MNG->getBarManager()->AddBar(data.nNodeNumber , data.nChannelFirstValue , data.nChannelSecondValue , data.sData);

			if(data.nChannelFirstValue == 1)
				m_nTotalNote++;
		}
#pragma endregion
	}
}

#pragma endregion

#pragma region PrivateFunc :: 내부 함수
int CBMSParser::GetBarNum(string data)
{
	return atoi(data.substr(1,3).c_str());
}

int CBMSParser::GetChannelFirst(string data)
{
	return atoi(data.substr(4,1).c_str());
}

int CBMSParser::GetChannelSecond(string data)
{
	return atoi(data.substr(5,1).c_str());
}
#pragma endregion