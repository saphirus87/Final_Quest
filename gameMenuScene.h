#pragma once
#include "gameNode.h"

class playerManager;

class gameMenuScene : public gameNode
{
private:
	int _cursorMenuNum;

	int _selectNum;

	int _alpha;

	bool _isMenu;
	bool _isCharater;

	int positiontemp;
	int positiontemp1;

	string _iswhere;

	playerManager* _pm;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();

	void playerInformation(int playerv);

	void playerposchange(int key);

	inline void setisWhere(string iswhere) { _iswhere = iswhere; }
	inline void setPlayerManagerAddressLink(playerManager* pm) { _pm = pm; }

	gameMenuScene();
	~gameMenuScene();
};

