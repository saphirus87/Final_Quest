#pragma once
#include "enemy.h"//
class knight : public enemy
{
private:
	int frame;

public:
	knight();
	~knight();
	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);
};

