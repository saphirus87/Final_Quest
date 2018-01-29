#include "stdafx.h"
#include "Boss.h"


Boss::Boss()
{
}


Boss::~Boss()
{
}

HRESULT Boss::init()
{
	enemy::init();
	boss_StartTime = 0.08;
	img = IMAGEMANAGER->addImage("head","boss_head.bmp" ,42, 36, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("body", "boss_body.bmp", 67, 65, true, RGB(255, 0, 255));
	isReflex = false; //���潺����϶� Ʈ���
	isAttack = false;
	_startTime = 0.0f;
	_endTime = 5.0f;
	_currentHp = _maxHp = 370;
	_currentMp = _maxMp = 60;
	_str = _int = 16;
	_def = 3;
	_m_Def = 5;
	//���� ���ݷ¹���
	_MIN = _str;
	_MAX = _str*2;
	_damage = RND->getFromIntTo(_MIN, _MAX);

	//��ų ���ݷ� ����
	_m_MIN = _int;
	_m_MAX = _int * 2.5;
	_m_Damage = RND->getFromIntTo(_m_MIN, _m_MAX);

	//���
	_MINgold = 300;
	_MAXgold = 377;
	_gold = RND->getFromFloatTo(_MINgold, _MAXgold);
	//����ġ
	_exp = 250;
	//
	return S_OK;
}

void Boss::release()
{
}

void Boss::update()
{
	bossAttack();

	//�׾��~~~~
	if (_currentHp <= 0)
	{
		state = DIE;
		_alpha--;
	}

}

void Boss::render(HDC hdc)
{//��������϶�
	IMAGEMANAGER->findImage("body")->alphaRender(hdc, 200, 300, _alpha); //�ٵ���� �ϴܺ���
	img->alphaRender(getMemDC(), 200, 500, _alpha);
}



void Boss::bossAttack()
{
	if (state == LIFE_NONE)
	{
		//Ÿ�� ���úκ�
		if (_startTime >= _endTime)
		{
			_startTime = 0;
			isAttack = true;
		}
		if (!isAttack)
			_startTime += boss_StartTime;

		else if (isAttack) 
		{
			_attack = RND->getFromIntTo(0, 5);
			if (_attack = 0 && _currentMp >= 20)
			{
				attack_state = SKILL;      //��ų
				SOUNDMANAGER->play("71.boss_reflex", 0.7f);
				_currentMp -= 20;
				isAttack = false;
			}
			else if (_attack = 1)
			{
				attack_state = DEFENSE;     //��� _startTime
											//if �÷��̾ �����ϸ�  isRefleex = true;
				isAttack = false;
			}
			else
			{
				//�Ϲݰ���
				attack_state = ATTACK;      //�Ϲݰ���
				isAttack = false;
				//�����¼Ҹ� ����Ŵ�����
			}
		}
	}
}

