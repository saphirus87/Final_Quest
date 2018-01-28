#pragma once
#include <vector>
#include "player1.h"
#include "player2.h"
#include "player3.h"

class playerManager
{

private:
	typedef vector<player*> vPlayer;

private:
	vPlayer _vPlayer;

public:
	playerManager();
	~playerManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void updateActGauge(void);
	BOOL isCommandReady(void);

	vector<player*> getvplayer() { return _vPlayer; }
	void resetActGauge(void);
};

