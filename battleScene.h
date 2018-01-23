#pragma once
#include "gameNode.h"

class battleScene : public gameNode
{
private:

public:
	battleScene();
	~battleScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

