#pragma once
#include "gameNode.h"

#define CAMERA_MOVE_SPEED 5.0f
#define PLAYER_WIDTH 48
#define PLAYER_HEIGHT 48

class fieldScene : public gameNode
{
private:
	image* _worldMap;

//==================== �׽�Ʈ ���� ====================
private:
	float _x, _y;		//�÷��̾� ��ǥ
	RECT _playerRc;		//�÷��̾� ��Ʈ
	float _mapMoveX, _mapMoveY;
//==================== �׽�Ʈ ���� ====================

//==================== ����� ���� ���� ====================
private:
	int _moveX, _moveY;
//==================== ����� ���� ���� ====================

public:
	fieldScene();
	~fieldScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

