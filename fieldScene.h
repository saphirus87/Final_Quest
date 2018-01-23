#pragma once
#include "gameNode.h"

class fieldScene : public gameNode
{
private:

public:
	fieldScene();
	~fieldScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
};

