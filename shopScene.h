#pragma once
#include "gameNode.h"

class Item;

class shopScene : public gameNode
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
	shopScene();
	~shopScene();

	inline void setItemAddressLink(Item* Item) { _Item = Item; }

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

