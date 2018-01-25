#pragma once
#include "gameNode.h"
#include "Item.h"

class itemMenu : public gameNode
{
private:
	Item* _Item;
	bool seltype;
	int selnum;
	int waitselnum;
	int waitX, waitY;
	int selX, selY;
	int itemsize, equipsize;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	itemMenu();
	~itemMenu();

	Item* itempos() { return _Item; }
};

