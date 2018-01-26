#pragma once
#include "gameNode.h"

class gameStartScene : public gameNode
{
private:
	int _cursorMenuNum;

	int _alpha;

	bool _isStart;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();


	gameStartScene();
	~gameStartScene();
};

