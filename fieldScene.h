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
	int _encount;					// 전투 진입 필요 값
	int _playerState;				// 플레이어 상태 값
	image* _playerImg;				// 플레이어 이미지
	animation* _playerAni;			// 플레이어 애니메이션
	RECT _townRc;					// 마을 진입 영역
	playerManager* _pm;

	int _alpha;						// 씬 전환시 알파 변경값


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
	
	void enterTown(void);

	void playerKeyInput(void);
	void playerMove(void);
	void playerPixelCollision(void);
	
	void increasedEncount(void);

	void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }
};

