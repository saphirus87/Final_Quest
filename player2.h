#pragma once
#include "player.h"
class player2 : public player
{
private:

public:
	player2();
	~player2();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(void);
	
	virtual void levelUp(void);
};

