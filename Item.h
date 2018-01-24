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

private:
	mapItemList _mItemList;
	int _iteminventory;
	int _equipinventory;

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

	//�Һ��� ��ȣ �ʱ�ȭ
	void iteminventoryreset() { _iteminventory = -1; }
	//�Һ��� �̸� �ϳ� ���
	string iteminventory();
	//����� ��ȣ �ʱ�ȭ
	void equipinventoryreset() { _equipinventory = 0; }
	//����� �̸� �ϳ� ���
	string equipinventory();

	//������ ����Ʈ ȣ��
	mapItemList itemlist() { return _mItemList; }
};
