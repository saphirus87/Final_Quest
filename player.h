#pragma once
#include "gameNode.h"

#define COMMAND1_POSY 580
#define COMMAND2_POSY 620
#define COMMAND3_POSY 660
#define COMMAND4_POSY 700

class player : public gameNode
{
protected:
	enum SKILL
	{
		FIRST_SKILL,
		SECOND_SKILL,
	};
	enum MOVEDIR
	{
		PLAYER_DOWN,
		PLAYER_UP,
		PLAYER_LEFT,
		PLAYER_RIGHT
	};
	enum BATTLE_MOTION
	{
		ATTACK_MOTION,
		ITEM_MOTION,
		MAGIC_MOTION,
		DEFFENCE_MOTION,
		RUN_MOTION,
		MOTION_END
	};
	enum BATTLE_COMAAND
	{
		ATTACK_COMMAND = 1,
		ITEM_COMMAND = 2,
		MAGIC_COMMAND = 4,
		RUN_COMMAND = 8,
		DEFFENCE_COMMAND = 16,
		ALL_COMMAND = ATTACK_COMMAND | ITEM_COMMAND | MAGIC_COMMAND | RUN_COMMAND | DEFFENCE_COMMAND
	};

protected:
	int _level;
	int _str, _int;				// 힘, 지력
	float _startTime, _endTime; // 속도 타이머 _startTime = 시작시간 / _endTime = 끝나는 시간  
								// _startTime 가 0.1씩 올라 _endTime 과 같으면 행동 실행 (예정)<------	

	int _x, _y;					// 플레이어 x,y 좌표
	int _frameX, _frameY;		// 프레임 좌표
						
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

	bool _isBattle;				// 배틀진행유무 true = 배틀 하고 있음, false = 배틀 안하고 있음 
	bool _isFight;				// 싸움유무 true = 싸우겟음, false = 안싸우겠음
	bool _isAttack;				// 공격 유무 true = 공격 가능, false 공격 불가능
	bool _isCommandReady;				// 플레이어 행동 준비 여부

	int _enableCommand;
	BATTLE_COMAAND _curCommand;

	MOVEDIR _dir;					// 상하좌우 판단
	SKILL _skill;					// 스킬 종류
	BATTLE_MOTION _battleMotion;	// 전투시 행동

	int _count;

public:
	player();
	~player();


	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(void) = 0;

	virtual void drawCommand(void);
	virtual void selectCommand(void);
	virtual void levelUp(void);

public:
	// getset 부분
	inline void setLevel(int Level) { _level = Level ; }
	inline int getLevel(void) { return _level; }

	inline void setStr(int Str) { _str = Str; }
	inline int getStr(void) { return _str; }

	inline void setInt(int Int) { _int = Int; }
	inline int getInt(void) { return _int; }

	inline void setStartTime(float StartTime) { _startTime = StartTime; }
	inline float getStartTime(void) { return _startTime; }

	inline void setEndTime(float EndTime) { _endTime = EndTime; }
	inline float getEndTime(void) { return _endTime; }

	inline void setMaxHp(int MaxHp) { _maxHp = MaxHp; }
	inline int getMaxHp(void) { return _maxHp; }

	inline void setCurrentHp(int CurrentHp) { _curruntHp = CurrentHp; }
	inline int getCurrentHp(void) { return _curruntHp; }

	inline void setMaxMp(int MaxMp) { _maxHp = MaxMp; }
	inline int getMaxMp(void) { return _maxMp; }

	inline void setCurrentMp(int CurrentMp) { _curruntMp = CurrentMp; }
	inline int getCurrentMp(void) { return _curruntMp; }

	inline void setMp(int Mp) { _mp = Mp; }
	inline int getMp(void) { return _mp; }

	inline void setDamage(int Damage) { _damage = Damage; }
	inline int getDamage(void) { return _damage; }

	inline void setMDamage(int m_damage) { _m_Damage = m_damage; }
	inline int getMDamage(void) { return _m_Damage; }

	inline void setMin(int Min) { _min = Min; }
	inline int getMin(void) { return _min; }

	inline void setMax(int Max) { _max = Max; }
	inline int getMax(void) { return _max; }

	inline void setM_Max(int m_Max) { _m_max = m_Max; }
	inline int getM_Max(void) { return _m_max; }

	inline void setExp(int Exp) { _exp = Exp; }
	inline int getExp(void) { return _exp; }

	inline void setMaxExp(int MaxExp) { _maxExp = MaxExp; }
	inline int getMaxExp(void) { return _maxExp; }

	inline void setCurrentExp(int CurrentExp) { _curruntExp = CurrentExp; }
	inline int getCurrentExp(void) { return _curruntExp; }

	inline void setIsDead(bool IsDead) { _isDead = IsDead; }
	inline bool getIsDead(void) { return _isDead; }

	inline void setIsAttack(bool IsAttack) { _isAttack = IsAttack; }
	inline bool getIsAttack(void) { return _isAttack; }
};

