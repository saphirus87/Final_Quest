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

	BATTLE battle;

public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void set_wolf(int x,int y,int nameX,int nameY);
	void set_knight(int x,int y,int nameX,int nameY);
	void set_mammos(int x,int y,int nameX,int nameY);
	void set_boss(int x,int y);
	vector<enemy*> getVenemy() { return venemy; }
	vector<enemy*>::iterator getVienemy() { return vienemy; }

	void Hit();
	void enemyErase();

	//void PlayerSet(Player* one, Player* two, Player* Three);

};

