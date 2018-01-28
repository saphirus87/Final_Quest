#pragma once
#include "gameNode.h"
class Item;
class playerManager;


class equipMenu : public gameNode
{
private:
	Item * _Item;
	playerManager* _pm;
	int _cursorMenuNum;

	bool _isCharater1;
	bool _isCharater2;
	bool _isCharater3;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();

	void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }
	void setItemAddressLink(Item* Item) { _Item = Item; }

	equipMenu();
	~equipMenu();
};

