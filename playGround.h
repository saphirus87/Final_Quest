#pragma once
#include "gameNode.h"
#include "battleScene.h"
#include "fieldScene.h"
#include "townScene.h"
#include "gameEndingScene.h"
#include "gameOpenningScene.h"
#include "gameStartScene.h"
#include "gameMenuScene.h"
#include "gameSaveLoadScene.h"
#include "itemMenu.h"
#include "saveLoadMenu.h"
#include "abilitiesMenu.h"
#include "configMenu.h"
#include "equipMenu.h"
#include "statusMenu.h"
#include "playerManager.h"
#include "shopScene.h"
#include "Item.h"
#include "gameBattleLodingScene.h"

class playGround : public gameNode
{
private:
	gameNode* _start;				//��ŸƮ ��
	playerManager* _pm;
	Item* _Item;

public:
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�

	void soundInit();

	playGround();
	~playGround();
};

