#pragma once
#include "gameNode.h"

class playerManager;

class statusMenu : public gameNode
{
private:
	int _cursorMenuNum;

	bool _isCharater1;
	bool _isCharater2;
	bool _isCharater3;

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

	inline void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }

	statusMenu();
	~statusMenu();
};

