#pragma once
#include "gameNode.h"

class gameOpenningScene : public gameNode
{
public:
	HRESULT init();
	void release();
	void update();
	void render();

	float OpeningCameraY;

	int _alpha;
	int knihgtAlpha;

	gameOpenningScene();
	~gameOpenningScene();
};