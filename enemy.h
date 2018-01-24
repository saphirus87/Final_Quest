#pragma once
#include "gameNode.h"
class enemy : public gameNode
{
protected:
	image* img;
	int Str, Int;
	float Speed;
	int maxHp, curruntHp;
	int maxMp, curruntMp;
	int Damage, m_Damage;
	int Def, m_Def;

	//물리 공격력 범위
	int MIN, MAX;
	//스킬 공격력 범위
	int m_MIN, m_MAX;
	//골드 획득범위
	int MINgold, MAXgold;
	int gold, exp;

public:
	enemy();
	~enemy();

	HRESULT init();
	void release();
	void update();
	void render();
};

