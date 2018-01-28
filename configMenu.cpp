#include "stdafx.h"
#include "configMenu.h"


configMenu::configMenu()
{
}


configMenu::~configMenu()
{

}

HRESULT configMenu::init()
{
	//옵션씬 이미지
	IMAGEMANAGER->addImage("옵션씬", ".\\SceneImage\\configMenu.bmp", 1024, 760, true, RGB(255, 0, 255));
	//옵션씬 손 이미지
	IMAGEMANAGER->addImage("선택", ".\\SceneImage\\selectPoint.bmp", 27, 27, true, RGB(255, 0, 255));

	// 버튼 이미지 ///////////////////////////////////////////////////////////////////////////
	IMAGEMANAGER->addImage("high", ".\\SceneImage\\high.bmp", 552, 61, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("medium", ".\\SceneImage\\medium.bmp", 552, 61, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("low", ".\\SceneImage\\low.bmp", 552, 61, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("off", ".\\SceneImage\\off.bmp", 552, 61, true, RGB(255, 0, 255));
	/////////////////////////////////////////////////////////////////////////////////////////
	
	//선택을 위한 변수
	_cursorMenuNum = 1;

	//볼륨 조절을 위한 변수
	_effectVolume = 1;
	_musicVolume = 1;

	return S_OK;
}

void configMenu::release()
{

}

void configMenu::update()
{
	keyControl();
}

void configMenu::render()
{
	//옵션씬 이미지
	IMAGEMANAGER->findImage("옵션씬")->render(getMemDC(), 0, 0);

	//옵션씬 선택 이미지
	if (_cursorMenuNum == 1)
	{
		IMAGEMANAGER->findImage("선택")->render(getMemDC(), 60, 175);
	}
	if (_cursorMenuNum == 2)
	{
		IMAGEMANAGER->findImage("선택")->render(getMemDC(), 60, 282);
	}
	if (_cursorMenuNum == 3)
	{
		IMAGEMANAGER->findImage("선택")->render(getMemDC(), 60, 387);
	}
	if (_cursorMenuNum == 4)
	{
		IMAGEMANAGER->findImage("선택")->render(getMemDC(), 60, 492);
	}

	//배경음악 소리조절 선택
	if (_musicVolume == 1)
	{
		IMAGEMANAGER->findImage("high")->render(getMemDC(), 386, 157);
		SOUNDMANAGER->setMusicVolume(1.0f);
	}
	if (_musicVolume == 2)
	{
		IMAGEMANAGER->findImage("medium")->render(getMemDC(), 386, 157);
		SOUNDMANAGER->setMusicVolume(0.7f);
	}
	if (_musicVolume == 3)
	{
		IMAGEMANAGER->findImage("low")->render(getMemDC(), 386, 157);
		SOUNDMANAGER->setMusicVolume(0.35f);
	}
	if (_musicVolume == 4)
	{
		IMAGEMANAGER->findImage("off")->render(getMemDC(), 386, 157);
		SOUNDMANAGER->setMusicVolume(0.0f);
	}

	//이펙트 or 사운드 소리조절
	if (_effectVolume == 1)
	{
		IMAGEMANAGER->findImage("high")->render(getMemDC(), 386, 262);
		SOUNDMANAGER->setEffectVolume(1.0f);
	}
	if (_effectVolume == 2)
	{
		IMAGEMANAGER->findImage("medium")->render(getMemDC(), 386, 262);
		SOUNDMANAGER->setEffectVolume(0.7f);
	}
	if (_effectVolume == 3)
	{
		IMAGEMANAGER->findImage("low")->render(getMemDC(), 386, 262);
		SOUNDMANAGER->setEffectVolume(0.35);
	}
	if (_effectVolume == 4)
	{
		IMAGEMANAGER->findImage("off")->render(getMemDC(), 386, 262);
		SOUNDMANAGER->setEffectVolume(0.0f);
	}
}

void configMenu::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		SOUNDMANAGER->play("메뉴선택", 1.0f);
		if (_cursorMenuNum == 1) _cursorMenuNum = 4;
		else if (_cursorMenuNum == 2) _cursorMenuNum = 1;
		else if (_cursorMenuNum == 3) _cursorMenuNum = 2;
		else if (_cursorMenuNum == 4) _cursorMenuNum = 3;
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		SOUNDMANAGER->play("메뉴선택", 1.0f);
		if (_cursorMenuNum == 1) _cursorMenuNum = 2;
		else if (_cursorMenuNum == 2) _cursorMenuNum = 3;
		else if (_cursorMenuNum == 3) _cursorMenuNum = 4;
		else if (_cursorMenuNum == 4) _cursorMenuNum = 1;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		SOUNDMANAGER->play("메뉴선택", 1.0f);
		if (_cursorMenuNum == 1 && _musicVolume == 1)
		{
			_musicVolume = 1;
		}
		else if (_cursorMenuNum == 1 && _musicVolume == 2)
		{
			_musicVolume = 1;
		}
		else if (_cursorMenuNum == 1 && _musicVolume == 3)
		{
			_musicVolume = 2;
		}
		else if (_cursorMenuNum == 1 && _musicVolume == 4)
		{
			_musicVolume = 3;
		}
		//////////////////////////////////////////////////
		if (_cursorMenuNum == 2 && _effectVolume == 1)
		{
			_effectVolume = 1;
		}
		else if (_cursorMenuNum == 2 && _effectVolume == 2)
		{
			_effectVolume = 1;
		}
		else if (_cursorMenuNum == 2 && _effectVolume == 3)
		{
			_effectVolume = 2;
		}
		else if (_cursorMenuNum == 2 && _effectVolume == 4)
		{
			_effectVolume = 3;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		SOUNDMANAGER->play("메뉴선택", 1.0f);
		if (_cursorMenuNum == 1 && _musicVolume == 1)
		{
			_musicVolume = 2;
		}
		else if (_cursorMenuNum == 1 && _musicVolume == 2)
		{
			_musicVolume = 3;
		}
		else if (_cursorMenuNum == 1 && _musicVolume == 3)
		{
			_musicVolume = 4;
		}
		else if (_cursorMenuNum == 1 && _musicVolume == 4)
		{
			_musicVolume = 4;
		}
		//////////////////////////////////////////////////////////////////
		if (_cursorMenuNum == 2 && _effectVolume == 1)
		{
			_effectVolume = 2;
		}
		else if (_cursorMenuNum == 2 && _effectVolume == 2)
		{
			_effectVolume = 3;
		}
		else if (_cursorMenuNum == 2 && _effectVolume == 3)
		{
			_effectVolume = 4;
		}
		else if (_cursorMenuNum == 2 && _effectVolume == 4)
		{
			_effectVolume = 4;
		}
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("메뉴씬", FALSE);
	}
}

//void configMenu::cursorReset()
//{
//}
