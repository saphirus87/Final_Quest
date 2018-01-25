#pragma once
#include "gameNode.h"

#define CAMERA_MOVE_SPEED 5.0f
#define PLAYER_MOVE_SPEED 4.0f
#define PLAYER_WIDTH 48
#define PLAYER_HEIGHT 48

#define ENCOUNT_MAX_VALUE 8000
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

class fieldScene : public gameNode
{
private:
	int _encount;
	int _playerState;
	image* _playerImg;
	animation* _playerAni;

//==================== 애니메이션 변수 ====================
private:

//==================== 애니메이션 변수 ====================

//==================== 테스트 변수 ====================
private:
	float _x, _y;		//플레이어 좌표
	RECT _playerRc;		//플레이어 렉트
	float _mapMoveX, _mapMoveY;
//==================== 테스트 변수 ====================

//==================== 디버그 모드용 변수 ====================
private:
	int _moveX, _moveY;
//==================== 디버그 모드용 변수 ====================

public:
	fieldScene();
	~fieldScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	
	void playerKeyInput(void);
	void playerMove(void);
	

	void increasedEncount(void);
};

