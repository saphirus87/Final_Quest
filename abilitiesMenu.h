#pragma once
#include "gameNode.h"

class abilitiesMenu : public gameNode
{
private:
	int _cursorMenuNum;

	bool _isCharater1;
	bool _isCharater2;
	bool _isCharater3;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();

	abilitiesMenu();
	~abilitiesMenu();
};

