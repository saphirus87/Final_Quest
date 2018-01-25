#include "stdafx.h"
#include "wolf.h"


wolf::wolf()
{
}


wolf::~wolf()
{
}

HRESULT wolf::init()
{
	enemy::init();
	isAttack = false;
	_startTime = 0.0f;
	_endTime = 5.0f;
	img = IMAGEMANAGER->addImage("wolf", "enemyimages/wolf.bmp", 48, 48, true, RGB(255, 0, 255));
	_curruntHp = _maxHp = 45;
	_curruntMp = _maxMp = 45;
	_str = Int = 4;
	_def = 1;
	_m_Def = 3;
	//���� ���ݷ¹���
	_MIN = Str;
	_MAX = Str*1.7;
	_damage = RND->getFromIntTo(MIN, MAX);

	//��ų ���ݷ� ����
	m_MIN = Int;
	m_MAX = Int * 2.3;
	m_Damage = RND->getFromIntTo(m_MIN, m_MAX);

	//���
	_MINgold = 10;
	_MAXgold = 14;
	_gold = RND->getFromFloatTo(MINgold, MAXgold);
	//����ġ
	_exp = 18;
	//
	return S_OK;
}

void wolf::release()
{
}

void wolf::update()
{
	enemy::update();
	cout << "����" << endl;

	//��ų�Ҹ�
}

void wolf::render()
{
	img->alphaRender(getMemDC(), 200, 500,_alpha);
}
