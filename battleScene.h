#pragma once
#include "gameNode.h"
#include <vector>
#include "enemyManager.h"

typedef void(*ACTION_FUNTION)(void*, void*);

struct tagDamageDraw
{
	int pos;
	int damage;
};

class playerManager;

class battleScene : public gameNode
{
private:
	int totalGold;
	int totalExp;
	bool isinit;
	bool _isVictory;
	tagDamageDraw _playerDamage[3];
	tagDamageDraw _enemyDamage[3];
	vector<CALLBACK_FUNCTION> _vActionList;
	enemyManager* _em;
	playerManager* _pm;

public:
	battleScene();
	~battleScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	/*
	// 플레이어 행동 선택 함수
	void selectCommand(void);

	// 플레이어 & 적 행동 함수
	void attack(void);
	void useSkill(void);
	void useItem(void);
	void defense(void);
	void escape(void);
	// 행동 게이지 증가 함수 
	void increasedActionGauge(void);
	미사용 함수
	*/

	void playerAction(void);
	void increaseEnemyTimer(void);

	void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }

	void enemyPositionSetting();
	//에너미가 플레이어때리는거
	void enemyHitPlayer();
	//플레이어가 에너미 때리는거
	void playerHitEnemy();

	void targetSelectCursorDraw(void);
	void takenDamageDraw(void);

	//****************** 관리자모드 함수 ******************
	void resetPlayerActGauge(void);


};

