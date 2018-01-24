#pragma once
#include "gameNode.h"

class gameStartScene : public gameNode
{
private:
	image* _startBackground;
	image* _selectCursor;

	int _cursorMenuNum;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	gameStartScene();
	~gameStartScene();
};

