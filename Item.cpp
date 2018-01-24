#include "stdafx.h"
#include "Item.h"

HRESULT Item::init(void)
{
	tagItem potion;
	potion.code = 1;
	potion.itemtype = TYPE_USE;
	potion.name = "����";
	potion.price = 5;
	potion.value = 10;
	potion.count = 0;
	_mItemList.insert(make_pair(potion.code, potion));
	tagItem highpotion;
	highpotion.code = 2;
	highpotion.itemtype = TYPE_USE;
	highpotion.name = "��������";
	highpotion.price = 10;
	highpotion.value = 30;
	highpotion.count = 0;
	_mItemList.insert(make_pair(highpotion.code, highpotion));
	tagItem megapotion;
	megapotion.code = 3;
	megapotion.itemtype = TYPE_USE;
	megapotion.name = "�ް�����";
	megapotion.price = 15;
	megapotion.value = 50;
	megapotion.count = 0;
	_mItemList.insert(make_pair(megapotion.code, megapotion));
	tagItem ether;
	ether.code = 4;
	ether.itemtype = TYPE_USE;
	ether.name = "���׸�";
	ether.price = 10;
	ether.value = 10;
	ether.count = 0;
	_mItemList.insert(make_pair(ether.code, ether));
	tagItem phoenix;
	phoenix.code = 5;
	phoenix.itemtype = TYPE_USE;
	phoenix.name = "�Ǵн��� ����";
	phoenix.price = 50;
	phoenix.value = 9999;
	phoenix.count = 0;
	_mItemList.insert(make_pair(phoenix.code, phoenix));
	tagItem megaphoenix;
	megaphoenix.code = 6;
	megaphoenix.itemtype = TYPE_USE;
	megaphoenix.name = "�ް� �Ǵн��� ����";
	megaphoenix.price = 100;
	megaphoenix.value = 99999;
	megaphoenix.count = 0;
	_mItemList.insert(make_pair(megaphoenix.code, megaphoenix));
	tagItem smoke;
	smoke.code = 7;
	smoke.itemtype = TYPE_USE;
	smoke.name = "����ź";
	smoke.price = 20;
	smoke.value = 0;
	smoke.count = 0;
	_mItemList.insert(make_pair(smoke.code, smoke));


	tagItem head1;
	head1.code = 101;
	head1.itemtype = TYPE_HEAD;
	head1.name = "��������";
	head1.price = 10;
	head1.value = 5;
	head1.count = 0;
	_mItemList.insert(make_pair(head1.code, head1));
	tagItem head2;
	head2.code = 102;
	head2.itemtype = TYPE_HEAD;
	head2.name = "ö����";
	head2.price = 30;
	head2.value = 20;
	head2.count = 0;
	_mItemList.insert(make_pair(head2.code, head2));
	tagItem head3;
	head3.code = 103;
	head3.itemtype = TYPE_HEAD;
	head3.name = "�ĵ�";
	head3.price = 40;
	head3.value = 50;
	head3.count = 0;
	_mItemList.insert(make_pair(head3.code, head3));


	tagItem body1;
	body1.code = 201;
	body1.itemtype = TYPE_BODY;
	body1.name = "���װ���";
	body1.price = 10;
	body1.value = 5;
	body1.count = 0;
	_mItemList.insert(make_pair(body1.code, body1));
	tagItem body2;
	body2.code = 202;
	body2.itemtype = TYPE_BODY;
	body2.name = "ö����";
	body2.price = 30;
	body2.value = 20;
	body2.count = 0;
	_mItemList.insert(make_pair(body2.code, body2));
	tagItem body3;
	body3.code = 203;
	body3.itemtype = TYPE_BODY;
	body3.name = "�κ�";
	body3.price = 40;
	body3.value = 50;
	body3.count = 0;
	_mItemList.insert(make_pair(body3.code, body3));


	tagItem right1;
	right1.code = 301;
	right1.itemtype = TYPE_RIGHT;
	right1.name = "�ܰ�(��)";
	right1.price = 10;
	right1.value = 5;
	right1.count = 0;
	_mItemList.insert(make_pair(right1.code, right1));
	tagItem right2;
	right2.code = 302;
	right2.itemtype = TYPE_RIGHT;
	right2.name = "������";
	right2.price = 30;
	right2.value = 10;
	right2.count = 0;
	_mItemList.insert(make_pair(right2.code, right2));
	tagItem right3;
	right3.code = 303;
	right3.itemtype = TYPE_RIGHT;
	right3.name = "��հ�";
	right3.price = 40;
	right3.value = 20;
	right3.count = 0;
	_mItemList.insert(make_pair(right3.code, right3));


	tagItem left1;
	left1.code = 401;
	left1.itemtype = TYPE_LEFT;
	left1.name = "�ܰ�(�)";
	left1.price = 10;
	left1.value = 5;
	left1.count = 0;
	_mItemList.insert(make_pair(left1.code, left1));
	tagItem left2;
	left2.code = 402;
	left2.itemtype = TYPE_LEFT;
	left2.name = "����";
	left2.price = 20;
	left2.value = 20;
	left2.count = 0;
	_mItemList.insert(make_pair(left2.code, left2));
	tagItem left3;
	left3.code = 403;
	left3.itemtype = TYPE_LEFT;
	left3.name = "��հ�1";
	left3.price = 40;
	left3.value = 20;
	left3.count = 0;
	_mItemList.insert(make_pair(left3.code, left3));


	tagItem accessary1;
	accessary1.code = 501;
	accessary1.itemtype = TYPE_ACCESSARY;
	accessary1.name = "���� �����";
	accessary1.price = 20;
	accessary1.value = 10;
	accessary1.count = 0;
	_mItemList.insert(make_pair(accessary1.code, accessary1));
	tagItem accessary2;
	accessary2.code = 502;
	accessary2.itemtype = TYPE_ACCESSARY;
	accessary2.name = "ü���� �����";
	accessary1.price = 20;
	accessary1.value = 10;
	accessary2.count = 0;
	_mItemList.insert(make_pair(accessary2.code, accessary2));
	tagItem accessary3;
	accessary3.code = 503;
	accessary3.itemtype = TYPE_ACCESSARY;
	accessary3.name = "������ �����";
	accessary1.price = 20;
	accessary1.value = 10;
	accessary3.count = 0;
	_mItemList.insert(make_pair(accessary3.code, accessary3));


	_iteminventory = -1;
	_equipinventory = 0;
	
	return S_OK;
}

