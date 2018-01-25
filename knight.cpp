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
	_endTime = 19.0f;
	img = IMAGEMANAGER->addImage("knight", "enemyimages/knight.bmp", 92, 122, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("knight_hit", "enemyimages/knight_hit.bmp", 96, 120, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("knight_die", "enemyimages/knight_die.bmp", 96, 120, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("knight_attack", "enemyimages/knight_attack.bmp", 259, 128, 4, 1, true, RGB(255, 0, 255));
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
		if (count % 10 == 0)
		{
			frameCount++;
			if (frameCount >= IMAGEMANAGER->findImage("knight_attack")->getMaxFrameX())
			{
				frameCount = 0;
				attack_state = NONE;
			}
			IMAGEMANAGER->findImage("knight_attack")->setFrameX(frameCount);
		}
	}

	//��ų�Ҹ�
}

void knight::render(HDC hdc)
{
	switch (state)
	{
	case LIFE_NONE:
		img->alphaRender(hdc, 240, 100, _alpha);
		break;
	case HIT:
		IMAGEMANAGER->findImage("knight_hit")->render(hdc, 240, 100);
		break;
	case DIE:
		IMAGEMANAGER->findImage("knight_die")->alphaRender(hdc, 240, 100, _alpha);
		break;
	default:
		break;
	}
	

	if (attack_state == ATTACK)
		IMAGEMANAGER->findImage("knight_attack")->frameRender(hdc, 540, 100,
			IMAGEMANAGER->findImage("knight_attack")->getFrameX(),
			IMAGEMANAGER->findImage("knight_attack")->getFrameY());
}
