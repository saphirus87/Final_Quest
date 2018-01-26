#pragma once
#include "player.h"
class player2 : public player
{
private:

public:
	player2();
	~player2();

	HRESULT init();
	void release();
	void update();
	void render(void);
};

