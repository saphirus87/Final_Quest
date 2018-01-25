#pragma once
#include "player.h"
class player1 : public player
{
private:


public:
	player1();
	~player1();


	HRESULT init();
	void release();
	void update();
	void render();
};

