#pragma once
#include "gameNode.h"

class playerManager;

class statusMenu : public gameNode
{
private:
	int _cursorMenuNum;
	int _selectNum;
	int _tempPos;

	playerManager* _pm;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();

	void playerInformation(int playerv);
	
	inline void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }

	statusMenu();
	~statusMenu();
};

