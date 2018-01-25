#pragma once
#include "enemy.h"
class Boss : public enemy
{
private:
	bool isReflex; //디펜스일때 반사하는값
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

