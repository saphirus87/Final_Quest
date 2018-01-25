#pragma once
#include "gameNode.h"
enum STATE
{
	LIFE_NONE,
	HIT,
	DIE
};
enum ATTACK_STATE
{
	ATTACK,
	SKILL, //������
	DEFENSE,
	NONE
};
class enemy : public gameNode
{
protected:

	int frameCount, count;
	STATE state;
	ATTACK_STATE attack_state;
	image* img;
	image* img_hit;
	image* img_die;
	image* img_attack;
	int _str, _int;
	float _startTime, _endTime, _stmn;
	int _maxHp, _curruntHp;
	int _maxMp, _curruntMp;
	//���ݷ� , ��ų���ݷ�
	int _damage, _m_Damage;
	//���� ����
	int _def, _m_Def;

	//���� ���ݷ� ����
	int _MIN, _MAX;
	//��ų ���ݷ� ����
	int _m_MIN, _m_MAX;
	//��� ȹ�����
	int _MINgold, _MAXgold;
	int _gold, _exp;
	//on�Ǹ� ���� off�Ǹ� ���ݺҰ���
	bool isAttack;
	//�������� ������ ��ų���� �Ϲݰ�������
	int _attack;
	//���İ����� ����
	int _alpha;

	int x, y;

public:
	enemy();
	~enemy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(HDC hdc);
	virtual void Attack();
	virtual void endAttack();
	virtual void enemySound();

	virtual void SetPostion(int xx, int yy)
	{
		x = xx;
		y = yy;
	}

	void enemysetCurrentHp(int CurrentHp) { _curruntHp = CurrentHp; }
	int enemygetCurrentHp(void) { return _curruntHp; }

	void enemysetMaxMp(int MaxMp) { _maxHp = MaxMp; }
	int enemygetMaxMp(void) { return _maxMp; }

	void enemysetDamage(int Damage) { _damage = Damage; }
	int enemygetDamage(void) { return _damage; }

	void enemysetMDamage(int m_damage) { _m_Damage = m_damage; }
	int enemygetMDamage(void) { return _m_Damage; }

	void setExp(int Exp) { _exp = Exp; }
	int getExp(void) { return _exp; }
};

