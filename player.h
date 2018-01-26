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
	int _str, _int;				// ��, ����
	float _startTime, _endTime; // �ӵ� Ÿ�̸� _startTime = ���۽ð� / _endTime = ������ �ð�  
								// _startTime �� 0.1�� �ö� _endTime �� ������ �ൿ ���� (����)<------	

	int _x, _y;					// �÷��̾� x,y ��ǥ
	int _frameX, _frameY;		// ������ ��ǥ
						
	int _maxHp, _curruntHp;		// ü��
	int _maxMp, _curruntMp;		// ����
	int _mp;					// �Һ񸶳�
	int _damage, _m_Damage;		// �������ݷ�, �������ݷ�
	int _min, _max;				// ���� �ּҰ��ݷ�, �ִ���ݷ�
	int _m_min, _m_max;			// ���� �ּҰ��ݷ�, �ִ���ݷ�
	int _def, _m_def;			// ��������, ��������
	int _gold;					// ���
	int _exp;					// ����ġ
	int _maxExp;				// �ִ����ġ
	int _curruntExp;			// �������ġ

	bool _isDead;				// ������� true = ���� , false ����

	bool _isBattle;				// ��Ʋ�������� true = ��Ʋ �ϰ� ����, false = ��Ʋ ���ϰ� ���� 
	bool _isFight;				// �ο����� true = �ο����, false = �Ƚο����
	bool _isAttack;				// ���� ���� true = ���� ����, false ���� �Ұ���
	bool _isCommandReady;				// �÷��̾� �ൿ �غ� ����

	int _enableCommand;
	BATTLE_COMAAND _curCommand;

	MOVEDIR _dir;					// �����¿� �Ǵ�
	SKILL _skill;					// ��ų ����
	BATTLE_MOTION _battleMotion;	// ������ �ൿ

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
	// getset �κ�
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

