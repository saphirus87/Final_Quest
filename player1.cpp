#include "stdafx.h"
#include "player1.h"


player1::player1()
{
}


player1::~player1()
{
}

HRESULT player1::init()
{
	_img = IMAGEMANAGER->addFrameImage("player1Move", ".//playerImage//player1Move.bmp", 84, 184, 3, 4, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("player1Battle_Idle", ".//playerImage//player1_attack_idle.bmp", 28, 43, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("player1Die", ".//playerImage//player1_die.bmp", 47, 24, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("player1Hurt", ".//playerImage//player1_hurt.bmp", 36, 45, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player1Skill", ".//playerImage//player1_skill.bmp", 54, 45, 2, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("player1Win", ".//playerImage//player1_win_motion.bmp", 446, 46, 4, 1, true, RGB(255, 0, 255));
	player::init();

	return S_OK;
}
void player1::release()
{


}
void player1::update()
{
	player::update();
	//물리 공격력범위
	_min = _str;
	_max = _str * 2;
	_damage = RND->getFromIntTo(_min, _max);

	//스킬 공격력 범위
	_m_min = _int;
	_m_min = _int * 2;
	_m_Damage = RND->getFromIntTo(_m_min, _m_max);

	// 현제 경험치가 최대경험치보다 크거나 같으면 능력치를 변경해줘라(플레이어마다 상승치 다르게 줄 예정)
	if (_curruntExp >= _maxExp)
	{
		_level = _level + 1;
		_curruntExp = 0;
		_maxExp = 100 * _level;
		_maxHp = 100 + 10 * _level;
		_maxMp = 100 + 10 * _level;
		_curruntHp = _maxHp;
		_curruntMp = _maxHp;
		_str = _str + 2;
		_int = _int + 2;

	}

	// 싸움 중 이면 이미지를 배틀 상태로 바꿔라
	if (_isFight)
	{
		_img = IMAGEMANAGER->findImage("player1Battle_Idle");
		// 싸움중일때 행동
		switch (_battle)
		{
			case ATTACK:
				//몬스터 지정 후 공격 실행
				_startTime = 0;
			break;

			case ITEM:
				//인벤토리 불러와서 아이템 사용 되게 만들어야 됨
				_startTime = 0;
			break;

			case MAGIC:
				// 스킬 시전시 스킬모션 바꾸고 스킬 선택 및 스킬 이미지 렌더 후 종료
				_img = IMAGEMANAGER->findImage("player1Skill");
				switch (_skill)
				{
				case FIRST_SKILL :
					break;
				case SECOND_SKILL :
					break;
				}
				_startTime = 0;
			break;

			case DEFFENCE:
				_def *= 2;
				_m_def *= 2;
				_startTime = 0;
			break;

			case RUN:
				_isBattle = false;
				_startTime = 0;
			break;
		
		}
	}

	// 현제체력이 0을 기준으로 0보다 크면 빠져나가고 0보다 작거나 같으면 이미지를 죽음으로 바꾸고 상태를 죽었다고 변경해라
	if (_isDead)
	{
		if (_curruntHp > 0) return;
		if (_curruntHp <= 0)
		{
			_img = IMAGEMANAGER->findImage("player1Die");
			_isDead = false;
		}
	}
}
void player1::render(HDC hdc)
{
	//player::render(hdc);
}
