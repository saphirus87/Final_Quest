#pragma once
#include "gameNode.h"
enum STATE
{
	LIFE,
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
	int _str, _int;
	float _startTime, _endTime;
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
public:
	enemy();
	~enemy();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void Attack();
	virtual void enemySound();
};

