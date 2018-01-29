#pragma once
#include "gameNode.h"
#define MIN_STMN 1
#define MAX_STMN 57
#define ALPHA_MAX_VALUE 255
enum STATE
{
	LIFE_NONE,
	HIT,
	DIE
};
enum ATTACK_STATE
{
	ATTACK,
	SKILL, //보스만
	DEFENSE,
	NONE
};
/////////////////////////////// 배틀씬에서 담아서 쓸 변수들
enum DAMAGETYPE
{
	SKILL_DAMAGE,
	NORMAL_DAMAGE
};
struct BATTLE
{
	int playerTarget;
	DAMAGETYPE damagetype;
	int totalDamage;
};
///////////////////////////////
class enemy : public gameNode
{
protected:
	string _name;
	BATTLE battle;
	int frameCount, count;
	STATE state;
	ATTACK_STATE attack_state;
	image* img;
	image* img_hit;
	image* img_die;
	image* img_attack;
	int _str, _int;
	int _startTime, _endTime, _stmn;
	int _maxHp, _currentHp;
	int _maxMp, _currentMp;
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
	int GOLD;
	int EXP;
	//on되면 공격 off되면 공격불가능
	bool isAttack;
	//랜덤으로 돌려서 스킬인지 일반공격인지
	int _attack;
	//알파값받을 변수
	int _alpha;

	int aimPlayer;
	int x, y;
	int namePositionX, namePositionY;
public:
	enemy();
	~enemy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	virtual void Attack(int damage);
	virtual void endAttack();
	virtual void enemySound();

	void increaseTime(void);

	virtual int getGold() { return GOLD; }
	virtual int getExp() { return _exp; }

	virtual void SetNamePosition(int x, int y)
	{
		namePositionX = x;
		namePositionY = y;
		
	}
	virtual void SetPosition(int positionX, int positionY)
	{
		x = positionX;
		y = positionY;
	}
	void enemysetCurrentHp(int CurrentHp) { _currentHp = CurrentHp; }
	int enemygetCurrentHp(void) { return _currentHp; }

	void enemysetDamage(int Damage) { _damage = Damage; }
	int enemygetDamage(void) { return _damage; }

	void enemysetMDamage(int m_damage) { _m_Damage = m_damage; }
	int enemygetMDamage(void) { return _m_Damage; }

	int enemygetPlayerTarget(void) { return battle.playerTarget; }

	/*void setExp(int Exp) { _exp = Exp; }
	int getExp(void) { return _exp; }*/

	inline BATTLE _battle() { return battle; }
	ATTACK_STATE enemygetAttackState() { return attack_state; }
	void enemysetState(STATE enemystate) { state = enemystate; }
	STATE enemygetState() { return state; }
	void nameInfo();

	int getAlpha() { return _alpha; }
	inline void setAttackState(ATTACK_STATE attackState) { attack_state = attackState; }
};

