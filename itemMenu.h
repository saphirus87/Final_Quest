#pragma once
#include "gameNode.h"

class itemMenu : public gameNode
{
private:
	image* _itemScene;


public:
	HRESULT init();
	void release();
	void update();
	void render();

	itemMenu();
	~itemMenu();
};

