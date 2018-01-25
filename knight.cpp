#include "stdafx.h"
#include "knight.h"


knight::knight()
{
}


knight::~knight()
{
}

HRESULT knight::init()
{
	enemy::init();
	isAttack = false;
	_startTime = 0.0f;
	_endTime = 5.0f;
	img = IMAGEMANAGER->addImage("knight", "enemyimages/knight.bmp", 32, 48, true, RGB(255, 0, 255));
	_curruntHp = _maxHp = 50;
	_curruntMp = _maxMp = 50;
	_str = _int = 5;
	_def = 1;
	_m_Def = 1;
	//���� ���ݷ¹���
	_MIN = Str;
	_MAX = Str*1.5;
	_damage = RND->getFromIntTo(MIN, MAX);

	//��ų ���ݷ� ����
	m_MIN = Int;
	m_MAX = Int * 3;
	m_Damage = RND->getFromIntTo(m_MIN, m_MAX);

	_//���
	_MINgold = 9;
	_MAXgold = 14;
	_gold = RND->getFromFloatTo(MINgold, MAXgold);
	//����ġ
	_exp = 17;
	return S_OK;
}

void knight::release()
{
}

void knight::update()
{
	enemy::update();
	cout << "����Ʈ" << endl;

	//��ų�Ҹ�
}

void knight::render()
{
	img->alphaRender(getMemDC(), 200, _alpha);
}
