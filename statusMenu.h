#pragma once
#include "gameNode.h"

class statusMenu : public gameNode
{
private:

public:
	HRESULT init();
	void release();
	void update();
	void render();

	statusMenu();
	~statusMenu();
};

