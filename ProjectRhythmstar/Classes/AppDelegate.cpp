#include "stdafx.h"

//!< using namespace cocos2d 의 줄임입니다.
//!< 해당 것은 타고 들어가면 Define (전처리기) 로 되어 있습니다.
USING_NS_CC;

//!< AppDelegate 의 생성자 입니다
//!< 여기에 simpleaudiosound 를 전부 초기화 와 NULL 값을 해주는 구문을 넣어 주어야 합니다.
AppDelegate::AppDelegate() {
	//h 파일에 선언을 해줍니다.
	// CocosDenshion::SimpleAudioEngine * mSound;
	// mSound = CocosDenshion::SimpleAudioEngine::sharedEngine(); 대입연산자로 초기화 해줍니다.
	// mSound->preloadBackgroundMusic("BGMName.mp3"); 백그라운드 같은 무거운 것들을 먼저 처리를 함으로써 매끄러운 재생이 되도록 합니다.
}

//!< AppDelegate 의 소멸자 입니다.
//!< 여기에 simpleaudiosound 를 초기화 하고 삭제해주는 구문을 넣어 주어야 합니다.
AppDelegate::~AppDelegate() {
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->unloadEffect("SoundName.mp3"); !< 해당 구문으로 이펙트 사운드에 할당한 메모리를 해제합니다.
	//CocosDenshion::SimpleAudioEngine::sharedEngine()->stopBackgroundMusci(true); !< 해당 구문으로 백그라운드 사운드에 할당한 메모리를 해제합니다.
}

//!< 어플리케이션을 맨처음 구동시키는 Init 이라 보시면 됩니다 ^^
bool AppDelegate::applicationDidFinishLaunching() {
    
#pragma region 해상도 조절 소스
	//!< CCDirector 는 총괄하는 감독 입니다.
	//!< 구조는 싱글턴으로 짜여 있으며, 씬 전체의 베이스를 담당합니다.
	//!< 상황에 따라서 CCDirector 를 통해 Scene의 설정을 변경 할 수 있습니다.
    CCDirector* pDirector = CCDirector::sharedDirector();

	//!< CCEGView 는 윈도우를 그려주는 역할을 합니다.
    CCEGLView* pEGLView = CCEGLView::sharedOpenGLView();
	
/*
	sharedOpenGLView를 사용할때 맨 마지막 인자로 들어가는 것들 입니다 ^^

	//!< 가로 세로 비율을 유지하지 않고 뻗는 느낌으로 표시됩니다 ^^
    kResolutionExactFit,
	
    //!< 가로 세로 비율을 유지하고 오른쪽이나 위쪽에 사이즈가 맞지 않으면 최대 사이즈로 하고 
	//!< 빈 공간은 검정색으로 만듭니다.
    kResolutionNoBorder,
    
	//!< 가로 세로 비율 유지하고 화면 가득 표시됩니다 ^^
	kResolutionShowAll,
    
	//!< 세로 기준으로 풍부하게 잡습니다.
    kResolutionFixedHeight,
    
	//!< 가로 기준으로 풍부하게 잡습니다.
    kResolutionFixedWidth,

	//!< 아무 경우의 수도 아닐 경우 들어옵니다 ^^
    kResolutionUnKnown,
*/

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID) //!< Android 버전 일때 입니다.
	//!< ========================================================================
	//!< 강제 해상도 설정 부분 시작

	//!< CCDirector 가 스크린에 뿌려줍니다.
    pDirector->setOpenGLView(pEGLView);
	
	//!< 스크린에 뿌려준 것들을 전부 강제 해상도 조정을 하여 핸드폰 기종마다 전부 맞춰주는 역할을 합니다. 
	//!< 첫번째 인자 : width (가로) // 두번째 인자 : height (세로)
	//!< 세번째 인자 Resolution Policy
	CCEGLView::sharedOpenGLView()->setDesignResolutionSize(D_DESIGN_WIDTH, D_DESIGN_HEIGHT, kResolutionShowAll);
	
	//!< 강제 해상도 설정 부분 끝
	//!< ========================================================================>

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_IOS) //!< IOS 버전 일때 입니다.

	pEGLView->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, kResolutionShowAll);
	
	//!< 현재 자신의 핸드폰의 사이즈를 가져옵니다 ^^
	CCSize frameSize = pEGLView->getFrameSize();

	//!< 이미지들을 저장해주기 위한 백터
	vector<string> searchPath;

    //!< 이 부분은 각각의 아이폰 픽셀별로 지정해 주는 부분입니다 ^^
	//!< 아이폰 플랫폼 별로 각각의 폴더가 Resources 파일에 있을겁니다 ^^ 거기안에 해당 이미지 픽셀만큼 처리하면 됩니다 ^^
	//!< 아이폰은 딱 플랫폼이 몇개 없으므로 각각으로 나누었습니다 ^^

	//!< 사이즈가 medium 보다 클때 이므로 즉 large 입니다 ^^
	if (frameSize.height > mediumResource.size.height)
	{
        searchPath.push_back(largeResource.directory);

        pDirector->setContentScaleFactor(MIN(largeResource.size.height/designResolutionSize.height, largeResource.size.width/designResolutionSize.width));
	}
    
	//!< 사이즈가 small 보다 크고 large 보다 작을때 즉 medium 일때 입니다 ^^
    else if (frameSize.height > smallResource.size.height)
    {
        searchPath.push_back(mediumResource.directory);
        
        pDirector->setContentScaleFactor(MIN(mediumResource.size.height/designResolutionSize.height, mediumResource.size.width/designResolutionSize.width));
    }
   
	//!< 말 안해도 아시겠죠?
	else
    {
        searchPath.push_back(smallResource.directory);

        pDirector->setContentScaleFactor(MIN(smallResource.size.height/designResolutionSize.height, smallResource.size.width/designResolutionSize.width));
    }

    // 파일 디텍터리를 찾습니다 ^^
    CCFileUtils::sharedFileUtils()->setSearchPaths(searchPath);

