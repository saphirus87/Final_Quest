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
	isReflex = false; //디펜스모드일때 트루됨
	isAttack = false;
	_startTime = 0.0f;
	_endTime = 5.0f;
	_currentHp = _maxHp = 370;
	_currentMp = _maxMp = 60;
	_str = _int = 16;
	_def = 3;
	_m_Def = 5;
	//물리 공격력범위
	_MIN = _str;
	_MAX = _str*2;
	_damage = RND->getFromIntTo(_MIN, _MAX);

	//스킬 공격력 범위
	_m_MIN = _int;
	_m_MAX = _int * 2.5;
	_m_Damage = RND->getFromIntTo(_m_MIN, _m_MAX);

	//골드
	_MINgold = 300;
	_MAXgold = 377;
	_gold = RND->getFromFloatTo(_MINgold, _MAXgold);
	//경험치
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

	//죽어라~~~~
	if (_currentHp <= 0)
	{
		state = DIE;
		_alpha--;
	}

}

void Boss::render(HDC hdc)
{//보통상태일때
	IMAGEMANAGER->findImage("body")->alphaRender(hdc, 200, 300, _alpha); //바디알파 일단보류
	img->alphaRender(getMemDC(), 200, 500, _alpha);
}



void Boss::bossAttack()
{
	if (state == LIFE_NONE)
	{
		//타임 셋팅부분
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
				attack_state = SKILL;      //스킬
				SOUNDMANAGER->play("71.boss_reflex", 0.7f);
				_currentMp -= 20;
				isAttack = false;
			}
			else if (_attack = 1)
			{
				attack_state = DEFENSE;     //방어 _startTime
											//if 플레이어가 공격하면  isRefleex = true;
				isAttack = false;
			}
			else
			{
				//일반공격
				attack_state = ATTACK;      //일반공격
				isAttack = false;
				//떄리는소리 사운드매니저로
			}
		}
	}
}

