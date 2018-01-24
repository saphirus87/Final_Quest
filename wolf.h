#pragma once
#include "enemy.h"
class wolf : public enemy
{
private:
public:
	wolf();
	~wolf();

	HRESULT init();
	void release();
	void update();
	void render();
};