#elif (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) //!< 윈도우 버전 일때 입니다.

	//!< CCDirector 가 스크린에 뿌려줍니다.
    pDirector->setOpenGLView(pEGLView);
	
	//!< 스크린에 뿌려준 것들을 전부 강제 해상도 조정을 하여 핸드폰 기종마다 전부 맞춰주는 역할을 합니다. 
	//!< 첫번째 인자 : width (가로) // 두번째 인자 : height (세로)
	//!< 세번째 인자 Resolution Policy
    CCEGLView::sharedOpenGLView()->setDesignResolutionSize(D_DESIGN_WIDTH, D_DESIGN_HEIGHT, kResolutionShowAll);
#endif
#pragma endregion

	//!< DEBUG 일시에만 Display Stats (프레임) 보여줍니다.
#ifdef DEBUG
    pDirector->setDisplayStats(true);
#else
	//!< DEBUG가 아닐 경우에는 안보여줍니다. ex) Release
	pDirector->setDisplayStats(false);
#endif

    //!< FPS 를 설정합니다. 현재는 1초에 60번 프레임이 돌게 됩니다.
    pDirector->setAnimationInterval(1.0 / 60);
	
	D_ASSET_MNG->setFPS(pDirector->getSecondsPerFrame());
    //!< Scene을 생성합니다. 
	//!< Start Scene을 HelloWorld 라는 Scene으로 설정 하였습니다.
	CCScene *pScene = CGame::scene();

    //!< 씬을 돌려줍니다.
	//!< 여기서 개념은 베이스가 돌아가는 동시에 씬도 같이 돌아가는 친구같은 것이라 보시면 됩니다.
    pDirector->runWithScene(pScene);

	//!< 한번만 돌아가도록 승인합니다 ^^
    return true;
}

//!< 이 곳은 어플리케이션을 홈버튼을 누른다거나 홀드 버튼을 눌러 정지가 되었을 때 들어오는 부분 입니다.
//!< 이 곳에서 사운드 정지나 일시정지가 되도록 하면 게임을 피치못하게 나가거나 꺼졌을 때
//!< 도움이 될 것 입니다.
void AppDelegate::applicationDidEnterBackground() {
    CCDirector::sharedDirector()->stopAnimation();

    //!< 사운드 같은 것을 멈추면 좋습니다.
    // SimpleAudioEngine::sharedEngine()->pauseBackgroundMusic();
}

//!< 이곳은 반대로 나갈때가 아닌 다시 들어올때 들어오는 부분 입니다.
//!< 다시 재생을 시켜 주시면 됩니다.
void AppDelegate::applicationWillEnterForeground() {
    CCDirector::sharedDirector()->startAnimation();

    //!< 여기서 사운드 같은 것을 재시작하면 좋습니다.
    // SimpleAudioEngine::sharedEngine()->resumeBackgroundMusic();
}


