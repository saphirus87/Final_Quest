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

	/////배틀씬 임시 이미지///
	IMAGEMANAGER->addImage("battleBackground","mapImage/battleBackground.bmp", 1136, 640, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("battleBox", ".//userInterface//BattleBox.bmp", 1024, 200, true, RGB(255, 0, 255));
	
	_em = new enemyManager;
	enemyPositionSetting();
		
	int rnd1 = RND->getFromIntTo(2, 3);
	
	return S_OK;
}

void battleScene::release(void) 
{

}

void battleScene::update(void)
{
	// 도망 커맨드 구현으로 불필요
	/*if (KEYMANAGER->isOnceKeyDown(VK_F10))
	{
		SCENEMANAGER->changeScene("fieldScene",false);
	}*/
	_em->update();
	//스타트타임이 엔드타임이 되서 on이되면 1,2,3중에 하나뽑는다
	//1이면 150 2면 300 3이면 450에 공격좌표들어가게 ㄱㄱ 

	for (int i = 0; i < _em->getVenemy().size(); i++)
	{
		for (int j = 0; j < _pm->getvplayer().size(); j++)
		{
			if (_em->getVenemy()[i]->enemygetAttackState() == ATTACK)
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
				cout << j + 1 << " 번쨰" << _pm->getvplayer()[j]->getCurrentHp() << endl;
				_em->getVenemy()[i]->setAttackState(NONE);
			}
			//에너미가 적에게 맞으면
			//if (_pm->getvplayer()[j]->getCommand().damagetype == SKILL_DAMAGE ||
			//	_pm->getvplayer()[j]->getCommand().damagetype == NORMAL_DAMAGE)
			//{
			//	_em->getVenemy()[i]->enemysetState(HIT);
			//}
			if (KEYMANAGER->isOnceKeyDown('W'))
			{
				_em->getVenemy()[0]->enemysetState(HIT);
			}
		}
	}

	_pm->update();
	if (!_pm->isCommandReady()) _pm->updateActGauge();
}

void battleScene::render(void)
{
	IMAGEMANAGER->findImage("battleBackground")->render(getMemDC(),0,0);
	IMAGEMANAGER->findImage("battleBox")->render(getMemDC(), 0, 557);
	_em->render();
	_pm->render();
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
			y = 150;
			nameX = 20;
			nameY = 540;
		}
		else if (i == 1)
		{
			x = 200;
			y = 300;
			nameX = 20;
			nameY = 610;
		}
		else if (i == 2)
		{
			x = 200;
			y = 450;
			nameX = 20;
			nameY = 660;
		}
		switch (rnd2)
		{
		case 1:
			_em->set_wolf(x, y, nameX, nameY);
			break;
		case 2:
			_em->set_knight(x, y, nameX, nameY);
			break;
		case 3:
			_em->set_mammos(x, y, nameX, nameY);
		default:
			break;
		}
	}
}