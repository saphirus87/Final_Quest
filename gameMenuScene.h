#pragma once
#include "gameNode.h"

class playerManager;

class gameMenuScene : public gameNode
{
private:
	int _cursorMenuNum;

	int _selectNum;
	int _currentNum;

	int _alpha;

	bool _isMenu;
	bool _isCharater1;
	bool _isCharater2;
	bool _isCharater3;

	string _iswhere;

	playerManager* _pm;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();

	void player1Information();
	void player2Information();
	void player3Information();

	inline void setisWhere(string iswhere) { _iswhere = iswhere; }
	inline void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }

	gameMenuScene();
	~gameMenuScene();
};

