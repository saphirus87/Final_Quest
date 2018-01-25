#pragma once
#include "singletonBase.h"
#include <map>

#include "inc/fmod.hpp"	//fmod.hpp���� ��Ŭ���
#pragma comment(lib, "lib/fmod64_vc.lib")	//���̺귯�� ���� ���

using namespace FMOD;

#define SOUNDBUFFER 10
#define EXTRACHANNELBUFFER 5

#define TOTALSOUNDBUFFER SOUNDBUFFER + EXTRACHANNELBUFFER

class soundManager : public singletonBase<soundManager>
{
private:
	typedef map<string, Sound**>				arrSounds;
	typedef map<string, Sound**>::iterator		arrSoundsIter;
	typedef map<string, Channel**>				arrChannels;
	typedef map<string, Channel**>::iterator	arrChannelsIter;

	FMOD_TAG Ftag;
	float _currentPitch, _currentPan;

private:
	System*			_system;
	
	Sound**			_sound;
	SoundGroup*		_masterSound;
	SoundGroup*		_musicSound;

	Channel**		_channel;
	ChannelGroup*	_musicGroup;  //�뷡 �׷�
	ChannelGroup*	_effectGroup; //����Ʈ �׷�������
	ChannelGroup*   _masterGroup; //��ü�� ����

	FMOD_RESULT     result;
	Geometry*		_geometry;
	DSP				*dspLowPass = 0;  //��������
	DSP				*dspHighPass = 0; //��������
	DSP		   	    *dspEcho = 0;     //�ݻ�����
	DSP			    *dspFlange = 0;   //�ֱ�𸣰ڴ� ���̸�
	DSP				*_dsp = 0;

	FMOD_VECTOR     _vector;//���ο� ���...
	int _polyIndex;

	int _maxCount;
	int ocil;
	float _frequency;
	float _bpm;
	arrSounds _mTotalSounds;

public:
	soundManager();
	~soundManager();

	HRESULT init();
	void release();
	void update();

	//���� �߰� �Լ�
	void addSound(string keyName, string soundName, bool bgm, bool loop);




	// 1.0 maximum 0.0 ~ 1.0 -> 0 ~ 255
	void play(string keyName, float volume = 1.0f, bool isMusic = false);

	void stop(string keyName);

	void pause(string keyName);
	void resume(string keyName);



	bool isPlaySound(string keyName);
	bool isPauseSound(string keyName);
	

	int getMaxCount() { return _maxCount; }


	//���� ��� �Ұ���
	void addMusicGroup(string keyName);
	void addEffectGroup(string keyName);

	//������� ���� 
	int getPosition(string keyName);
	void setPosition(string keyName,int position);
	int getLengh(string keyName);

	//�̸����
	string getTagTitle(string keyName);
	string getTagArtist(string keyName);

	//������ ����
	float getMasterVolume();
	void setMasterVolume(float volume);



//���� ��� �Ұ���***********
	//�����׷� ���� ����
	float getMusicVolume();
	void setMusicVolume(float volume);
	//����Ʈ �׷� ���� ����
	float getEffectVolume();
	void setEffectVolume(float volume);
//���� ��� �Ұ���***********


	//ä�ΰ��� ����
	float getVolume(string keyName);
	void  setVolume(string keyName, float volume);

	//������ //���̶� ����Ŀ �¿� ������ ġ��ħ �������
	void leftPan(string keyName); //�������� 0.5
	void rightPan(string keyName); //���������� 0.5
	void setPan(string keyName, float panValue);  // �ڽ��� ���� -1~1��������

	//�ݻ��� 
	void reverbOn(string keyName);
	void reverbOff(string keyName);

	//���ļ��뿪
	void downFrequency(string keyName);//���ļ� �ٿ�
	void upFrequency(string keyName);//���ļ� ��
	void multipleFrequency(string keyName, float multiple); // ���ļ� ����
													   //���� ����
	void picthUp(string keyName);
	void picthDown(string keyName);


	void ssss(string keyName);
};

