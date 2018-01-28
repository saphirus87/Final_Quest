#pragma once
#include "gameNode.h"

class playerManager;

class abilitiesMenu : public gameNode
{
private:
	int _cursorMenuNum;

	bool _isCharater1;
	bool _isCharater2;
	bool _isCharater3;

	playerManager* _pm;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();

	inline void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }

	abilitiesMenu();
	~abilitiesMenu();
};

