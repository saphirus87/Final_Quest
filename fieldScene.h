#pragma once
#include "gameNode.h"

#define CAMERA_MOVE_SPEED 5.0f
#define PLAYER_WIDTH 48
#define PLAYER_HEIGHT 48

class fieldScene : public gameNode
{
private:
	image* _worldMap;

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
};

