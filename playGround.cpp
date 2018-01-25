#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{

}

HRESULT playGround::init()
{
	gameNode::init(true);
	soundInit();

	IMAGEMANAGER->addImage("��ŸƮ���", ".\\SceneImage\\startBackground.bmp", 1024, 665, true, RGB(255, 0, 255));

	SCENEMANAGER->addScene("�����׾�", new gameOpenningScene);
	SCENEMANAGER->addScene("������", new gameEndingScene);
	SCENEMANAGER->addScene("��ŸƮ��", new gameStartScene);
	SCENEMANAGER->addScene("�޴���", new gameMenuScene);
	SCENEMANAGER->addScene("�����۸޴���", new itemMenu);
	SCENEMANAGER->addScene("���̺�ε�޴���", new saveLoadMenu);
	SCENEMANAGER->addScene("��ų�޴���", new abilitiesMenu);
	SCENEMANAGER->addScene("�ɼǾ�", new configMenu);
	SCENEMANAGER->addScene("fieldScene", new fieldScene);
	SCENEMANAGER->addScene("battleScene", new battleScene);
	
	SCENEMANAGER->changeScene("��ŸƮ��");

	return S_OK;
}

//�޸� ���� ����
void playGround::release(void)
{
	gameNode::release();

}

//����
void playGround::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();

}

//�׸��°�.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//================== �� ���� �մ��� ���ÿ� =========================
	
	SCENEMANAGER->render();

	//SetTextColor(getMemDC(), RGB(255, 255, 255));
	TIMEMANAGER->render(getMemDC());

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc������ �׷��ش� 
}
