#pragma once
#include "gameNode.h"

class saveLoadMenu : public gameNode
{
private:

public:
	HRESULT init();
	void release();
	void update();
	void render();

	saveLoadMenu();
	~saveLoadMenu();
};

