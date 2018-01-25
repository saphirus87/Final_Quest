#include "stdafx.h"
#include "mammos.h"


mammos::mammos()
{
}


mammos::~mammos()
{
}

HRESULT mammos::init()
{
	enemy::init();
	img = IMAGEMANAGER->addImage("mammos", "enemyimages/mammos.bmp", 63, 48, true, RGB(255, 0, 255));
	isAttack = false;
	_startTime = 0.0f;
	_endTime = 5.0f;
	_curruntHp = _maxHp = 60;
	_curruntMp = _maxMp = 60;
	_str = Int = 3;
	_def = 2;
	m_Def = 2;
	//���� ���ݷ¹���
	_MIN = Str;
	_MAX = Str*1.3;
	_damage = RND->getFromIntTo(MIN, MAX);

	//��ų ���ݷ� ����
	m_MIN = Int;
	m_MAX = Int * 2;
	m_Damage = RND->getFromIntTo(m_MIN, m_MAX);

	//���
	_MINgold = 10;
	_MAXgold = 15;
	_gold = RND->getFromFloatTo(MINgold, MAXgold);
	//����ġ
	_exp = 21;
	return S_OK;
}

void mammos::release()
{
}

void mammos::update()
{
	enemy::update();
	cout << "����" << endl;

	//��ų�Ҹ�
}

void mammos::render()
{
	img->alphaRender(getMemDC(), 200, 300,_alpha);
}
