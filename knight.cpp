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
	_startTime = 0;
	_endTime = 3000;
	//img = IMAGEMANAGER->addImage("knight", "enemyimages/knight.bmp", 92, 122, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("knight_hit", "enemyimages/knight_hit.bmp", 96, 120, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("knight_die", "enemyimages/knight_die.bmp", 96, 120, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("knight_attack", "enemyimages/knight_attack.bmp", 259, 128, 4, 1, true, RGB(255, 0, 255));

	img = new image;
	img->init("enemyimages/knight.bmp", 92, 122, true, RGB(255, 0, 255));

	img_hit = new image;
	img_hit->init("enemyimages/knight_hit.bmp", 368,122,4,1, true, RGB(255, 0, 255));

	img_die = new image;
	img_die->init("enemyimages/knight_die.bmp", 96, 120, true, RGB(255, 0, 255));

	img_attack = new image;
	img_attack->init("enemyimages/knight_attack.bmp", 199, 48, 4, 1, true, RGB(255, 0, 255));


	_currentHp = _maxHp = 50;
	_currentMp = _maxMp = 50;
	_str = _int = 5;
	_def = 1;
	_m_Def = 1;
	//물리 공격력범위
	_MIN = _str;
	_MAX = _str*1.5;
	_damage = RND->getFromIntTo(_MIN, _MAX);

	//스킬 공격력 범위
	_m_MIN = _int;
	_m_MAX = _int *3;
	_m_Damage = RND->getFromIntTo(_m_MIN, _m_MAX);

	//골드
	_MINgold = 9;
	_MAXgold = 14;
	_gold = RND->getFromFloatTo(_MINgold, _MAXgold);
	//경험치
	_exp = 17;
	frame = 0;

	_name = "knight";
	return S_OK;
}

void knight::release()
{
}

void knight::update()
{
	enemy::update();

	count++;
	if (count % 40 == 0)
	{
		_damage = RND->getFromIntTo(_MIN, _MAX);
	}
	Attack(_damage);
	//공격 프레임
	if (attack_state==ATTACK)
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

void knight::render(HDC hdc)
{
	char hpPrint[128];
	char startTime[128];
	wsprintf(hpPrint, "%d / %d", _currentHp, _maxHp);
	wsprintf(startTime, "%d / %d", _startTime, _endTime);

	if (_isDebug)
	{
		TextOut(getMemDC(), x + img->getWidth(), y, hpPrint, strlen(hpPrint));
		TextOut(getMemDC(), x + img->getWidth(), y + 10, startTime, strlen(startTime));
	}

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
		if (battle.playerTarget == 1)  img_attack->frameRender(hdc, 850, 150, img_attack->getFrameX(), img_attack->getFrameY());
		else if (battle.playerTarget == 2) img_attack->frameRender(hdc, 910, 300, img_attack->getFrameX(), img_attack->getFrameY());
		else img_attack->frameRender(hdc, 980, 450, img_attack->getFrameX(), img_attack->getFrameY());
	}

	HFONT hFont = CreateFont(30, 0, 0, 0, 600, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("consolas"));
	HFONT oFont = (HFONT)SelectObject(getMemDC(), hFont);

	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextColor(getMemDC(), RGB(220, 220, 220));

	//TextOut(hdc, 20, namePositionY, "knight", strlen("knight"));
	outlineTextOut(hdc, 20, namePositionY, "knight", RGB(220, 220, 220), RGB(0, 0, 0), 2);
	SelectObject(getMemDC(), oFont);
	DeleteObject(hFont);
	DeleteObject(oFont);
}
