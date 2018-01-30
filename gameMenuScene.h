#pragma once
#include "gameNode.h"

class playerManager;
class Item;

class gameMenuScene : public gameNode
{
private:
	int _cursorMenuNum;

	int _selectNum;

	int _alpha;

	bool _isMenu;
	bool _isCharater;

	int positiontemp;
	int positiontemp1;
	int _curGil;

	string _iswhere;

	playerManager* _pm;
	Item* _item;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();

	void playerInformation(int playerv);

	void playerposchange(int key);

	inline void setisWhere(string iswhere) { _iswhere = iswhere; }
	inline void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }
	inline void setItemAddressLink(Item* item) { _item = item; }

	gameMenuScene();
	~gameMenuScene();
};

