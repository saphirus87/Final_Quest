#include "stdafx.h"
#include "battleScene.h"
#include "playerManager.h"

battleScene::battleScene()
{
}


battleScene::~battleScene()
{
}

HRESULT battleScene::init(void) 
{
	totalExp = totalGold = 0;
	/////배틀씬 임시 이미지///
	IMAGEMANAGER->addImage("battleBackground","mapImage/battleBackground.bmp", 1136, 640, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("battleBox", ".//userInterface//BattleBox.bmp", 1024, 200, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("selectPointLeft", ".//SceneImage//selectPointLeft.bmp", 27, 27, true, RGB(255, 0, 255));
	isinit = false;
	_isVictory = false;
	_em = new enemyManager;
	
	return S_OK;
}

void battleScene::release(void) 
{

}

void battleScene::update(void)
{
	if (!isinit)
	{
		isinit = true;
		enemyPositionSetting();
	}

	if (!_isVictory)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_F4))
		{
			resetPlayerActGauge();
		}
		// 도망 커맨드 구현으로 불필요
		/*if (KEYMANAGER->isOnceKeyDown(VK_F10))
		{
		SCENEMANAGER->changeScene("fieldScene",false);
		}*/
		_em->update();
		//스타트타임이 엔드타임이 되서 on이되면 1,2,3중에 하나뽑는다
		//1이면 150 2면 300 3이면 450에 공격좌표들어가게 ㄱㄱ 


		enemyHitPlayer();
		playerHitEnemy();


		_pm->update();

		playerAction();

		if (!_pm->isCommandReady())
		{
			_pm->updateActGauge();		// 플레이어 행동 게이지 증가
			increaseEnemyTimer();
		}

		if (_em->getVenemy().size() == 0)
		{
			_isVictory = true;
		}
	}
	else
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
		{
			SCENEMANAGER->changeScene("fieldScene", FALSE);
		}
	}
}

void battleScene::render(void)
{
	IMAGEMANAGER->findImage("battleBackground")->render(getMemDC(),0,0);
	IMAGEMANAGER->findImage("battleBox")->render(getMemDC(), 0, 557);
	_em->render();
	_pm->render();

	targetSelectCursorDraw();
	takenDamageDraw();
}

void battleScene::playerAction(void)
{
	for (int i = 0; i < _pm->getvplayer().size(); i++)
	{
		if (_pm->getvplayer()[i]->getCommand()->selectCommand == ATTACK_COMMAND)
		{
			_playerDamage[i].damage = _pm->getvplayer()[i]->getCommand()->totalDamage;
			_playerDamage[i].pos = _pm->getvplayer()[i]->getCommand()->target - 1;
			_em->getVenemy()[_pm->getvplayer()[i]->getCommand()->target - 1]->
				enemysetCurrentHp(_em->getVenemy()[_pm->getvplayer()[i]->getCommand()->target - 1]->enemygetCurrentHp() - _pm->getvplayer()[i]->getCommand()->totalDamage);
			_pm->getvplayer()[i]->commandReset();
		}
	}
}

void battleScene::increaseEnemyTimer(void)
{
	for (int i = 0; i < _em->getVenemy().size(); i++)
	{
		_em->getVenemy()[i]->increaseTime();
	}
}

void battleScene::enemyPositionSetting()
{
	int rnd1 = RND->getFromIntTo(2, 3);

	for (int i = 0; i < rnd1; i++)
	{
		int rnd2 = RND->getFromFloatTo(1, 4);
		int x, y;
		int nameX, nameY;
		if (i == 0)
		{
			x = 200;
			y = 130;
			nameX = 20;
			nameY = 570;
		}
		else if (i == 1)
		{
			x = 150;
			y = 280;
			nameX = 20;
			nameY = 630;
		}
		else if (i == 2)
		{
			x = 100;
			y = 430;
			nameX = 20;
			nameY = 690;
		}
		switch (rnd2)
		{
		case 1:
			_em->set_wolf(x, y, nameX, nameY);
			totalGold += _em->getVenemy()[i]->getGold();
			totalExp += _em->getVenemy()[i]->getExp();
			break;
		case 2:
			_em->set_knight(x, y, nameX, nameY);
			totalGold += _em->getVenemy()[i]->getGold();
			totalExp += _em->getVenemy()[i]->getExp();
			break;
		case 3:
			_em->set_mammos(x, y, nameX, nameY);
			totalGold += _em->getVenemy()[i]->getGold();
			totalExp += _em->getVenemy()[i]->getExp();
		default:
			break;
		}
	}
}

