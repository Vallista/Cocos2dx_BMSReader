#include "stdafx.h"

/**
@brief : 생성자
*/
CShortNote::CShortNote()
{

}

/**
@brief : 소멸자
*/
CShortNote::~CShortNote()
{
	//Destroy();
}

/**
@brief : 상태 변경
@state : 상태 값
*/
void CShortNote::ChangeState(E_NOTE_STATE state)
{
	ChangeState(m_pState_Pool[state]);
}

/**
@brief : 상태 변경
@pState : 변경할 상태 클래스
*/
void CShortNote::ChangeState( INoteState * pState )
{
	m_pState = pState;
}

/**
@brief : 초기화
@pLayer : 씬의 값
@nNotePos : 노트의 X 위치
@dY : 노트의 Y 위치
*/
void CShortNote::Init(CCLayer* pLayer , int nNotePos , double dY , bool bVisible)
{
	m_pLayer			= pLayer;
	m_bActive			= false;
	m_bSong				= false;
	m_bMiss				= false;
	m_bVisibleNote		= bVisible;

	m_nBarNum			= 0;
	m_nIndex			= 0;
	m_nKeyboard			= 0;
	m_nNotePos			= 0;
	m_nPrivateNumber	= 0;
	m_nSoundNum			= 0;
	m_fBpm				= 0.0f;
	m_fCanselTime		= 0.0f;
	m_fDestTime			= 0.0f;
	m_dBarperSecond		= 0.0;
	m_dBarDownTime		= 0.0;

	m_eColor			= E_NOTE_WHITE;

#pragma region Sprite :: 생성
	//!< Sprite 생성

	CCString *plistStringName = CCString::createWithFormat("Images/Game/Note/texture_note_list.plist");
	CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
	cache->addSpriteFramesWithFile(plistStringName->getCString());

	CCString *stringName = CCString::createWithFormat("note_white_1.png");
	m_pSpNote[0] = CCSprite::createWithSpriteFrameName(stringName->getCString());
	stringName = CCString::createWithFormat("note_blue_1.png");
	m_pSpNote[1] = CCSprite::createWithSpriteFrameName(stringName->getCString());
	stringName = CCString::createWithFormat("note_red_1.png");
	m_pSpNote[2] = CCSprite::createWithSpriteFrameName(stringName->getCString());

#pragma endregion

#pragma region Position :: 생성
	////////////////////////////////////////////////////////////////////////////////////////////////////////
	//!< 좌표 생성
	
	for(int i = 0 ; i < E_NOTE_COLOR_MAX ; i++)
	{
		switch(nNotePos)
		{
		case 0:
			m_cPos.x = D_START_POS + 33;
			break;
		case 1:
			m_cPos.x = D_START_POS + 66 + 19;
			break;
		case 2:
			m_cPos.x = D_START_POS + 66 + 38 + 13.0f;
			break;
		case 3:
			m_cPos.x = D_START_POS + 66 + 38 + 26 + 19;
			break;
		case 4:
			m_cPos.x = D_START_POS + 66 + 38 + 26 + 38 + 13.0f;
			break;
		case 5:
			m_cPos.x = D_START_POS + 66 + 38 + 26 + 38 + 26 + 19;
			break;
		case 6:
			m_cPos.x = D_START_POS + 66 + 38 + 26 + 38 + 26 + 38 + 13.0f;
			break;
		case 7:
			m_cPos.x = D_START_POS + 66 + 38 + 26 + 38 + 26 + 38 + 26 + 19;
			break;
		case 8:
			m_cPos.x = D_START_POS + 66 + 38 + 26 + 38 + 26 + 38 + 26 + 38 + 13.0f;
			break;
		default:
			m_cPos.x = 1000;
			break;
		}
		
		m_cPos.y		= (float)dY;
		m_pSpNote[i]->setPosition(m_cPos);
		m_pSpNote[i]->setVisible(false);
		m_pLayer->addChild(m_pSpNote[i] , 25);
	}
#pragma endregion
	
#pragma region State :: 관련
	///////////////////////////////////////////////////////////////////////////////////////////////////////
	//!< 상태 관련 

	m_pState = new CState_Die();

	m_pState_Pool[E_STATE_MOVE] = new CState_Move();
	m_pState_Pool[E_STATE_TOUCH] = new CState_Touch();
	m_pState_Pool[E_STATE_DIE] = new CState_Die();

	m_pState_Pool[E_STATE_MOVE]->Enter(this);
	m_pState_Pool[E_STATE_TOUCH]->Enter(this);
	m_pState_Pool[E_STATE_DIE]->Enter(this);
#pragma endregion
}

/**
@brief : 생성
*/
void CShortNote::Create()
{
	m_bActive = true;
	
	m_pSpNote[m_eColor]->setPosition(m_cPos);
	m_pSpNote[m_eColor]->setVisible(false);

	Move(m_cPos);
}

/**
@brief : 업데이트
@dt : delay time
*/
void CShortNote::Update(float dt)
{
	if(!m_bActive || m_pState->GetState() == E_STATE_TOUCH) return;
	
	m_pState->Update(dt);
}

/**
@brief : 삭제
*/
void CShortNote::Destroy()
{
	for(int i = 0 ; i < 3 ; i++)
		CC_SAFE_DELETE(m_pSpNote[i]);
	delete m_pState;
}

//// 이벤트

/**
@brief : 움직일때
@pos : 위치
*/
void CShortNote::Move(CCPoint pos)
{
	ChangeState(m_pState_Pool[E_STATE_MOVE]);
	m_pState->Execute(pos);
}

/**
@brief : 터치할때
@pos : 위치
*/
void CShortNote::Touch(CCPoint pos)
{
	ChangeState(m_pState_Pool[E_STATE_TOUCH]);
	m_pState->Execute(pos);
}

/**
@brief : 죽을때
@pos : 위치
*/
void CShortNote::Die(CCPoint pos)
{
	ChangeState(m_pState_Pool[E_STATE_DIE]);
	m_pState->Execute(pos);
}

/**
@brief : 애니메이션 가져오는 함수
*/
CCSprite* CShortNote::getAnimation()
{
	return m_pSpNote[m_eColor];
}

/**
@brief : 1프레임당 움직이는 시간 알아오는 함수
@dt : delay time
*/
void CShortNote::MoveTime(float dt)
{
	m_dBarperSecond = ((4 * 60) / D_ASSET_MNG->getBPM());
	m_dBarDownTime = D_MAX_NOTEFIELD_HEIGHT * (dt / m_dBarperSecond);
	m_fDestTime = (((m_cPos.y - D_JUDGE_POSITIONY) / ( D_MAX_NOTEFIELD_HEIGHT * dt / ((4 * 60) / D_ASSET_MNG->getBPM()))) * dt) + 0.2f; 
	m_pState->MoveTime(m_dBarDownTime);
}