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
	gameNode* _start;				//��ŸƮ ��

public:
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�

	void soundInit();

	playGround();
	~playGround();
};

