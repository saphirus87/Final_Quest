#pragma once
#include "player.h"
class player1 : public player
{
private:


public:
	player1();
	~player1();


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(void);
};

