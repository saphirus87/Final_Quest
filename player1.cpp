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
	//���� ���ݷ¹���
	_min = _str;
	_max = _str * 2;
	_damage = RND->getFromIntTo(_min, _max);

	//��ų ���ݷ� ����
	_m_min = _int;
	_m_min = _int * 2;
	_m_Damage = RND->getFromIntTo(_m_min, _m_max);

	// ���� ����ġ�� �ִ����ġ���� ũ�ų� ������ �ɷ�ġ�� ���������(�÷��̾�� ���ġ �ٸ��� �� ����)
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

	// �ο� �� �̸� �̹����� ��Ʋ ���·� �ٲ��
	if (_isFight)
	{
		_img = IMAGEMANAGER->findImage("player1Battle_Idle");
		// �ο����϶� �ൿ
		switch (_battle)
		{
			case ATTACK:
				//���� ���� �� ���� ����
				_startTime = 0;
			break;

			case ITEM:
				//�κ��丮 �ҷ��ͼ� ������ ��� �ǰ� ������ ��
				_startTime = 0;
			break;

			case MAGIC:
				// ��ų ������ ��ų��� �ٲٰ� ��ų ���� �� ��ų �̹��� ���� �� ����
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

	// ����ü���� 0�� �������� 0���� ũ�� ���������� 0���� �۰ų� ������ �̹����� �������� �ٲٰ� ���¸� �׾��ٰ� �����ض�
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
