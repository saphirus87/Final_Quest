#pragma once
#include "enemy.h"
class Boss : public enemy
{
private:
	bool isReflex; //���潺�϶� �ݻ��ϴ°�
	int boss_StartTime;
public:
	Boss();
	~Boss();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
	void bossAttack();
};

