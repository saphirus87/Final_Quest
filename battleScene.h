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
	// �÷��̾� �ൿ ���� �Լ�
	void selectCommand(void);

	// �÷��̾� & �� �ൿ �Լ�
	void attack(void);
	void useSkill(void);
	void useItem(void);
	void defense(void);
	void escape(void);
	// �ൿ ������ ���� �Լ� 
	void increasedActionGauge(void);
	�̻�� �Լ�
	*/

	void playerAction(void);
	void increaseEnemyTimer(void);

	void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }

	void enemyPositionSetting();
	//���ʹ̰� �÷��̾���°�
	void enemyHitPlayer();
	//�÷��̾ ���ʹ� �����°�
	void playerHitEnemy();

	void targetSelectCursorDraw(void);
	void takenDamageDraw(void);

	//****************** �����ڸ�� �Լ� ******************
	void resetPlayerActGauge(void);


};

