#pragma once
#include "gameNode.h"

class gameMenuScene : public gameNode
{
private:
	image* _menuScene;
	image* _selectCursor;

	int _cursorMenuNum;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void selectMove();

	gameMenuScene();
	~gameMenuScene();
};

