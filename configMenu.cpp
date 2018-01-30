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
	
	DLCMANAGER->addDLC("BGM", false);
	DLCMANAGER->addDLC("Effect", false);
	DLCMANAGER->addDLC("MP3", false);
	DLCMANAGER->addDLC("reverb", false);
	DLCMANAGER->addDLC("musicSpeed", false);
	DLCMANAGER->addDLC("LowFrequency", false);
	DLCMANAGER->addDLC("Mp3MaxVolume", false);
	DLCMANAGER->addDLC("LeftSpeaker", false);



	//선택을 위한 변수
	_cursorMenuNum = 1;
	_musicSpeed = 1.0;

	//볼륨 조절을 위한 변수
	_effectVolume = 1;
	_musicVolume = 1;
	_musicTitle = SOUNDMANAGER->getTagTitle(true);

	return S_OK;
}

void configMenu::release()
{

}

void configMenu::update()
{
	if (DLCMANAGER->findDLC("LeftSpeaker"))
	{
		SOUNDMANAGER->setPan(0);
	}
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
		SOUNDMANAGER->setMusicVolume(0.6f);
	}
	if (_musicVolume == 3)
	{
		IMAGEMANAGER->findImage("low")->render(getMemDC(), 386, 157);
		SOUNDMANAGER->setMusicVolume(0.2f);
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
		SOUNDMANAGER->setEffectVolume(0.6f);
	}
	if (_effectVolume == 3)
	{
		IMAGEMANAGER->findImage("low")->render(getMemDC(), 386, 262);
		SOUNDMANAGER->setEffectVolume(0.2f);
	}
	if (_effectVolume == 4)
	{
		IMAGEMANAGER->findImage("off")->render(getMemDC(), 386, 262);
		SOUNDMANAGER->setEffectVolume(0.0f);
	}

	if (!DLCMANAGER->findDLC("BGM"))
	{
		SOUNDMANAGER->setMusicVolume(0.0f);
	}
	if (!DLCMANAGER->findDLC("Effect"))
	{
		SOUNDMANAGER->setEffectVolume(0.0f);
	}

	HFONT hFont = CreateFont(30, 0, 0, 0, 600, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, VARIABLE_PITCH | FF_ROMAN, TEXT("consolas"));
	HFONT oFont = (HFONT)SelectObject(getMemDC(), hFont);


	SetTextColor(getMemDC(), RGB(255, 255, 0));
	SetBkMode(getMemDC(), TRANSPARENT);

	if (DLCMANAGER->findDLC("MP3"))
	{
		TextOut(getMemDC(), WINSIZEX / 2 + 53, 482, _musicTitle.c_str(), strlen(_musicTitle.c_str()));
	}
	SetTextColor(getMemDC(), RGB(255, 255, 0));

	
	SelectObject(getMemDC(), oFont);
	DeleteObject(hFont);
	DeleteObject(oFont);

}

void configMenu::keyControl()
{

	if (DLCMANAGER->findDLC("musicSpeed"))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_ADD))
		{
		}
		if (KEYMANAGER->isOnceKeyDown(VK_SUBTRACT))
		{
			SOUNDMANAGER->setFrequency(-500);
		}
	}

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
		if (_cursorMenuNum == 4)
		{
			_musicTitle= SOUNDMANAGER->getTagTitle(true);
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

		if (_cursorMenuNum == 4)
		{
			_musicTitle=SOUNDMANAGER->getTagTitle(false);
		}
	}
	
	if (KEYMANAGER->isOnceKeyDown(VK_BACK))
	{
		SCENEMANAGER->changeScene("메뉴씬", FALSE);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN)&& DLCMANAGER->findDLC("MP3"))
	{
		SOUNDMANAGER->play("배틀");
		SOUNDMANAGER->stop("배틀");
		SOUNDMANAGER->currentPlay();

		if (!DLCMANAGER->findDLC("LowFrequency"))
		{
			SOUNDMANAGER->reverseHighPass(false);
		}
		if(!DLCMANAGER->findDLC("reverb"))
		{
			SOUNDMANAGER->setReverb();
			SOUNDMANAGER->reverbOn();
		}
		if(!DLCMANAGER->findDLC("musicSpeed"))
		{
			SOUNDMANAGER->setFrequency(2);
		}
		if (!DLCMANAGER->findDLC("Mp3MaxVolume"))
		{
			SOUNDMANAGER->setMP3Volume(0.2);
		}
		else if (DLCMANAGER->findDLC("Mp3MaxVolume"))
		{
			SOUNDMANAGER->setMP3Volume(1);
		}
	}
}

//void configMenu::cursorReset()
//{
//}