void Item::release(void)
{
	mapItemIter iter = _mItemList.begin();

	for (; iter != _mItemList.end();)
	{
		iter = _mItemList.erase(iter);
	}

	_mItemList.clear();
}

tagItem Item::findItem(string strKey)
{
	mapItemIter iter = _mItemList.begin();

	for (; iter != _mItemList.end();)
	{
		if (iter->second.name == strKey)return iter->second;
	}
	tagItem temp;
	temp.name = "����";
	return temp;
}

void Item::addItem(string strKey)
{
	mapItemIter iter = _mItemList.begin();

	for (; iter != _mItemList.end();)
	{
		if (iter->second.name == strKey)++iter->second.count;
	}
}

void Item::delItem(string strKey)
{
	mapItemIter iter = _mItemList.begin();

	for (; iter != _mItemList.end();)
	{
		if (iter->second.name == strKey)--iter->second.count;
		if (iter->second.count < 0)iter->second.count = 0;
	}
}

string Item::iteminventory()
{
	++_iteminventory;
	if (_mItemList[_iteminventory].count != 0 && _mItemList[_equipinventory].itemtype == TYPE_USE)
	{
		return _mItemList[_iteminventory].name;
	}
	return NULL;
}

string Item::equipinventory()
{
	for (; _mItemList[_equipinventory].itemtype == TYPE_USE;)++_equipinventory;
	if (_mItemList[_equipinventory].count != 0)
	{
		return _mItemList[_equipinventory].name;
	}
	return NULL;
}