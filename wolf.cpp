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
	img = IMAGEMANAGER->addImage("wolf", "enemyimages/wolf.bmp", 48, 48, true, RGB(255, 0, 255));
	curruntHp = maxHp = 45;
	curruntMp = maxMp = 45;
	Str = Int = 4;
	Def = 1;
	m_Def = 3;
	//���� ���ݷ¹���
	MIN = Str;
	MAX = Str*1.7;
	Damage = RND->getFromIntTo(MIN, MAX);

	//��ų ���ݷ� ����
	m_MIN = Int;
	m_MAX = Int * 2.3;
	m_Damage = RND->getFromIntTo(m_MIN, m_MAX);

	//���
	MINgold = 10;
	MAXgold = 14;
	gold = RND->getFromFloatTo(MINgold, MAXgold);
	//����ġ
	exp = 18;
	return S_OK;
}

void wolf::release()
{
}

void wolf::update()
{
}

void wolf::render()
{
}
