#pragma once
#include "gameNode.h"

class Item;

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
	int isinit;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void setItemAddressLink(Item* Item) { _Item = Item; }

	itemMenu();
	~itemMenu();
};

