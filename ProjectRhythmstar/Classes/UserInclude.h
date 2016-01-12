#pragma once

#include "cocos2d.h"

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <vector>
#include <map>

using namespace std;
USING_NS_CC;

////////////////////////////////////////////////////
//!< Cocos2d-x 라이브러리
//#include "SimpleAudioEngine.h"		//!< 음악 추가 시키는 헤더

////////////////////////////////////////////////////
//!< 외부 라이브러리
#include "../fmod/inc/fmod.hpp"			//!< fmod 사운드 헤더
#include "../fmod/inc/fmod_errors.h"
#pragma comment (lib, "../fmod/fmodex_vc.lib")		//!< fmod 사운드 라이브러리 추가
#pragma comment (lib, "../fmod/fmodex64_vc.lib")	//!< fmod 사운드 라이브러리 추가

using namespace FMOD;

////////////////////////////////////////////////////
//!< 동영상 재생 라이브러리 FFMPEG
// 
//#define inline __inline  
//
////#ifdef __cplusplus
//extern "C" {
////#endif
//
//#include <libavcodec/avcodec.h>
//#include <libavfilter/avfilter.h>
//#include <libavformat/avformat.h>
//#include <libavdevice/avdevice.h>
//#include <libavutil/avutil.h>
//#include <libswresample/swresample.h>
//#include <libswscale/swscale.h>
//
////#ifdef __cplusplus
//};
////#endif 
//
//#pragma comment(lib, "avcodec.lib")
//#pragma comment(lib, "avdevice.lib")
//#pragma comment(lib, "avfilter.lib")
//#pragma comment(lib, "avformat.lib")
//#pragma comment(lib, "avutil.lib")
//#pragma comment(lib, "swresample.lib")
//#pragma comment(lib, "swscale.lib")
////////////////////////////////////////////////////
//!< 사용자 생성 라이브러리
#include "cGHAnimation.h"
#include "CNumber.h"
#include "CInput.h"

////////////////////////////////////////////////////
//!< 제일 최상위 루트
#include "iGameObject.h"

//!< 사용자 생성 오브젝트
#include "CBMSParser.h"			//!< BMS 관련 데이터 리스트 클래스
#include "IFormatList.h"		//!< 포멧 리스트
#include "CBmpDataList.h"		//!< 이미지 데이터 리스트 클래스
#include "CWaveDataList.h"		//!< 웨이브 데이터 리스트 클래스
#include "CNoteDataList.h"		//!< 노트 데이터 리스트 클래스
#include "CKey.h"				//!< 키 관련 메서드
#include "CBar.h"				//!< 노트 생성을 위한 바
#include "CEffect.h"			//!< 이펙트

//!< UI
#include "iUI.h"				//!< UI interface
#include "iPopup.h"				//!< 팝업 인것들
#include "iNoPopup.h"			//!< 팝업 아닌것들

////////////////////////////////////////////////////
//!< 노트 관련

#include "INoteState.h"			//!< 노트 상태 최상위 클래스
#include "CState_Move.h"		//!< 노트가 움직일 때 적용되는 클래스
#include "CState_Touch.h"		//!< 노트가 Touch 상태일때 적용되는 클래스
#include "CState_Die.h"			//!< 노트가 죽을 때 적용되는 클래스

#include "INoteObject.h"

#include "CShortNote.h"			//!< CNoteObject 상속
#include "CLongNote.h"			//!< CNoteObject 상속

////////////////////////////////////////////////////
//!< UI 관련
#include "CVideo.h"				//!< 비디오 출력
#include "CJudge.h"				//!< 판정선
#include "CBarLine.h"			//!< 마디 라인선
#include "CMenuItem.h"			//!< 전체적인 메뉴
#include "CKeyboard.h"			//!< 키보드
#include "CShowJudge.h"			//!< 판정 보여주는 클래스
#include "CGameOver.h"			//!< 게임 오버
#include "CFont.h"				//!< 폰트
#include "CBackGround.h"		//!< 뒷배경

////////////////////////////////////////////////////
//!< 사용자 생성 매니저
#include "CNoteManager.h"		//!< 노트 관련 메소드 관리
#include "CBarManager.h"		//!< 노트 생성시 필요한 Bar 관련 메소드 관리
#include "CAssetManager.h"		//!< 자원 관리
#include "CSurportManager.h"	//!< 서포트 관련 관리 (씬 전환이라던지)
#include "CSongManager.h"		//!< 음악 관리
#include "CUIManager.h"			//!< UI 관리
#include "CGameManager.h"		//!< 게임 전체 관리

////////////////////////////////////////////////////
//!< 메인
#include "AppDelegate.h"

////////////////////////////////////////////////////
//!< 씬 등록
#include "CMenu.h"
#include "CGame.h"
