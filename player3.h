#pragma once
#include "player.h"
class player3 : public player
{
private:

public:
	player3();
	~player3();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(void);

	virtual void levelUp(void);
};

