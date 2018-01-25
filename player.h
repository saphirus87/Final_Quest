#pragma once
#include "gameNode.h"

enum SKILL
{
	FIRST_SKILL,
	SECOND_SKILL,
	LAST_SKILL
};
enum MOVEDIR
{
	PLAYER_DOWN,
	PLAYER_UP,
	PLAYER_LEFT,
	PLAYER_RIGHT
};
enum BATTLE
{
	ATTACK,
	ITEM,
	MAGIC,
	DEFFENCE,
	RUN
};



class player : public gameNode
{
protected:
	image * _img;
	int _level;
	int _str, _int;				// 힘, 지력
	float _startTime, _endTime; // 속도 타이머 _startTime = 시작시간 / _endTime = 끝나는 시간  
								// _startTime 가 0.1씩 올라 _endTime 과 같으면 행동 실행 (예정)<------	

	int _x, _y;					// 플레이어 x,y 좌표
	int _frameX, _frameY;
						
	int _maxHp, _curruntHp;		// 체력
	int _maxMp, _curruntMp;		// 마나
	int _mp;					// 소비마나
	int _damage, _m_Damage;		// 물리공격력, 마법공격력
	int _min, _max;				// 물리 최소공격력, 최대공격력
	int _m_min, _m_max;			// 마력 최소공격력, 최대공격력
	int _def, _m_def;			// 물리방어력, 마법방어력
	int _gold;					// 골드
	int _exp;					// 경험치
	int _maxExp;				// 최대경험치
	int _curruntExp;			// 현재경험치
	bool _isDead;				// 사망유무 true = 생존 , false 죽음
	bool _isAttack;				// 공격 유무 true = 공격 가능, false 공격 불가능 

	MOVEDIR _dir;				// 상하좌우 판단
	SKILL _skill;				// 스킬 종류
	BATTLE _battle;				// 전투시 행동

	int _count;



public:
	player();
	~player();


	HRESULT init();
	void release();
	void update();
	void render(HDC hdc);

	void attack();




	// getset 부분
	void setLevel(int Level) { _level = Level ; }
	int getLevel(void) { return _level; }


	void setStr(int Str) { _str = Str; }
	int getStr(void) { return _str; }

	void setInt(int Int) { _int = Int; }
	int getInt(void) { return _int; }

	void setStartTime(float StartTime) { _startTime = StartTime; }
	float getStartTime(void) { return _startTime; }

	void setEndTime(float EndTime) { _endTime = EndTime; }
	float getEndTime(void) { return _endTime; }

	void setMaxHp(int MaxHp) { _maxHp = MaxHp; }
	int getMaxHp(void) { return _maxHp; }

	void setCurrentHp(int CurrentHp) { _curruntHp = CurrentHp; }
	int getCurrentHp(void) { return _curruntHp; }

	void setMaxMp(int MaxMp) { _maxHp = MaxMp; }
	int getMaxMp(void) { return _maxMp; }

	void setCurrentMp(int CurrentMp) { _curruntMp = CurrentMp; }
	int getCurrentMp(void) { return _curruntMp; }

	void setMp(int Mp) { _mp = Mp; }
	int getMp(void) { return _mp; }

	void setDamage(int Damage) { _damage = Damage; }
	int getDamage(void) { return _damage; }

	void setMDamage(int m_damage) { _m_Damage = m_damage; }
	int getMDamage(void) { return _m_Damage; }

	void setMin(int Min) { _min = Min; }
	int getMin(void) { return _min; }

	void setMax(int Max) { _max = Max; }
	int getMax(void) { return _max; }

	void setM_Max(int m_Max) { _m_max = m_Max; }
	int getM_Max(void) { return _m_max; }

	void setExp(int Exp) { _exp = Exp; }
	int getExp(void) { return _exp; }

	void setMaxExp(int MaxExp) { _maxExp = MaxExp; }
	int getMaxExp(void) { return _maxExp; }

	void setCurrentExp(int CurrentExp) { _curruntExp = CurrentExp; }
	int getCurrentExp(void) { return _curruntExp; }

	void setIsDead(bool IsDead) { _isDead = IsDead; }
	bool getIsDead(void) { return _isDead; }

	void setIsAttack(bool IsAttack) { _isAttack = IsAttack; }
	bool getIsAttack(void) { return _isAttack; }
};

