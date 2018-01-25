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
	IMAGEMANAGER->addFrameImage("knight_attack", "enemyimages/attack.bmp", 370, 19, 2, 1, true, RGB(25, 0, 255));
	_curruntHp = _maxHp = 50;
	_curruntMp = _maxMp = 50;
	_str = _int = 5;
	_def = 1;
	_m_Def = 1;
	//���� ���ݷ¹���
	_MIN = _str;
	_MAX = _str*1.5;
	_damage = RND->getFromIntTo(_MIN, _MAX);

	//��ų ���ݷ� ����
	_m_MIN = _int;
	_m_MAX = _int *3;
	_m_Damage = RND->getFromIntTo(_m_MIN, _m_MAX);

	//���
	_MINgold = 9;
	_MAXgold = 14;
	_gold = RND->getFromFloatTo(_MINgold, _MAXgold);
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

	//���� ������
	if (attack_state==ATTACK)
	{
		frameCount++;
		if (frameCount >= IMAGEMANAGER->findImage("attack")->getMaxFrameX())
		{
			frameCount = 0;
			attack_state = NONE;
		}
		IMAGEMANAGER->findImage("attack")->setFrameX(frameCount);
	}

	//��ų�Ҹ�
}

void knight::render(HDC hdc)
{
	img->alphaRender(getMemDC(), 200,300, _alpha);

	if (attack_state == ATTACK)
		IMAGEMANAGER->findImage("attack")->frameRender(hdc, 200, 500,
			IMAGEMANAGER->findImage("attack")->getFrameX(),
			IMAGEMANAGER->findImage("attack")->getFrameY());
}
