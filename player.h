#pragma once
#include "gameNode.h"

enum SKILL
{
	FIRST_SKILL,
	SECOND_SKILL,
	LAST_SKILL
};

class player : public gameNode
{
protected:
	image * img;
	int _level;
	int _str, _int;				// ��, ����
	float _startTime, _endTime; // �ӵ� Ÿ�̸�
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
	int _currentExp;			// �������ġ
	bool _isDead;				// ������� true = ���� , false ����
	SKILL _skill;

public:
	player();
	~player();


	HRESULT init();
	void release();
	void update();
	void render();


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

	void setCurrentExp(int CurrentExp) { _currentExp = CurrentExp; }
	int getCurrentExp(void) { return _currentExp; }

	void setIsDead(bool IsDead) { _isDead = IsDead; }
	bool getIsDead(void) { return _isDead; }

};

