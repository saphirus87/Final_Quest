#pragma once 
#include "gameNode.h"
#include <vector>
#include "wolf.h"
#include "knight.h"
#include "mammos.h"//
#include "boss.h"

 
class enemyManager : public gameNode
{
private:
	typedef vector<enemy*> vV;
	typedef vector<enemy*>::iterator viV;

	vV venemy;
	viV vienemy;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void set_wolf(int x,int y);
	void set_knight(int x,int y);
	void set_mammos(int x,int y);
	void set_boss(int x,int y);

	void Hit();
	void enemyErase();

	//void PlayerSet(Player* one, Player* two, Player* Three);

};

