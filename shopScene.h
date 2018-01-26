#pragma once
#include "gameNode.h"

class shopScene
{
public:
	shopScene();
	~shopScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

