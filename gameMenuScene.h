#pragma once
#include "gameNode.h"

class gameMenuScene : public gameNode
{
private:
	int _cursorMenuNum;

	int _alpha;

	bool _isMenu;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();

	gameMenuScene();
	~gameMenuScene();
};

