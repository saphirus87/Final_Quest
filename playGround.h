#pragma once
#include "gameNode.h"
#include "battleScene.h"
#include "fieldScene.h"
#include "gameEndingScene.h"
#include "gameOpenningScene.h"
#include "gameStartScene.h"

class playGround : public gameNode
{
private:


public:
	virtual HRESULT init(void);		//�ʱ�ȭ �Լ�
	virtual void release(void);		//�޸� ���� ����
	virtual void update(void);		//������Ʈ(����)
	virtual void render(void);		//�׷��ִ� �Լ�

	playGround();
	~playGround();
};

