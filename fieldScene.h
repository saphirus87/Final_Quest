#pragma once
#include "gameNode.h"

#define CAMERA_MOVE_SPEED 5.0f
#define PLAYER_WIDTH 48
#define PLAYER_HEIGHT 48

#define ENCOUNT_MAX_VALUE 8000
#define ENCOUNT_VALUE RND->getFromIntTo(5, 10)

class fieldScene : public gameNode
{
private:
	int _encount;

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

	void playerMove(void);
	void playerAni(void);

	void increasedEncount(void);
};

