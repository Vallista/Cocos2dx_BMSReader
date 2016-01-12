#include "stdafx.h"

/**
@brief : 초기화
@pNote : 노트 오브젝트
*/
void CState_Die::Enter(INoteObject* pNote)
{
	m_pNote = pNote;
}

/**
@brief : 처음 들어올때
@pos : 위치
*/
void CState_Die::Execute(CCPoint pos)
{
	m_pNote->getAnimation()->setVisible(false);
	m_dMoveTime = 0.0f;

	switch(m_pNote->getPrivateNum()) {
	case D_BPMBLOCK_NUM		: D_ASSET_MNG->setFBPM(m_pNote->getBpm()); break;	//!< BPM 블록
	//case D_CANSELBLOCK_NUM	: break;//D_ASSET_MNG->setJointMul(m_pNote->getCanselTime()); D_ASSET_MNG->setJointValue(m_pNote->getBarNum()); D_GAME_MNG->setCancelTimer(0.0); break;	//!< 마디 감속 블록
	case D_BITMAPBLOCK_NUM	: break;//D_UI_MNG->getUI(E_UI_BACKGROUND)->ChangeBackGround(m_pNote->getTextureName()); break;	//!< 비트맵 블록
	case D_WAVEBLOCK_NUM	: D_GAME_MNG->getSongManager()->Play(m_pNote->getSoundNum()); break; //!< 백그라운드 파일 경로
	case D_STOPBLOCK_NUM	: D_ASSET_MNG->setJointValue(0); D_ASSET_MNG->setStopTime(m_pNote->getIndex()); break;
	default:
		if(m_pNote->getMissCheck()) 
		{
			D_UI_MNG->getUI(E_UI_SHOW)->Create(ccp(190.0f , 530.0f) , ccp(0.2f , 0.2f) , E_JUDGEMENT_MISS);
			D_GAME_MNG->Miss();
			break;
		}

		if(m_pNote->getDestTime() >= D_ASSET_MNG->getJudge().fPerfect[E_JUDGEMENT_MIN] 
		&& m_pNote->getDestTime() <= D_ASSET_MNG->getJudge().fPerfect[E_JUDGEMENT_MAX])
		{
			D_UI_MNG->getUI(E_UI_SHOW)->Create(ccp(190.0f , 530.0f) , ccp(0.2f , 0.2f) , E_JUDGEMENT_PERFECT);
			D_GAME_MNG->Perfect();
		}
		else if (m_pNote->getDestTime() >= D_ASSET_MNG->getJudge().fGreat[E_JUDGEMENT_MIN] 
		&& m_pNote->getDestTime() <= D_ASSET_MNG->getJudge().fGreat[E_JUDGEMENT_MAX])
		{
			D_UI_MNG->getUI(E_UI_SHOW)->Create(ccp(190.0f , 530.0f) , ccp(0.2f , 0.2f) , E_JUDGEMENT_GREAT);
			D_GAME_MNG->Great();
		}
		else if (m_pNote->getDestTime() >= D_ASSET_MNG->getJudge().fGood[E_JUDGEMENT_MIN] 
		&& m_pNote->getDestTime() <= D_ASSET_MNG->getJudge().fGood[E_JUDGEMENT_MAX])
		{
			D_UI_MNG->getUI(E_UI_SHOW)->Create(ccp(190.0f , 530.0f) , ccp(0.2f , 0.2f) , E_JUDGEMENT_GOOD);
			D_GAME_MNG->Good();
		}
		else if (m_pNote->getDestTime() >= D_ASSET_MNG->getJudge().fBad[E_JUDGEMENT_MIN] 
		&& m_pNote->getDestTime() <= D_ASSET_MNG->getJudge().fBad[E_JUDGEMENT_MAX])
		{
			D_UI_MNG->getUI(E_UI_SHOW)->Create(ccp(190.0f , 530.0f) , ccp(0.2f , 0.2f) , E_JUDGEMENT_BAD);
			D_GAME_MNG->Bad();
		}
		else if (m_pNote->getDestTime() < D_ASSET_MNG->getJudge().fMiss[E_JUDGEMENT_MIN] 
		|| m_pNote->getDestTime() > D_ASSET_MNG->getJudge().fMiss[E_JUDGEMENT_MAX])
		{
			D_UI_MNG->getUI(E_UI_SHOW)->Create(ccp(190.0f , 530.0f) , ccp(0.2f , 0.2f) , E_JUDGEMENT_MISS);
			D_GAME_MNG->Miss();
		}

		break;
	}
}

/**
@brief : 업데이트
@dt : delay time
*/
void CState_Die::Update(float dt)
{

}

/**
@brief : 프레임당 움직이는 거리
@dy : 거리값
*/
void CState_Die::MoveTime(double dy)
{
	m_dMoveTime = dy;
}