#include "stdafx.h"
#include "fieldScene.h"


fieldScene::fieldScene()
{
}


fieldScene::~fieldScene()
{
}

HRESULT fieldScene::init(void)
{
	//============================= 월드맵 이미지 추가 =============================
	IMAGEMANAGER->addImage("worldMap", ".//mapImage//worldMap.bmp", 4608, 4608, true, RGB(255, 0, 255));				// 월드맵 추가
	IMAGEMANAGER->addImage("worldMapSea", ".//mapImage//sea.bmp", 4608, 4608, true, RGB(255, 0, 255));					// 월드맵 바다 이미지
	IMAGEMANAGER->addImage("worldMapCollision", ".//mapImage//worldMapCollision", 4608, 4608, true, RGB(255, 0, 255));	// 월드맵 충돌 영역
	//============================= 월드맵 이미지 추가 =============================


	//============================= 플레이어 이미지 애니메이션 추가 =============================
	_playerImg = IMAGEMANAGER->addFrameImage("playerMove", ".//playerImage//playerMove.bmp", 84, 184, 3, 4, true, RGB(255, 0, 255));	// 플레이어 이동 이미지

	int arrLeftIdle[] = { 7 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftIdle", "playerMove", arrLeftIdle, 1, 10, true);
	
	int arrRightIdle[] = { 10 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightIdle", "playerMove", arrRightIdle, 1, 10, true);

	int arrTopIdle[] = { 4 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTopIdle", "playerMove", arrTopIdle, 1, 10, true);

	int arrBottomIdle[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerBottomIdle", "playerMove", arrBottomIdle, 1, 10, true);

	int arrLeftMove[] = { 6, 7, 8, 7 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftMove", "playerMove", arrLeftMove, 4, 5, true);

	int arrRightMove[] = { 9, 10, 11, 10 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightMove", "playerMove", arrRightMove, 4, 5, true);

	int arrTopMove[] = { 3, 4, 5, 4 };
	KEYANIMANAGER->addArrayFrameAnimation("playerTopMove", "playerMove", arrTopMove, 4, 5, true);

	int arrBottomMove[] = { 0, 1, 2, 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerBottomMove", "playerMove", arrBottomMove, 4, 5, true);
	//============================= 플레이어 이미지 애니메이션 추가 =============================


	//==================== 월드맵 사용 변수 초기화 ====================
	_encount = 0;
	_playerAni = KEYANIMANAGER->findAnimation("playerBottomIdle");
	_playerAni->start();
	//==================== 월드맵 사용 변수 초기화 ====================

	//==================== 테스트 변수 ====================
	_x = 100;
	_y = 100;
	_playerRc = RectMake(_x, _y, PLAYER_WIDTH, PLAYER_HEIGHT);
	_mapMoveX = _mapMoveY = 0;
	//==================== 테스트 변수 ====================

	//==================== 디버그 모드용 변수 ====================
	_moveX = _moveY = 0;
	//==================== 디버그 모드용 변수 ====================

	return S_OK;
}

void fieldScene::release(void)
{
}

void fieldScene::update(void)
{
	//디버그 모드시 좌표 이동
	if (_isDebug)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT)) _moveX -= CAMERA_MOVE_SPEED;
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) _moveX += CAMERA_MOVE_SPEED;
		if (KEYMANAGER->isStayKeyDown(VK_UP)) _moveY -= CAMERA_MOVE_SPEED;
		if (KEYMANAGER->isStayKeyDown(VK_DOWN)) _moveY += CAMERA_MOVE_SPEED;
	}
	else
	{
		playerMove();
	}

	//메뉴 호출
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		SCENEMANAGER->changeScene("메뉴씬", FALSE);
	}
	
	KEYANIMANAGER->update();
}

void fieldScene::render(void)
{
	if (_isDebug)
	{
		IMAGEMANAGER->render("worldMapSea", getMemDC(), 0, 0, _moveX, _moveY, WINSIZEX, WINSIZEY);
		IMAGEMANAGER->render("worldMap", getMemDC(), 0, 0, _moveX, _moveY, WINSIZEX, WINSIZEY);
	}
	else
	{
		IMAGEMANAGER->render("worldMapSea", getMemDC(), 0, 0, _mapMoveX, _mapMoveY, WINSIZEX, WINSIZEY);
		IMAGEMANAGER->render("worldMap", getMemDC(), 0, 0, _mapMoveX, _mapMoveY, WINSIZEX, WINSIZEY);
	}
	
	_playerImg->aniRender(getMemDC(), _playerRc.left, _playerRc.top, _playerAni);
	if (_isDebug) Rectangle(getMemDC(), _playerRc.left, _playerRc.top, _playerRc.right, _playerRc.bottom);
}

void fieldScene::playerMove(void)
{
	// 플레이어 방향키 입력
	playerKeyInput();
	
	// 플레이어 이동시 encount 값 증가
	if (_playerState & PLAYER_MOVE) increasedEncount();

	// 플레이어 상태에 따른 좌표 변경
	switch (_playerState)
	{
	case PLAYER_IDLE | PLAYER_LEFT:
		break;
	case PLAYER_IDLE | PLAYER_RIGHT:
		break;
	case PLAYER_IDLE | PLAYER_TOP:
		break;
	case PLAYER_IDLE | PLAYER_BOTTOM:
		break;
	case PLAYER_MOVE | PLAYER_LEFT:
		_x -= PLAYER_MOVE_SPEED;
		break;
	case PLAYER_MOVE | PLAYER_RIGHT:
		_x += PLAYER_MOVE_SPEED;
		break;
	case PLAYER_MOVE | PLAYER_TOP:
		_y -= PLAYER_MOVE_SPEED;
		break;
	case PLAYER_MOVE | PLAYER_BOTTOM:
		_y += PLAYER_MOVE_SPEED;
		break;
	default:
		break;
	}

	// 플레이어 좌표에 따라 렉트 생성
	_playerRc = RectMake(_x, _y, PLAYER_WIDTH, PLAYER_HEIGHT);

	// 카메라 효과를 위해 플레이어 좌표 이동시 플레이어 렉트와 맵 랜더 좌표 변경
	if (_x > WINSIZEX / 2 - PLAYER_WIDTH / 2 && _x < IMAGEMANAGER->findImage("worldMap")->getWidth() - WINSIZEX / 2 - PLAYER_WIDTH / 2)
	{
		_playerRc.left = WINSIZEX / 2 - PLAYER_WIDTH / 2;
		_playerRc.right = _playerRc.left + PLAYER_WIDTH;
		_mapMoveX = _x - _playerRc.left;
	}
	if (_y > WINSIZEY / 2 - PLAYER_HEIGHT / 2 && _y < IMAGEMANAGER->findImage("worldMap")->getHeight() - WINSIZEY / 2 - PLAYER_HEIGHT / 2)
	{
		_playerRc.top = WINSIZEY / 2 - PLAYER_HEIGHT / 2;
		_playerRc.bottom = _playerRc.top + PLAYER_HEIGHT;
		_mapMoveY = _y - _playerRc.top;
	}

	if (_mapMoveX < 0) _mapMoveX = 0;
	if (_mapMoveY < 0) _mapMoveY = 0;
}

void fieldScene::playerKeyInput(void)
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_playerState = PLAYER_MOVE | PLAYER_LEFT;
		_playerAni = KEYANIMANAGER->findAnimation("playerLeftMove");
		_playerAni->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_playerState = PLAYER_IDLE | PLAYER_LEFT;
		_playerAni = KEYANIMANAGER->findAnimation("playerLeftIdle");
		_playerAni->start();
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_playerState = PLAYER_MOVE | PLAYER_RIGHT;
		_playerAni = KEYANIMANAGER->findAnimation("playerRightMove");
		_playerAni->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_playerState = PLAYER_IDLE | PLAYER_RIGHT;
		_playerAni = KEYANIMANAGER->findAnimation("playerRightIdle");
		_playerAni->start();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_playerState = PLAYER_MOVE | PLAYER_TOP;
		_playerAni = KEYANIMANAGER->findAnimation("playerTopMove");
		_playerAni->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_playerState = PLAYER_IDLE | PLAYER_TOP;
		_playerAni = KEYANIMANAGER->findAnimation("playerTopIdle");
		_playerAni->start();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_playerState = PLAYER_MOVE | PLAYER_BOTTOM;
		_playerAni = KEYANIMANAGER->findAnimation("playerBottomMove");
		_playerAni->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_playerState = PLAYER_IDLE | PLAYER_BOTTOM;
		_playerAni = KEYANIMANAGER->findAnimation("playerBottomIdle");
		_playerAni->start();
	}
}

void fieldScene::increasedEncount(void)
{
	if (_encount < ENCOUNT_MAX_VALUE) _encount += ENCOUNT_VALUE;
	else if (_encount > ENCOUNT_MAX_VALUE)
	{
		SCENEMANAGER->changeScene("battleScene", FALSE);
		_encount = 0;
	}
}