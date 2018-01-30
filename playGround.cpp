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

	_pm = new playerManager;
	_pm->init();

	_Item = new Item;
	_Item->init();

	IMAGEMANAGER->addImage("��ŸƮ���", ".\\SceneImage\\startBackground.bmp", 1024, 665, true, RGB(255, 0, 255));

	SCENEMANAGER->addScene("�����׾�", new gameOpenningScene);
	SCENEMANAGER->addScene("������", new gameEndingScene);
	SCENEMANAGER->addScene("��ŸƮ��", new gameStartScene);
	SCENEMANAGER->addScene("�޴���", new gameMenuScene);
	SCENEMANAGER->addScene("�����۸޴���", new itemMenu);
	SCENEMANAGER->addScene("���̺�ε�޴���", new saveLoadMenu);	
	SCENEMANAGER->addScene("���Ӽ��̺�ε�޴���", new gameSaveLoadScene);
	SCENEMANAGER->addScene("��ų�޴���", new abilitiesMenu);
	SCENEMANAGER->addScene("�ɼǾ�", new configMenu);
	SCENEMANAGER->addScene("���޴���", new equipMenu);
	SCENEMANAGER->addScene("�������ͽ��޴���", new statusMenu);
	SCENEMANAGER->addScene("fieldScene", new fieldScene);
	SCENEMANAGER->addScene("townScene", new townScene);
	SCENEMANAGER->addScene("battleScene", new battleScene);
	SCENEMANAGER->addScene("shopScene", new shopScene);
	
	((gameMenuScene*)SCENEMANAGER->findScene("�޴���"))->setPlayerManagerAddressLink(_pm);
	((gameMenuScene*)SCENEMANAGER->findScene("�޴���"))->setItemAddressLink(_Item);
	((itemMenu*)SCENEMANAGER->findScene("�����۸޴���"))->setItemAddressLink(_Item);
	((itemMenu*)SCENEMANAGER->findScene("�����۸޴���"))->setPlayerManagerAddressLink(_pm);
	((saveLoadMenu*)SCENEMANAGER->findScene("���̺�ε�޴���"))->setPlayerManagerAddressLink(_pm);
	((gameSaveLoadScene*)SCENEMANAGER->findScene("���Ӽ��̺�ε�޴���"))->setPlayerManagerAddressLink(_pm);
	((abilitiesMenu*)SCENEMANAGER->findScene("��ų�޴���"))->setPlayerManagerAddressLink(_pm);
	((equipMenu*)SCENEMANAGER->findScene("���޴���"))->setPlayerManagerAddressLink(_pm);
	((equipMenu*)SCENEMANAGER->findScene("���޴���"))->setItemAddressLink(_Item);
	((statusMenu*)SCENEMANAGER->findScene("�������ͽ��޴���"))->setPlayerManagerAddressLink(_pm);
	((fieldScene*)SCENEMANAGER->findScene("fieldScene"))->setPlayerManagerAddressLink(_pm);
	((battleScene*)SCENEMANAGER->findScene("battleScene"))->setPlayerManagerAddressLink(_pm);
	((battleScene*)SCENEMANAGER->findScene("battleScene"))->setItemAddressLink(_Item);
	((shopScene*)SCENEMANAGER->findScene("shopScene"))->setItemAddressLink(_Item);

	SCENEMANAGER->changeScene("�����׾�");

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

	if (KEYMANAGER->isOnceKeyDown(VK_F1)) _isDebug = !_isDebug;

	SCENEMANAGER->update();

	if (SCENEMANAGER->getnowScene() == SCENEMANAGER->findScene("fieldScene"))
	{
		((gameMenuScene*)SCENEMANAGER->findScene("�޴���"))->setisWhere("fieldScene");
	}
	else if (SCENEMANAGER->getnowScene() == SCENEMANAGER->findScene("townScene"))
	{
		((gameMenuScene*)SCENEMANAGER->findScene("�޴���"))->setisWhere("townScene");
	}
}

//�׸��°�.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//================== �� ���� �մ��� ���ÿ� =========================
	
	SCENEMANAGER->render();

	SetTextColor(getMemDC(), RGB(255, 0, 0));
	if (_isDebug) TIMEMANAGER->render(getMemDC());

	//================== �� �Ʒ��� �մ��� ���ÿ� ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc������ �׷��ش� 
}
