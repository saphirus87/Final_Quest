#pragma once
#include "gameNode.h"

class itemMenu : public gameNode
{
private:
	bool seltype;
	int selnum;
	int waitselnum;
	int waitX, waitY;
	int selX, selY;
	int itemsize, equipsize;
	int isinit;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	itemMenu();
	~itemMenu();
};

