#pragma once
#include "gameNode.h"
#include "battleScene.h"
#include "fieldScene.h"
#include "gameEndingScene.h"
#include "gameOpenningScene.h"
#include "gameStartScene.h"
#include "gameMenuScene.h"
#include "itemMenu.h"
#include "saveLoadMenu.h"
#include "abilitiesMenu.h"
#include "configMenu.h"

class playGround : public gameNode
{
private:
	gameNode* _start;				//스타트 씬

public:
	virtual HRESULT init(void);		//초기화 함수
	virtual void release(void);		//메모리 관련 해제
	virtual void update(void);		//업데이트(연산)
	virtual void render(void);		//그려주는 함수

	void soundInit();

	playGround();
	~playGround();
};

