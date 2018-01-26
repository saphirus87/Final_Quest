#pragma once
#include "fieldScene.h"

#define EXIT_AREA_LEFT 1080
#define EXIT_AREA_TOP 1500
#define EXIT_AREA_SIZEX 100
#define EXIT_AREA_SIZEY 50
#define TOWN_INIT_POSX 1110;
#define TOWN_INIT_POSY 1450;

class townScene : public gameNode
{
private:
	int _encount;
	int _playerState;
	image* _playerImg;
	animation* _playerAni;
	RECT _exitAreaRc;					// 마을 나가는 영역

	//==================== 애니메이션 변수 ====================
private:

	//==================== 애니메이션 변수 ====================

	//==================== 테스트 변수 ====================
private:
	float _x, _y;		//플레이어 좌표
	RECT _playerRc;		//플레이어 렉트
	float _mapMoveX, _mapMoveY;
	//==================== 테스트 변수 ====================

public:
	townScene();
	~townScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	void playerKeyInput(void);
	void playerMove(void);
	//void playerPixelCollision(void);
	void enterWorldMap(void);
};

