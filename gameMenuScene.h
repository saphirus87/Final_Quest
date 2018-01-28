#pragma once
#include "gameNode.h"

class playerManager;

class gameMenuScene : public gameNode
{
private:
	int _cursorMenuNum;

	int _alpha;

	bool _isMenu;

	string _iswhere;

	playerManager* _pm;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();

	inline void setisWhere(string iswhere) { _iswhere = iswhere; }
	inline void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }

	gameMenuScene();
	~gameMenuScene();
};

