#pragma once
#include "gameNode.h"
enum STATE
{
	LIFE,
	DIE
};
enum ATTACK_SKILL
{
	ATTACK,
	SKILL,
	NONE
};
class enemy : public gameNode
{
protected:
	STATE state;
	ATTACK_SKILL attack_skill;
	image* img;
	int _str, _int;
	float _startTime, _endTime;
	int _maxHp, _curruntHp;
	int _maxMp, _curruntMp;
	//공격력 , 스킬공격력
	int _damage, _m_Damage;
	//방어력 마방
	int _def, _m_Def;

	//물리 공격력 범위
	int _MIN, _MAX;
	//스킬 공격력 범위
	int _m_MIN, _m_MAX;
	//골드 획득범위
	int _MINgold, _MAXgold;
	int _gold, _exp;
	//on되면 공격 off되면 공격불가능
	bool isAttack;
	//랜덤으로 돌려서 스킬인지 일반공격인지
	int _attack;
	//알파값받을 변수
	int _alpha;
public:
	enemy();
	~enemy();

	HRESULT init();
	void release();
	void update();
	void render();
};

