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

	IMAGEMANAGER->addFrameImage("playerMove", ".//playerImage//playerMove.bmp", 84, 184, 3, 4, true, RGB(255, 0, 255));	// 플레이어 이동 이미지
	//============================= 월드맵 이미지 추가 =============================

	//==================== 월드맵 사용 변수 초기화 ====================
	_encount = 0;
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

	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		SCENEMANAGER->changeScene("메뉴씬", FALSE);
	}

	_playerRc = RectMake(_x, _y, PLAYER_WIDTH, PLAYER_HEIGHT);

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
	
	Rectangle(getMemDC(), _playerRc.left, _playerRc.top, _playerRc.right, _playerRc.bottom);
}

void fieldScene::playerMove(void)
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_x -= 3;
		increasedEncount();
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_x += 3;
		increasedEncount();
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_y -= 3;
		increasedEncount();
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_y += 3;
		increasedEncount();
	}
}

void fieldScene::increasedEncount(void)
{
	if (_encount < ENCOUNT_MAX_VALUE) _encount += ENCOUNT_VALUE;
	else if (_encount > ENCOUNT_MAX_VALUE)
	{
		SCENEMANAGER->changeScene("battleScene");
		_encount = 0;
	}
}