void battleScene::enemyHitPlayer()
{
	for (int i = 0; i < _em->getVenemy().size(); i++)
	{
		for (int j = 0; j < _pm->getvplayer().size(); j++)
		{
			if (_em->getVenemy()[i]->GetAttackOn())
			{
				if (_em->getVenemy()[i]->enemygetPlayerTarget() == 1)
				{
					_pm->getvplayer()[0]->setCurrentHp(_pm->getvplayer()[0]->getCurrentHp() - _em->getVenemy()[i]->enemygetDamage());
				}
				if (_em->getVenemy()[i]->enemygetPlayerTarget() == 2)
				{
					_pm->getvplayer()[1]->setCurrentHp(_pm->getvplayer()[1]->getCurrentHp() - _em->getVenemy()[i]->enemygetDamage());
				}
				if (_em->getVenemy()[i]->enemygetPlayerTarget() == 3)
				{
					_pm->getvplayer()[2]->setCurrentHp(_pm->getvplayer()[2]->getCurrentHp() - _em->getVenemy()[i]->enemygetDamage());
				}
				_em->getVenemy()[i]->SetAttackOn(false);
				//	cout << j + 1 << " 번쨰" << _pm->getvplayer()[j]->getCurrentHp() << endl;
			}
		}
	}
}

void battleScene::playerHitEnemy()
{
	for (int i = 0; i < _em->getVenemy().size(); i++)
	{
		for (int j = 0; j < _pm->getvplayer().size(); j++)
		{
			//에너미가 적에게 맞으면
			//if (_pm->getvplayer()[j]->getCommand().damagetype == SKILL_DAMAGE ||
			//	_pm->getvplayer()[j]->getCommand().damagetype == NORMAL_DAMAGE)
			//{
			//	_em->getVenemy()[i]->enemysetState(HIT);
			//}



			//임시 테스트 DIE값 HIT값 
			if (KEYMANAGER->isOnceKeyDown('W'))
			{
				_em->getVenemy()[i]->enemysetState(HIT);
				_em->getVenemy()[i]->enemysetCurrentHp(_em->getVenemy()[i]->enemygetCurrentHp() - 30);
				cout << _em->getVenemy()[i]->enemygetCurrentHp() << endl;
			}
			if (_em->getVenemy().size() > 0)
			{
				if (_em->getVenemy()[i]->enemygetState() == DIE)
				{
					if (_em->getVenemy()[i]->getAlpha() == 0)
						_em->enemyErase(i);
				}
			}
		}
	}
}

void battleScene::targetSelectCursorDraw(void)
{	
	for (int i = 0; i < _pm->getvplayer().size(); i++)
	{
		if (_pm->getvplayer()[i]->getSelectCommand() == ATTACK_COMMAND)
		{
			IMAGEMANAGER->findImage("selectPointLeft")->render(getMemDC(), _em->getVenemy()[_pm->getvplayer()[i]->getCommand()->target - 1]->getLeftPos(),
				50 + 150 * _pm->getvplayer()[i]->getCommand()->target);
		}
	}
}

void battleScene::takenDamageDraw(void)
{
	char playerDamage[3][64];
	char enemyDamage[3][64];

	for (int i = 0; i < _pm->getvplayer().size(); i++)
	{
		
		wsprintf(playerDamage[i], "%d", _playerDamage[i].damage);
	}

	for (int i = 0; i < _em->getVenemy().size(); i++)
	{
		wsprintf(enemyDamage[i], "%d", _enemyDamage[i].damage);
	}
	

	HFONT hFont = CreateFont(30, 0, 0, 0, 600, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("consolas"));
	HFONT oFont = (HFONT)SelectObject(getMemDC(), hFont);

	SetBkMode(getMemDC(), TRANSPARENT);
	SetTextColor(getMemDC(), RGB(220, 220, 220));
	for (int i = 0; i < _pm->getvplayer().size(); i++)
	{
		if (_pm->getvplayer()[i]->getIsDamageDraw()) TextOut(getMemDC(), 100, 100, playerDamage[i], strlen(playerDamage[i]));
	}

	for (int i = 0; i < _em->getVenemy().size(); i++)
	{
		//TextOut(getMemDC(), 100, 100, enemyDamage[i], strlen(enemyDamage[i]));
	}

	SelectObject(getMemDC(), oFont);
	DeleteObject(hFont);
	DeleteObject(oFont);
}

void battleScene::resetPlayerActGauge(void)
{
	for (int i = 0; i < _pm->getvplayer().size(); i++)
	{
		_pm->getvplayer()[i]->setCurActGauge(0);
		_pm->getvplayer()[i]->setIsCommandReady(false);
	}
}
