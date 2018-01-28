#pragma once
#include "gameNode.h"

class gameMenuScene : public gameNode
{
private:
	int _cursorMenuNum;

	int _alpha;

	bool _isMenu;

	string _iswhere;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();

	void setisWhere(string iswhere) { _iswhere = iswhere; }

	gameMenuScene();
	~gameMenuScene();
};

