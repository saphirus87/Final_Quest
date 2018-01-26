#pragma once
#include "player.h"
class player3 : public player
{
private:

public:
	player3();
	~player3();

	HRESULT init();
	void release();
	void update();
	void render(void);
};

