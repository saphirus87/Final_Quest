#pragma once
#include "gameNode.h"

#define CAMERA_MOVE_SPEED 5.0f
#define TOWN_LEFT 1050
#define TOWN_TOP 550
#define TOWN_SIZE 50

#define PLAYER_MOVE_SPEED 4.0f
#define PLAYER_WIDTH 28
#define PLAYER_HEIGHT 46

#define ENCOUNT_MAX_VALUE 500
#define ENCOUNT_VALUE RND->getFromIntTo(5, 10)

enum PLAYER_STATE
{
	PLAYER_LEFT = 1,
	PLAYER_RIGHT = 2,
	PLAYER_TOP = 4,
	PLAYER_BOTTOM = 8,
	PLAYER_IDLE = 256,
	PLAYER_MOVE = 512,
	PLAYER_MOVE_MASK = PLAYER_IDLE | PLAYER_MOVE
};

class playerManager;

class fieldScene : public gameNode
{
private:
	int _encount;					// ���� ���� �ʿ� ��
	int _playerState;				// �÷��̾� ���� ��
	image* _playerImg;				// �÷��̾� �̹���
	animation* _playerAni;			// �÷��̾� �ִϸ��̼�
	RECT _townRc;					// ���� ���� ����
	playerManager* _pm;

	int _alpha;						// �� ��ȯ�� ���� ���氪


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
	
	void enterTown(void);

	void playerKeyInput(void);
	void playerMove(void);
	void playerPixelCollision(void);
	
	void increasedEncount(void);

	void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }
};

