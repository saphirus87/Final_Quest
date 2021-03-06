#pragma once
#include "gameNode.h"
#include <map>
#include <vector>

enum Itemtype
{
	TYPE_USE,
	TYPE_RIGHT,
	TYPE_LEFT,
	TYPE_HEAD,
	TYPE_BODY,
	TYPE_ACCESSARY
};

struct tagItem
{
	int code;
	string name;
	Itemtype itemtype;
	int value;
	int price;
	int count;
};

class Item : public gameNode
{
private:
	typedef map<int, tagItem> mapItemList;
	typedef map<int, tagItem>::iterator mapItemIter;
	typedef vector<string> vItemList;

private:
	mapItemList _mItemList;

	vItemList _iteminventory;
	vItemList _equipinventory;

	int _money;

public:
	Item() {};
	~Item() {};

	//아이템 초기화
	HRESULT init(void);		//초기화 함수
	//아이템 삭제
	void release(void);		//메모리 관련 해제
	void update(void);

	//아이템 찾기(이름)
	tagItem findItem(string strKey);
	//아이템 갯수 증가
	void addItem(string strKey);
	//아이템 갯수 감소
	void delItem(string strKey);

	//소비템 목록
	vector<string> getiteminventory() { return _iteminventory; }
	//장비템 목록
	vector<string> getequipinventory() { return _equipinventory; }

	//아이템 리스트 호출
	mapItemList getitemlist() { return _mItemList; }

	void setMoney(int money) { _money = money; }
	int getMoney() { return _money; }
};
