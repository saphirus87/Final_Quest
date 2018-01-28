#pragma once
#include "enemy.h"//
class mammos : public enemy
{
private:
	int frame;
public:
	mammos();
	~mammos();

	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};

