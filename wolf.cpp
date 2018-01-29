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
	state = LIFE_NONE;
	isAttack = false;
	_startTime = 0;
	_endTime = 1200;
	frame = 0;
	img = new image;
	img->init("enemyimages/wolf.bmp", 144, 116, true, RGB(255, 0, 255));

	img_hit = new image;
	img_hit->init("enemyimages/wolf_hit.bmp", 576, 116,4,1, true, RGB(255, 0, 255));

	img_die = new image;
	img_die->init("enemyimages/wolf_die.bmp", 114, 116, true, RGB(255, 0, 255));

	img_attack = new image;
	img_attack->init("enemyimages/wolf_attack.bmp", 600, 134, 3, 1, true, RGB(255, 0, 255));

	_currentHp = _maxHp = 45;
	_currentMp = _maxMp = 45;
	_str = _int = 4;
	_def = 1;
	_m_Def = 3;
	//물리 공격력범위
	_MIN = _str;
	_MAX = _str*1.7;
	_damage = RND->getFromIntTo(_MIN, _MAX);

	//스킬 공격력 범위
	_m_MIN = _int;
	_m_MAX = _int * 2.3;
	_m_Damage = RND->getFromIntTo(_m_MIN, _m_MAX);

	//골드
	_MINgold = 10;
	_MAXgold = 14;
	_gold = RND->getFromFloatTo(_MINgold, _MAXgold);
	//경험치
	_exp = 18;
	//
	_name = "wolf";
	return S_OK;
}

void wolf::release()
{
}

void wolf::update()
{
	enemy::update();

	count++;
	if (count % 40 == 0)
	{
		_damage = RND->getFromIntTo(_MIN, _MAX);
	}
	Attack(_damage);
	if (attack_state == ATTACK)
	{
		if (count % 10 == 0)
		{
			frameCount++;
			if (frameCount >= img_attack->getMaxFrameX())
			{
				frameCount = 0;
				attack_state = NONE;
			}
			img_attack->setFrameX(frameCount);
		}
	}
	if (state == HIT)
	{
		if (count % 14 == 0)
		{
			frame++;
			if (frame > img_hit->getMaxFrameX())
			{
				frame = 0;
				state = LIFE_NONE;
			}
			img_hit->setFrameX(frame);
		}
	}

	//스킬소리
}

void wolf::render(HDC hdc)
{
	char hpPrint[128];
	wsprintf(hpPrint, "%d / %d", _currentHp, _maxHp);

	if (_isDebug) TextOut(getMemDC(), x + img->getWidth(), y, hpPrint, strlen(hpPrint));

	switch (state)
	{
	case LIFE_NONE:
		img->render(hdc, x, y);
		break;
	case HIT:
		img_hit->frameRender(hdc, x, y,img_hit->getFrameX(),img_hit->getFrameY());
		break;
	case DIE:
		img_die->alphaRender(hdc, x, y, _alpha);
		break;
	default:
		break;
	}

	if (attack_state == ATTACK)
	{
		//update->num =rnd->  if(num==1)
		if (battle.playerTarget == 1)  img_attack->frameRender(hdc, x + 300, 150, img_attack->getFrameX(), img_attack->getFrameY());
		else if (battle.playerTarget == 2) img_attack->frameRender(hdc, x + 300, 300, img_attack->getFrameX(), img_attack->getFrameY());
		else img_attack->frameRender(hdc, x + 300, 450, img_attack->getFrameX(), img_attack->getFrameY());
	}
	HFONT hFont = CreateFont(30, 0, 0, 0, 600, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("consolas"));
	HFONT oFont = (HFONT)SelectObject(getMemDC(), hFont);

	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextColor(getMemDC(), RGB(220, 220, 220));

	TextOut(hdc, 20, namePositionY, "wolf", strlen("wolf"));
	SelectObject(getMemDC(), oFont);
	DeleteObject(hFont);
	DeleteObject(oFont);

}
