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

	void set_wolf();
	void set_knight();
	void set_mammos();
	void set_boss();
};

