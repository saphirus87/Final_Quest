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

	HRESULT init();
	void release();
	void update();
	void render();
};

