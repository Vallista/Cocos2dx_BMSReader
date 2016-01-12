#include "stdafx.h"

#pragma region Change Scene :: 씬 전환하는 구문 입니다.
/**
 @brief : 씬 전환 구문
 @sceneType : 씬 전환 타입
 @type : 타입
 @pTargetScene : 타겟 씬
 @fChangeTime : 전환 시간
*/
void CSurportManager::ChangeScene(E_CHANGE_SCENE sceneType , E_SCENE_TYPE type, CCScene* pTargetScene , float fChangeTime)
{
	CCScene* pScene = NULL;

	switch(sceneType)
	{
	case E_CHANGE_CROSSFADE:
		pScene = CCTransitionCrossFade::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FADE:
		pScene = CCTransitionFade::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FADEBL:
		pScene = CCTransitionFadeBL::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FADEDOWN:
		pScene = CCTransitionFadeDown::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FADETR:
		pScene = CCTransitionFadeTR::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FLIPANGULAR:
		pScene = CCTransitionFlipAngular::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FLIPX:
		pScene = CCTransitionFlipX::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_FLIPY:
		pScene = CCTransitionFlipY::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_JUMPZOOM:
		pScene = CCTransitionJumpZoom::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_MOVEINB:
		pScene = CCTransitionMoveInB::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_MOVEINL:
		pScene = CCTransitionMoveInL::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_MOVEINR:
		pScene = CCTransitionMoveInR::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_MOVEINT:
		pScene = CCTransitionMoveInT::create(fChangeTime, pTargetScene);
		break;

	case E_CHANGE_PAGETURN:
		pScene = CCTransitionPageTurn::create(fChangeTime, pTargetScene , false);
		break;
	case E_CHANGE_ROTOZOOM:
		pScene = CCTransitionRotoZoom::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_SLIDEINB:
		pScene = CCTransitionSlideInR::create(fChangeTime, pTargetScene);
		break;

	case E_CHANGE_SLIDEINL:
		pScene = CCTransitionSlideInL::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_SLIDEINR:
		pScene = CCTransitionSlideInR::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_SLIDEINT:
		pScene = CCTransitionSlideInT::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_ZOOMFLIPX:
		pScene = CCTransitionZoomFlipX::create(fChangeTime, pTargetScene);
		break;
	case E_CHANGE_ZOOMFLIPY:
		pScene = CCTransitionZoomFlipY::create(fChangeTime, pTargetScene);
		break;
	}

	if(type == E_REPLACE_SCENE)
		CCDirector::sharedDirector()->replaceScene(pScene);
	else
		CCDirector::sharedDirector()->pushScene(pScene);
}
#pragma endregion

#pragma region Split :: 문자열 Split 입니다.
/**
 @brief : 문자열을 잘라주는 함수입니다. (에러 있음 사용하지 않는거 권장)
 @strOrigin : 자를 데이터
 @strTok : 분기줄 데이터
 @string : 반환형 , 배열로 인자전달
*/
string* CSurportManager::StringSplit(string strOrigin, string strTok)
{
	int     cutAt;                            //자르는위치
	int     index     = 0;                    //문자열인덱스
	string* strResult = new string[D_MAX_ARRAY_SIZE];  //결과return 할변수

	//strTok을찾을때까지반복
	while ((cutAt = strOrigin.find_first_of(strTok)) != strOrigin.npos)
	{
		if (cutAt > 0)  //자르는위치가0보다크면(성공시)
		{
			strResult[index++] = strOrigin.substr(0, cutAt);  //결과배열에추가
		}
		strOrigin = strOrigin.substr(cutAt+1);  //원본은자른부분제외한나머지
	}

	if(strOrigin.length() > 0)  //원본이아직남았으면
	{
		strResult[index++] = strOrigin.substr(0, cutAt);  //나머지를결과배열에추가
	}

	return strResult;  //결과return
}
#pragma endregion