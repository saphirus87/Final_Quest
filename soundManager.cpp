#include "stdafx.h"
#include "soundManager.h"


soundManager::soundManager()
{
}


soundManager::~soundManager()
{

}

HRESULT soundManager::init()
{
	//FMOD 사운드엔진 사용하려면 초기화
	System_Create(&_system);

	_system->init(TOTALSOUNDBUFFER, FMOD_INIT_NORMAL, NULL);

	_sound = new Sound*[TOTALSOUNDBUFFER];
	_channel = new Channel*[TOTALSOUNDBUFFER];

	ZeroMemory(_sound, sizeof(_sound));
	ZeroMemory(_channel, sizeof(_channel));




	//마스터그룹 추가된 모든 음악을 조절가능
	_system->getMasterChannelGroup(&_masterGroup);


	//이펙트 채널 그룹
	_system->createChannelGroup("channelEffect", &_effectGroup);

	//BGM 채널 그룹
	_system->createChannelGroup("channelMusic", &_musicGroup);

	_system->createChannelGroup("MP3Group", &_mp3Group);

	//마스터사운드그룹 추가
	_system->getMasterSoundGroup(&_masterSound);

	//노래 사운드 그룹	
	_system->createSoundGroup("musicSound", &_musicSound);

	//노래 사운드 그룹	
	_system->createSoundGroup("effectSound", &_effectSound);



	_musicGroup->addGroup(_mp3Group);

	_currentMusic = 0;


	_maxCount = 0;

	return S_OK;

}

void soundManager::release()
{
	if (*_channel != NULL || *_sound != NULL)
	{
		for (int i = 0; i < TOTALSOUNDBUFFER; ++i)
		{
			if (_channel != NULL)
			{
				if (_channel[i])_channel[i]->stop();
			}
			if (_sound != NULL)
			{
				if (_sound[i] != NULL) _sound[i]->release();
			}
		}
	}

	//메모리 지워준다
	//배열이므로
	SAFE_DELETE_ARRAY(_channel);
	SAFE_DELETE_ARRAY(_sound);

	//마지막으로 FMOD 사운드 시스템 닫아줌
	if (_system != NULL)
	{
		_system->release();
		_system->close();		//셧더 내립니다
	}
}

void soundManager::update()	
{
	_system->update();
}



//사운드 추가 함수
void soundManager::addSound(string keyName, string soundName, bool bgm, bool loop)
{
	if (loop)
	{
		if (bgm)
		{ 
			_system->createStream(soundName.c_str(), FMOD_LOOP_NORMAL, NULL, &_sound[_mTotalSounds.size()]);
		}
		else
		{
			_system->createSound(soundName.c_str(), FMOD_LOOP_NORMAL , NULL, &_sound[_mTotalSounds.size()]);
		}
		_maxCount++;
	}
	else
	{
		if (bgm)
		{
			_system->createStream(soundName.c_str(), FMOD_DEFAULT , NULL, &_sound[_mTotalSounds.size()]);
		}
		else
		{
			_system->createSound(soundName.c_str(), FMOD_DEFAULT, NULL, &_sound[_mTotalSounds.size()]);
		}
		_maxCount++;
	}

	_mTotalSounds.insert(make_pair(keyName, &_sound[_mTotalSounds.size()]));

}




//						키값,			볼륨			  BGM = ture,  Effect = false
void soundManager::play(string keyName, float volume, bool isMusic)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	//배열 의 몇번째인지 세알리기위한 카운트 변수
	int count = 0;
	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_system->playSound(*iter->second, 0, false, &_channel[count]);
			_channel[count]->setLoopPoints(0, FMOD_TIMEUNIT_MS, 0, FMOD_TIMEUNIT_MS);
			
			_channel[count]->setVolume(volume);

			if (isMusic)
			{
				_channel[count]->setChannelGroup(_musicGroup);
			}
			else if (!isMusic)
			{
				_channel[count]->setChannelGroup(_effectGroup);
			}

			break;
		}
	}
}

void soundManager::currentPlay()
{
	bool isPlay;
	for(int i=0;i<=_maxCount;i++)
	{

		_channel[i]->stop();
	}
	_system->playSound(_sound[_currentMusic-1], 0, false, &_channel[_currentMusic-1]);
	_channel[_currentMusic - 1]->setVolume(0.75);

	_channel[_currentMusic - 1]->setChannelGroup(_mp3Group);
}


void soundManager::stop(string keyName)				 
{
	arrSoundsIter iter = _mTotalSounds.begin();
	//배열 의 몇번째인지 세알리기위한 카운트 변수
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->stop();
			break;
		}
	}
}

void soundManager::pause(string keyName)			 
{
	arrSoundsIter iter = _mTotalSounds.begin();
	//배열 의 몇번째인지 세알리기위한 카운트 변수
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(true);
			break;
		}
	}
}

