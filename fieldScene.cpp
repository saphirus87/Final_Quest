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
	//============================= ����� �̹��� �߰� =============================
	IMAGEMANAGER->addImage("worldMap", ".//mapImage//worldMap.bmp", 4608, 4608, true, RGB(255, 0, 255));				// ����� �߰�
	IMAGEMANAGER->addImage("worldMapSea", ".//mapImage//sea.bmp", 4608, 4608, true, RGB(255, 0, 255));					// ����� �ٴ� �̹���
	IMAGEMANAGER->addImage("worldMapCollision", ".//mapImage//worldMapCollision", 4608, 4608, true, RGB(255, 0, 255));	// ����� �浹 ����
	//============================= ����� �̹��� �߰� =============================


	//============================= �÷��̾� �̹��� �ִϸ��̼� �߰� =============================
	_playerImg = IMAGEMANAGER->addFrameImage("playerMove", ".//playerImage//playerMove.bmp", 84, 184, 3, 4, true, RGB(255, 0, 255));	// �÷��̾� �̵� �̹���

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
	//============================= �÷��̾� �̹��� �ִϸ��̼� �߰� =============================


	//==================== ����� ��� ���� �ʱ�ȭ ====================
	_encount = 0;
	_playerAni = KEYANIMANAGER->findAnimation("playerBottomIdle");
	_playerAni->start();
	//==================== ����� ��� ���� �ʱ�ȭ ====================

	//==================== �׽�Ʈ ���� ====================
	_x = 100;
	_y = 100;
	_playerRc = RectMake(_x, _y, PLAYER_WIDTH, PLAYER_HEIGHT);
	_mapMoveX = _mapMoveY = 0;
	//==================== �׽�Ʈ ���� ====================

	//==================== ����� ���� ���� ====================
	_moveX = _moveY = 0;
	//==================== ����� ���� ���� ====================

	return S_OK;
}

void fieldScene::release(void)
{
}

void fieldScene::update(void)
{
	//����� ���� ��ǥ �̵�
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

	//�޴� ȣ��
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE))
	{
		SCENEMANAGER->changeScene("�޴���", FALSE);
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
	// �÷��̾� ����Ű �Է�
	playerKeyInput();
	
	// �÷��̾� �̵��� encount �� ����
	if (_playerState & PLAYER_MOVE) increasedEncount();

	// �÷��̾� ���¿� ���� ��ǥ ����
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

	// �÷��̾� ��ǥ�� ���� ��Ʈ ����
	_playerRc = RectMake(_x, _y, PLAYER_WIDTH, PLAYER_HEIGHT);

	// ī�޶� ȿ���� ���� �÷��̾� ��ǥ �̵��� �÷��̾� ��Ʈ�� �� ���� ��ǥ ����
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