#pragma once
#include "gameNode.h"

class saveLoadMenu : public gameNode
{
private:
	image* _saveLoadScene;
	image* _selectCursor;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	saveLoadMenu();
	~saveLoadMenu();
};

