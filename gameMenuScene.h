#pragma once
#include "gameNode.h"

class gameMenuScene : public gameNode
{
private:
	int _cursorMenuNum;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();

	gameMenuScene();
	~gameMenuScene();
};

