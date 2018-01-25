#pragma once
#include "gameNode.h"

class equipMenu : public gameNode
{
private:

public:
	HRESULT init();
	void release();
	void update();
	void render();

	equipMenu();
	~equipMenu();
};

