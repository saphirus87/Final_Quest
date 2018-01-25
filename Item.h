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

public:
	Item() {};
	~Item() {};

	//������ �ʱ�ȭ
	HRESULT init(void);		//�ʱ�ȭ �Լ�
	//������ ����
	void release(void);		//�޸� ���� ����
	//������ ã��(�̸�)
	tagItem findItem(string strKey);
	//������ ���� ����
	void addItem(string strKey);
	//������ ���� ����
	void delItem(string strKey);

	//�Һ��� ���
	vector<string>* iteminventory();
	string vitemstring(int num) { return _iteminventory[num]; }
	//����� ���
	vector<string>* equipinventory();
	string vequipstring(int num) { return _equipinventory[num]; }

	//������ ����Ʈ ȣ��
	mapItemList itemlist() { return _mItemList; }
};
