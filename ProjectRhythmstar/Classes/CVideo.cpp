#include "stdafx.h"

CVideo::CVideo()
{

}

CVideo::~CVideo()
{

}

void CVideo::Create(CCPoint pos , CCPoint scale , E_JUDGEMENT_TYPE eType)
{

}

void CVideo::Init(CCLayer* pLayer)
{
	//av_register_all();
	//avcodec_register_all();

	//fmt_ctx = NULL;

	//string tempName;
	//tempName += D_ASSET_MNG->getPath();
	//tempName += "/";
	//tempName += D_ASSET_MNG->getBmpDataList()->getTable()[0].sDataTarget;
	//tempName += D_ASSET_MNG->getBmpDataList()->getTable()[0].sExtensionTarget;
	//
	//avformat_open_input(&fmt_ctx , tempName.c_str() , NULL , NULL);

	//for(int i = 0 ; i < fmt_ctx->nb_streams; i++)
	//{
	//	AVStream * st = fmt_ctx->streams[i];
	//	AVCodec * dec;

	//	avcodec_open2(st->codec , dec , NULL);
	//}

	////if(FileOpen(path) == -1) return;

	//AVStream * st;
	//AVPacket pkt;
	//AVFrame *frm = av_frame_alloc();
	//int got_frame;

	//while(1) 
	//{
	//	av_read_frame(fmt_ctx , &pkt);

	//	st = fmt_ctx->streams[pkt.stream_index];
	//	avcodec_get_frame_defaults(frm);
	//	switch(st->codec->codec_type)
	//	{
	//	case AVMEDIA_TYPE_AUDIO:
	//		avcodec_decode_audio4(st->codec , frm , &got_frame , &pkt);
	//		break;
	//	case AVMEDIA_TYPE_VIDEO:
	//		avcodec_decode_video2(st->codec , frm , &got_frame , &pkt);
	//		break;
	//	}

	//	if(got_frame)
	//	{

	//	}

	//	av_free_packet(&pkt);
	//}

	//av_frame_free(&frm);

	//m_pCodec = avcodec_find_decoder(CODEC_ID_H264);
	//m_pContext = avcodec_alloc_context3(m_pCodec);

	//m_pContext->width = 800;
	//m_pContext->height = 480;
	//m_pContext->codec_id = CODEC_ID_H264;
	//m_pContext->codec_type = AVMEDIA_TYPE_VIDEO;
	//m_pContext->flags2 |= CODEC_FLAG2_FAST;
	//m_pContext->thread_count = 0;

	//avcodec_open2(m_pContext , m_pCodec , );
	
	//D_ASSET_MNG->m_Handler = MCIWndCreate(D_ASSET_MNG->m_Handler , D_ASSET_MNG->m_hInst , MCIWNDF_NOTIFYANSI | MCIWNDF_NOMENU | MCIWNDF_NOTIFYALL | MCIWNDF_NOPLAYBAR , L"movie.mpg");
	//SetWindowPos(D_ASSET_MNG->m_Handler , NULL , 0 , 0 , 800 , 480 , SWP_NOZORDER | SWP_NOMOVE);

	//MCIWndPlay(D_ASSET_MNG->m_Handler);
}

void CVideo::Update(float dt)
{

}

//int CVideo::FileOpen(string fileName)
//{
//	char * pszFileName = (char*)fileName.c_str();
//	m_pContext = NULL;
//	m_nError = avformat_open_input(&m_pContext,pszFileName , NULL , NULL);
//
//	if(m_nError >= 0) return 0;
//
//	return -1;
//}
//
//int CVideo::FindStream()
//{
//	m_nError = av_find_default_stream_index(m_pContext);
//
//	if(m_nError < 0) return -1;
//
//	m_nError = av_find_best_stream(m_pContext , AVMEDIA_TYPE_VIDEO , -1 , -1 , 
//}

void CVideo::Destroy()
{
	
}