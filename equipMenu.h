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

	int equipsize;
	int _waitplayersel;
	bool _isCharater;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();

	void player1Information();
	void player2Information();
	void player3Information();

	inline void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }
	inline void setItemAddressLink(Item* Item) { _Item = Item; }

	equipMenu();
	~equipMenu();
};

