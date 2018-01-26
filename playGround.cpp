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

	IMAGEMANAGER->addImage("스타트배경", ".\\SceneImage\\startBackground.bmp", 1024, 665, true, RGB(255, 0, 255));

	SCENEMANAGER->addScene("오프닝씬", new gameOpenningScene);
	SCENEMANAGER->addScene("엔딩씬", new gameEndingScene);
	SCENEMANAGER->addScene("스타트씬", new gameStartScene);
	SCENEMANAGER->addScene("메뉴씬", new gameMenuScene);
	SCENEMANAGER->addScene("아이템메뉴씬", new itemMenu);
	SCENEMANAGER->addScene("세이브로드메뉴씬", new saveLoadMenu);
	SCENEMANAGER->addScene("게임세이브로드메뉴씬", new gameSaveLoadScene);
	SCENEMANAGER->addScene("스킬메뉴씬", new abilitiesMenu);
	SCENEMANAGER->addScene("옵션씬", new configMenu);
	SCENEMANAGER->addScene("장비메뉴씬", new equipMenu);
	SCENEMANAGER->addScene("스테이터스메뉴씬", new statusMenu);
	SCENEMANAGER->addScene("fieldScene", new fieldScene);
	SCENEMANAGER->addScene("townScene", new townScene);
	SCENEMANAGER->addScene("battleScene", new battleScene);
	SCENEMANAGER->addScene("shopScene", new shopScene);
	
	SCENEMANAGER->changeScene("스타트씬");

	_pm = new playerManager;
	_pm->init();

	((fieldScene*)SCENEMANAGER->findScene("fieldScene"))->setPlayerManagerAddressLink(_pm);

	_Item = new Item;
	_Item->init();

	((itemMenu*)SCENEMANAGER->findScene("아이템메뉴씬"))->setItemAddressLink(_Item);
	((shopScene*)SCENEMANAGER->findScene("shopScene"))->setItemAddressLink(_Item);

	return S_OK;
}

//메모리 관련 삭제
void playGround::release(void)
{
	gameNode::release();

}

//연산
void playGround::update(void)
{
	gameNode::update();

	if (KEYMANAGER->isOnceKeyDown(VK_F1)) _isDebug = !_isDebug;

	SCENEMANAGER->update();

}

//그리는거.......
void playGround::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//================== 이 위는 손대지 마시오 =========================
	
	SCENEMANAGER->render();

	SetTextColor(getMemDC(), RGB(255, 0, 0));
	if (_isDebug) TIMEMANAGER->render(getMemDC());

	//================== 이 아래는 손대지 마시오 ========================
	this->getBackBuffer()->render(getHDC(), 0, 0);//hdc영역에 그려준다 
}