void soundManager::resume(string keyName)			 
{
	arrSoundsIter iter = _mTotalSounds.begin();
	//배열 의 몇번째인지 세알리기위한 카운트 변수
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPaused(false);
			break;
		}
	}
}


bool soundManager::isPlaySound(string keyName) 
{
	bool isPlay;

	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->isPlaying(&isPlay);
			break;
		}
	}

	return isPlay;
}

bool soundManager::isPauseSound(string keyName)
{
	bool isPause;

	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->getPaused(&isPause);
			break;
		}
	}

	return isPause;
}

//준우의 사운드매니저!!!!!!!!!!!!!!!!!!!!!!!!!!!!//준우의 사운드매니저!!!!!!!!!!!!!!!!!!!!!!!!!!!!




//마스터볼륨 -- 전체적 볼륨을 조절한다
//채널의 볼륨얻어오기
float soundManager::getVolume(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;
	float volume;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_channel[count]->getVolume(&volume);
	break;
		}
	}
	return volume;
}



//채널의 볼륨설정하기

//키값을 받아서 직접 볼륨을 설정
void soundManager::setVolume(string keyName, float volume)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
		_channel[count]->setVolume(volume);
	break;
		}
	}
}


//전체 볼륨을 얻어온다
float soundManager::getMasterVolume()
{
	float volume;
	_masterGroup->getVolume(&volume);
	return volume;
}

//전체 볼륨을 설정한다.
void soundManager::setMasterVolume(float volume)
{
	_masterGroup->setVolume(volume);
}

//BGM관련 음악을 설정한다.
float soundManager::getMusicVolume()
{
	float volume;
	_musicGroup->getVolume(&volume);
	return volume;
}
void soundManager::setMusicVolume(float volume)
{
	_musicGroup->setVolume(volume);
}


//이펙트 그룹 관련 볼륨을 설정한다.
float soundManager::getEffectVolume()
{
	float volume;
	_effectGroup->getVolume(&volume);
	return volume;
}
void soundManager::setEffectVolume(float volume)
{
	_effectGroup->setVolume(volume);
}


void soundManager::setMP3Volume(float volume)
{
	_mp3Group->setVolume(volume);
}


// 타이틀을 얻어서 string형태로 반환
string soundManager::getTagTitle(string keyName)
{
	const int fileName = 255;
	char tag[fileName] = { 0 };
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
		_sound[count]->getTag("TITLE", 0, &Ftag);
	break;
		}
	}
	return (char*)Ftag.data;
}

string soundManager::getTagTitle(bool isPlus)
{

	
	unsigned int tempLenght = 0;


		while (1)
		{
			_sound[_currentMusic]->getLength(&tempLenght, FMOD_TIMEUNIT_MS);

			if (tempLenght <= 50000)
			{
				if (_maxCount > _currentMusic)
					_currentMusic++;
				else if (_maxCount <= _currentMusic)
					_currentMusic = 0;
			}
			else
			{
				break;
			}
		}
		_sound[_currentMusic]->getTag("TITLE", 0, &Ftag);

		if (_maxCount > _currentMusic)
			_currentMusic++;
		else if (_maxCount < _currentMusic)
			_currentMusic = 0;
	
	


	return (char*)Ftag.data;
}

// 작곡가를 얻어서 string형태로 반환
string soundManager::getTagArtist(string keyName)
{
	const int fileName = 255;
	char tag[fileName] = { 0 };
	
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_sound[count]->getTag("ARTIST", 0, &Ftag);
	break;
		}
	}

	return (char*)Ftag.data;
}




///////////***************///////////////
///////////***************///////////////
///////////**** 팬설정 ****///////////////
///////////***************///////////////
//-1 ~ 0 ~ 1 로 왼쪽부터 오른쪽까지의 좌우음향설정
void soundManager::setPan(string keyName, float panValue)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setPan(panValue);
			break;
		}
	}
}




//현재 주파수를 얻어온후 주파수의 진동수를 speed의 배수로 곱한다.
//진동수가 빨라질수록 곡의 길이는 짧아지고 재생속도는 빨라진다.
void soundManager::multipleFrequency(string keyName, float speed)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_channel[count]->getFrequency(&_frequency);
	_frequency *= speed;
	_channel[count]->setFrequency(_frequency);

	break;
		}
	}
}
//반사음설정
void soundManager::setReverb()
{

	//모든 그룹에 반사음의 우선순위를 2로 넣어놓는다.
	_masterGroup->setReverbProperties(1, 0.5);
	//그 채널의 우선순위를 1로 넣는다.

	
}

//FMod를 사용하여 반사음의 효과를 넣을 수 있음
void soundManager::reverbOn()
{
	FMOD_REVERB_PROPERTIES propOn = FMOD_PRESET_CONCERTHALL;

	_system->setReverbProperties(0, &propOn);
}

void soundManager::reverbOff()
{
	FMOD_REVERB_PROPERTIES propOff = FMOD_PRESET_OFF;

	_system->setReverbProperties(0, &propOff);
}



// dsp장난치기