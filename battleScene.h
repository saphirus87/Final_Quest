#pragma once
#include "gameNode.h"
#include <vector>
#include "enemyManager.h"

typedef void(*ACTION_FUNTION)(void*, void*);

class battleScene : public gameNode
{
private:
	vector<CALLBACK_FUNCTION> _vActionList;
	enemyManager* em;

public:
	battleScene();
	~battleScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	
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
};

