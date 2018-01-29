#include "stdafx.h"
#include "fieldScene.h"
#include "battleScene.h"
#include "playerManager.h"

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
	IMAGEMANAGER->addImage("worldMapCollision", ".//mapImage//worldMapCollision.bmp", 4608, 4608, true, RGB(255, 0, 255));	// 월드맵 충돌 영역
	//============================= 월드맵 이미지 추가 =============================


	//============================= 플레이어 이미지 애니메이션 추가 =============================
	_playerImg = IMAGEMANAGER->addFrameImage("playerMove", ".//playerImage//player1Move.bmp", 84, 184, 3, 4, true, RGB(255, 0, 255));	// 플레이어 이동 이미지

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
	_townRc = RectMake(TOWN_LEFT - _mapMoveX, TOWN_TOP - _mapMoveY, TOWN_SIZE, TOWN_SIZE);
	//==================== 월드맵 사용 변수 초기화 ====================

	//==================== 테스트 변수 ====================
	_x = 550;
	_y = 250;
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
	playerMove();

	//메뉴 호출
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		SOUNDMANAGER->play("메뉴선택", 1.0f); //메뉴선택 소리

		SCENEMANAGER->changeScene("메뉴씬", FALSE);
	}
	
	KEYANIMANAGER->update();

	_townRc = RectMake(TOWN_LEFT - _mapMoveX, TOWN_TOP - _mapMoveY, TOWN_SIZE, TOWN_SIZE);
	enterTown();
}

void fieldScene::render(void)
{

	IMAGEMANAGER->render("worldMapSea", getMemDC(), 0, 0, _mapMoveX, _mapMoveY, WINSIZEX, WINSIZEY);
	IMAGEMANAGER->render("worldMap", getMemDC(), 0, 0, _mapMoveX, _mapMoveY, WINSIZEX, WINSIZEY);

	if (_isDebug)
	{
		char encountNum[128];
		wsprintf(encountNum, "encount : %d", _encount);
		Rectangle(getMemDC(), _playerRc.left, _playerRc.top, _playerRc.right, _playerRc.bottom);
		TextOut(getMemDC(), _playerRc.right, _playerRc.top, encountNum, strlen(encountNum));
	}
	_playerImg->aniRender(getMemDC(), _playerRc.left, _playerRc.top, _playerAni);

	Rectangle(getMemDC(), _townRc.left, _townRc.top, _townRc.right, _townRc.bottom);
}

void fieldScene::enterTown(void)
{
	if (PtInRect(&_townRc, PointMake(_playerRc.left + PLAYER_WIDTH / 2, _playerRc.top + PLAYER_HEIGHT * 3 / 4)))
	{
		SCENEMANAGER->changeScene("townScene", FALSE);
		_x = TOWN_LEFT + 10;
		_y = TOWN_TOP + TOWN_SIZE;
		_playerState = PLAYER_IDLE | PLAYER_BOTTOM;
		_playerAni = KEYANIMANAGER->findAnimation("playerBottomIdle");
		_playerAni->start();
	}
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
		playerPixelCollision();
		break;
	case PLAYER_MOVE | PLAYER_RIGHT:
		_x += PLAYER_MOVE_SPEED;
		playerPixelCollision();
		break;
	case PLAYER_MOVE | PLAYER_TOP:
		_y -= PLAYER_MOVE_SPEED;
		playerPixelCollision();
		break;
	case PLAYER_MOVE | PLAYER_BOTTOM:
		_y += PLAYER_MOVE_SPEED;
		playerPixelCollision();
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

void fieldScene::playerPixelCollision(void)
{
	// leftTop 좌표 getPixel
	COLORREF leftTopProbe = GetPixel(IMAGEMANAGER->findImage("worldMapCollision")->getMemDC(), _x + 3, _y + 3);
	// rightTop 좌표 getPixel
	COLORREF rightTopProbe = GetPixel(IMAGEMANAGER->findImage("worldMapCollision")->getMemDC(), _x + PLAYER_WIDTH - 3, _y + 3);
	// leftBottom 좌표 getPixel
	COLORREF leftBottomProbe = GetPixel(IMAGEMANAGER->findImage("worldMapCollision")->getMemDC(), _x + 3, _y + PLAYER_HEIGHT - 3);
	// rightBottom 좌표 getPixel
	COLORREF rightBottomProbe = GetPixel(IMAGEMANAGER->findImage("worldMapCollision")->getMemDC(), _x + PLAYER_WIDTH - 3, _y + PLAYER_HEIGHT - 3);

	switch (_playerState)
	{
	case PLAYER_MOVE | PLAYER_LEFT:
		if (leftTopProbe == RGB(255, 0, 255) || leftBottomProbe == RGB(255, 0, 255)) _x += PLAYER_MOVE_SPEED;
		break;
	case PLAYER_MOVE | PLAYER_RIGHT:
		if (rightTopProbe == RGB(255, 0, 255) || rightBottomProbe == RGB(255, 0, 255)) _x -= PLAYER_MOVE_SPEED;
		break;
	case PLAYER_MOVE | PLAYER_TOP:
		if (leftTopProbe == RGB(255, 0, 255) || rightTopProbe == RGB(255, 0, 255)) _y += PLAYER_MOVE_SPEED;
		break;
	case PLAYER_MOVE | PLAYER_BOTTOM:
		if (leftBottomProbe == RGB(255, 0, 255) || rightBottomProbe == RGB(255, 0, 255)) _y -= PLAYER_MOVE_SPEED;
		break;
	default:
		break;
	}
}

void fieldScene::increasedEncount(void)
{
	if (_encount < ENCOUNT_MAX_VALUE) _encount += ENCOUNT_VALUE;
	else if (_encount >= ENCOUNT_MAX_VALUE)
	{
		//배틀씬에서 에너미 랜덤받아오게하려면 펄스빼야되서 일단뺏어요
		_pm->resetActGauge();
		SOUNDMANAGER->setMP3Volume(0.0f);
		SOUNDMANAGER->play("배틀입장");
		SOUNDMANAGER->play("배틀",0.75,true);

		SCENEMANAGER->changeScene("battleScene");
		_encount = 0;
	}
}