#pragma once
#include "gameNode.h"

class Item;
class playerManager;

class itemMenu : public gameNode
{
private:
	Item* _Item;
	playerManager* _pm;
	bool seltype;
	bool selItem;
	int selnum;
	int waitselnum;
	int waitselItem;
	int waitX, waitY;
	int selX, selY;
	int waitItemX, waitItemY;
	int itemsize, equipsize;
	int isinit;
	int playersel;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	inline void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }
	inline void setItemAddressLink(Item* Item) { _Item = Item; }

	itemMenu();
	~itemMenu();
};

