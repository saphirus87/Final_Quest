#pragma once
#include "gameNode.h"
#include <map>
#include <vector>

enum Itemtype
{
	TYPE_USE,
	TYPE_HEAD,
	TYPE_BODY,
	TYPE_RIGHT,
	TYPE_LEFT,
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

	//������ �ʱ�ȭ
	HRESULT init(void);		//�ʱ�ȭ �Լ�
	//������ ����
	void release(void);		//�޸� ���� ����
	void update(void);

	//������ ã��(�̸�)
	tagItem findItem(string strKey);
	//������ ���� ����
	void addItem(string strKey);
	//������ ���� ����
	void delItem(string strKey);

	//�Һ��� ���
	vector<string> getiteminventory() { return _iteminventory; }
	//����� ���
	vector<string> getequipinventory() { return _equipinventory; }

	//������ ����Ʈ ȣ��
	mapItemList getitemlist() { return _mItemList; }

	void setMoney(int money) { _money = money; }
	int getMoney() { return _money; }
};
