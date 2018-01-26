#pragma once
#include "gameNode.h"

class gameSaveLoadScene : public gameNode
{
private:

public:
	HRESULT init();
	void release();
	void update();
	void render();

	gameSaveLoadScene();
	~gameSaveLoadScene();
};

