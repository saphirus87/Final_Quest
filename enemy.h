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

	//���� ���ݷ� ����
	int MIN, MAX;
	//��ų ���ݷ� ����
	int m_MIN, m_MAX;
	//��� ȹ�����
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

