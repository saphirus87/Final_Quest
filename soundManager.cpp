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
	//FMOD ���忣�� ����Ϸ��� �ʱ�ȭ
	System_Create(&_system);

	_system->init(TOTALSOUNDBUFFER, FMOD_INIT_NORMAL, NULL);

	_sound = new Sound*[TOTALSOUNDBUFFER];
	_channel = new Channel*[TOTALSOUNDBUFFER];

	ZeroMemory(_sound, sizeof(_sound));
	ZeroMemory(_channel, sizeof(_channel));


	_maxCount = 0;
	_currentPitch = 1.0f;
	_currentPan = 0;


	//�ο��н� ����
	_system->createDSPByType(FMOD_DSP_TYPE_LOWPASS, &dspLowPass);
	//�����н�����
	_system->createDSPByType(FMOD_DSP_TYPE_HIGHPASS, &dspHighPass);
	// �÷��� ����
	_system->createDSPByType(FMOD_DSP_TYPE_FLANGE, &dspFlange);
	// ���� ����
	_system->createDSPByType(FMOD_DSP_TYPE_ECHO, &dspEcho);


	//������ �����Ѵ�.
	_system->createDSPByType(FMOD_DSP_TYPE_OSCILLATOR, &_dsp);


	//�����ͱ׷� �߰��� ��� ������ ��������
	_system->getMasterChannelGroup(&_masterGroup);

	//�����ͻ���׷� �߰�
	_system->getMasterSoundGroup(&_masterSound);

	//����Ʈ ���� �׷�
	_system->createChannelGroup("channelEffect", &_effectGroup);

	//BGM �뷡 �׷�
	_system->createChannelGroup("channelMusic", &_musicGroup);

	_masterGroup->addGroup(_effectGroup);
	_masterGroup->addGroup(_musicGroup);

	
	_system->createSoundGroup("soundMusic", &_musicSound);
	
	
	//���ļ�~~~
	_system->createGeometry(1, 3, &_geometry);



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

	//�޸� �����ش�
	//�迭�̹Ƿ�
	SAFE_DELETE(_channel);
	SAFE_DELETE(_sound);

	//���������� FMOD ���� �ý��� �ݾ���
	if (_system != NULL)
	{
		_system->release();
		_system->close();		//�˴� �����ϴ�
	}
}

void soundManager::update()	
{
	_system->update();
}



//���� �߰� �Լ�
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
			_system->createSound(soundName.c_str(), FMOD_DEFAULT , NULL, &_sound[_mTotalSounds.size()]);
		}
		_maxCount++;
	}

	_mTotalSounds.insert(make_pair(keyName, &_sound[_mTotalSounds.size()]));

}


// 1.0 maximum 0.0 ~ 1.0 -> 0 ~ 255
void soundManager::play(string keyName, float volume)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	//�迭 �� ���°���� ���˸������� ī��Ʈ ����
	int count = 0;
	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_system->playSound(_sound[count],0, false, &_channel[count]);
			_channel[count]->setLoopPoints(0, FMOD_TIMEUNIT_MS, 0, FMOD_TIMEUNIT_MS);

			_channel[count]->setVolume(volume);
			
			break;
		}
	}
}


void soundManager::stop(string keyName)				 
{
	arrSoundsIter iter = _mTotalSounds.begin();
	//�迭 �� ���°���� ���˸������� ī��Ʈ ����
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
	//�迭 �� ���°���� ���˸������� ī��Ʈ ����
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
	//�迭 �� ���°���� ���˸������� ī��Ʈ ����
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

//�ؿ��� ����Ŵ���!!!!!!!!!!!!!!!!!!!!!!!!!!!!//�ؿ��� ����Ŵ���!!!!!!!!!!!!!!!!!!!!!!!!!!!!


//ä�� �����׷쿡 �߰�
void soundManager::addMusicGroup(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			_channel[count]->setChannelGroup(_musicGroup);
			break;
		}
	}
}

//ä�� ����Ʈ�׷쿡 �߰�
void soundManager::addEffectGroup(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();

	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
		_channel[count]->setChannelGroup(_effectGroup);
		break;
		}
	}
}





//�����ͺ��� -- ��ü�� ������ �����Ѵ�
//ä���� ����������
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



//ä���� ���������ϱ�

//Ű���� �޾Ƽ� ���� ������ ����
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


//��ü ������ ���´�
float soundManager::getMasterVolume()
{
	float volume;
	_masterGroup->getVolume(&volume);
	return volume;
}

//��ü ������ �����Ѵ�.
void soundManager::setMasterVolume(float volume)
{
	_masterGroup->setVolume(volume);
}

//BGM���� ������ �����Ѵ�.
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


//����Ʈ �׷� ���� ������ �����Ѵ�.
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


// Ÿ��Ʋ�� �� string���·� ��ȯ
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

// �۰�� �� string���·� ��ȯ
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
///////////**** �Ҽ��� ****///////////////
///////////***************///////////////
//-1 ~ 0 ~ 1 �� ���ʺ��� �����ʱ����� �¿����⼳��
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

//���������� ��ĭ�� 
void soundManager::rightPan(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_currentPan += 0.05;
	_masterGroup->setPan(_currentPan);
	break;
		}
	}
}


//�������� ��ĭ�� �Ҽ���
void soundManager::leftPan(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
	_currentPan -= 0.05;
	_masterGroup->setPan(_currentPan);
	break;
		}
	}
}



//�ݻ�������
void soundManager::ssss(string keyName)
{
	arrSoundsIter iter = _mTotalSounds.begin();
	int count = 0;

	for (iter; iter != _mTotalSounds.end(); ++iter, count++)
	{
		if (keyName == iter->first)
		{
			//��� �׷쿡 �ݻ����� �켱������ 2�� �־���´�.
	_masterGroup->setReverbProperties(2, 0.5);
	//�� ä���� �켱������ 1�� �ִ´�.
	_channel[count]->setPriority(1);
	break;
		}
	}
}

//���� ���ļ��� ������ ���ļ��� �������� speed�� ����� ���Ѵ�.
//�������� ���������� ���� ���̴� ª������ ����ӵ��� ��������.
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


//FMod�� ����Ͽ� �ݻ����� ȿ���� ���� �� ����
void soundManager::reverbOn(string keyName)
{
	FMOD_REVERB_PROPERTIES propOn = FMOD_PRESET_CONCERTHALL;

	_system->setReverbProperties(0, &propOn);
}
void soundManager::reverbOff(string keyName)
{
	FMOD_REVERB_PROPERTIES propOff = FMOD_PRESET_OFF;

	_system->setReverbProperties(0, &propOff);
}

// dsp�峭ġ��