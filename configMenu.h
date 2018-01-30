#pragma once
#include "gameNode.h"

class configMenu : public gameNode
{
private:
	int _cursorMenuNum;
	int _musicVolume;
	int _effectVolume;


	float _musicSpeed;
	string _musicTitle;

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void keyControl();
	//POINT cursorReset(POINT x, POINT y);

	configMenu();
	~configMenu();
};

