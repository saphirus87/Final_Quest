#pragma once
#include "gameNode.h"

class abilitiesMenu : public gameNode
{
private:

public:
	HRESULT init();
	void release();
	void update();
	void render();

	abilitiesMenu();
	~abilitiesMenu();
};

