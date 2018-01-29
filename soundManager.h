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


private:
	FMOD_RESULT     result;

	System*			_system;
	
	Sound**			_sound;
	SoundGroup*		_masterSound; //������ ����׷�
	SoundGroup*		_musicSound; //�뷡 ����׷�
	SoundGroup*		_effectSound; //����Ʈ ����׷�

	Channel**		_channel;
	ChannelGroup*   _masterGroup; //������ ä�α׷�
	ChannelGroup*	_musicGroup;  //�뷡 ä�α׷�
	ChannelGroup*	_effectGroup; //����Ʈ ä�α׷�

	arrSounds _mTotalSounds;

	FMOD_TAG Ftag; //�±׸� �޾ƿ��� ���� Ftag

	int _currentMusic;

	int _maxCount;


	float _frequency;//���ļ� ������ ���� ����

public:
	soundManager();
	~soundManager();

	HRESULT init();
	void release();
	void update();

	// ���� �߰� �Լ�(string Ű��, string ��ι����ϸ�, bgm�ΰ�?, �ݺ�����Ұ��ΰ�?)
	void addSound(string keyName, string soundName, bool bgm, bool loop);

	//�������(Ű��, ����,bgm=true, effect=false) ������ 0~1.0����
	void play(string keyName, float volume = 1.0f, bool isMusic = false);
	void currentPlay();

	//��� �ߴ�(Ű��);
	void stop(string keyName);


	//�Ͻ�����(Ű��);
	void pause(string keyName);
	//�Ͻ���������(Ű��)
	void resume(string keyName);


	//������ΰ�?(Ű��)
	bool isPlaySound(string keyName);
	//�Ͻ������ΰ�?(Ű��)
	bool isPauseSound(string keyName);
	

	//�����̸����(Ű��),������ string;
	string getTagTitle(string keyName);
	string getTagTitle(bool isPlus);

	//�۰����(Ű��), ������ string;
	string getTagArtist(string keyName);

	//������ ���� ��� ������ ����Ƽ� �����Ѵ�.
	float getMasterVolume();
	void setMasterVolume(float volume);

	//��� �ر��̴�!!
	//��� ���� ���� ������� ��ϵ� �뷡�� ������ �����Ѵ�.
	float getMusicVolume();
	void setMusicVolume(float volume);


	//ȿ���� �׷� ���� ���� ȿ�������� ��ϵ� �뷡�� ������ �����Ѵ�.
	float getEffectVolume();
	void setEffectVolume(float volume);


	//ä�ΰ��� ���� ���������� �� ������ ���õ� ������ �����Ѵ�.
	float getVolume(string keyName);
	void  setVolume(string keyName, float volume);

	//������ //���̶� ����Ŀ �¿� ������ ġ��ħ �������
	void setPan(string keyName, float panValue);  // -1�� �������� �������� 1�� ����� ���� ����������

	//�ݻ��� �⺻����
	void setReverb(string keyName);


	//�ݻ��� �� ����
	void reverbOn(string keyName);
	void reverbOff(string keyName);

	//���ļ� ��������
	void multipleFrequency(string keyName, float multiple); 
};