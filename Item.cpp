#include "stdafx.h"
#include "Item.h"

HRESULT Item::init(void)
{
	_money = 0;

	tagItem potion;
	potion.code = 1;
	potion.itemtype = TYPE_USE;
	potion.name = "포션";
	potion.price = 5;
	potion.value = 10;
	potion.count = 0;
	_mItemList.insert(make_pair(potion.code, potion));
	tagItem highpotion;
	highpotion.code = 2;
	highpotion.itemtype = TYPE_USE;
	highpotion.name = "하이포션";
	highpotion.price = 10;
	highpotion.value = 30;
	highpotion.count = 0;
	_mItemList.insert(make_pair(highpotion.code, highpotion));
	tagItem megapotion;
	megapotion.code = 3;
	megapotion.itemtype = TYPE_USE;
	megapotion.name = "메가포션";
	megapotion.price = 15;
	megapotion.value = 50;
	megapotion.count = 0;
	_mItemList.insert(make_pair(megapotion.code, megapotion));
	tagItem ether;
	ether.code = 4;
	ether.itemtype = TYPE_USE;
	ether.name = "에테르";
	ether.price = 10;
	ether.value = 10;
	ether.count = 0;
	_mItemList.insert(make_pair(ether.code, ether));
	tagItem phoenix;
	phoenix.code = 5;
	phoenix.itemtype = TYPE_USE;
	phoenix.name = "피닉스의 깃털";
	phoenix.price = 50;
	phoenix.value = 9999;
	phoenix.count = 0;
	_mItemList.insert(make_pair(phoenix.code, phoenix));
	tagItem megaphoenix;
	megaphoenix.code = 6;
	megaphoenix.itemtype = TYPE_USE;
	megaphoenix.name = "메가 피닉스의 깃털";
	megaphoenix.price = 100;
	megaphoenix.value = 99999;
	megaphoenix.count = 0;
	_mItemList.insert(make_pair(megaphoenix.code, megaphoenix));
	tagItem smoke;
	smoke.code = 7;
	smoke.itemtype = TYPE_USE;
	smoke.name = "연막탄";
	smoke.price = 20;
	smoke.value = 0;
	smoke.count = 0;
	_mItemList.insert(make_pair(smoke.code, smoke));


	tagItem head1;
	head1.code = 101;
	head1.itemtype = TYPE_HEAD;
	head1.name = "밀집모자";
	head1.price = 10;
	head1.value = 5;
	head1.count = 0;
	_mItemList.insert(make_pair(head1.code, head1));
	tagItem head2;
	head2.code = 102;
	head2.itemtype = TYPE_HEAD;
	head2.name = "철투구";
	head2.price = 30;
	head2.value = 20;
	head2.count = 0;
	_mItemList.insert(make_pair(head2.code, head2));
	tagItem head3;
	head3.code = 103;
	head3.itemtype = TYPE_HEAD;
	head3.name = "후드";
	head3.price = 40;
	head3.value = 50;
	head3.count = 0;
	_mItemList.insert(make_pair(head3.code, head3));


	tagItem body1;
	body1.code = 201;
	body1.itemtype = TYPE_BODY;
	body1.name = "가죽갑옷";
	body1.price = 10;
	body1.value = 5;
	body1.count = 0;
	_mItemList.insert(make_pair(body1.code, body1));
	tagItem body2;
	body2.code = 202;
	body2.itemtype = TYPE_BODY;
	body2.name = "철갑옷";
	body2.price = 30;
	body2.value = 20;
	body2.count = 0;
	_mItemList.insert(make_pair(body2.code, body2));
	tagItem body3;
	body3.code = 203;
	body3.itemtype = TYPE_BODY;
	body3.name = "로브";
	body3.price = 40;
	body3.value = 50;
	body3.count = 0;
	_mItemList.insert(make_pair(body3.code, body3));


	tagItem right1;
	right1.code = 301;
	right1.itemtype = TYPE_RIGHT;
	right1.name = "단검(右)";
	right1.price = 10;
	right1.value = 5;
	right1.count = 0;
	_mItemList.insert(make_pair(right1.code, right1));
	tagItem right2;
	right2.code = 302;
	right2.itemtype = TYPE_RIGHT;
	right2.name = "지팡이";
	right2.price = 30;
	right2.value = 10;
	right2.count = 0;
	_mItemList.insert(make_pair(right2.code, right2));
	tagItem right3;
	right3.code = 303;
	right3.itemtype = TYPE_RIGHT;
	right3.name = "한손검";
	right3.price = 40;
	right3.value = 20;
	right3.count = 0;
	_mItemList.insert(make_pair(right3.code, right3));


	tagItem left1;
	left1.code = 401;
	left1.itemtype = TYPE_LEFT;
	left1.name = "단검(左)";
	left1.price = 10;
	left1.value = 5;
	left1.count = 0;
	_mItemList.insert(make_pair(left1.code, left1));
	tagItem left2;
	left2.code = 402;
	left2.itemtype = TYPE_LEFT;
	left2.name = "방패";
	left2.price = 20;
	left2.value = 20;
	left2.count = 0;
	_mItemList.insert(make_pair(left2.code, left2));
	tagItem left3;
	left3.code = 403;
	left3.itemtype = TYPE_LEFT;
	left3.name = "수정구";
	left3.price = 40;
	left3.value = 20;
	left3.count = 0;
	_mItemList.insert(make_pair(left3.code, left3));


	tagItem accessary1;
	accessary1.code = 501;
	accessary1.itemtype = TYPE_ACCESSARY;
	accessary1.name = "힘의 목걸이";
	accessary1.price = 20;
	accessary1.value = 10;
	accessary1.count = 0;
	_mItemList.insert(make_pair(accessary1.code, accessary1));
	tagItem accessary2;
	accessary2.code = 502;
	accessary2.itemtype = TYPE_ACCESSARY;
	accessary2.name = "체력의 목걸이";
	accessary2.price = 20;
	accessary2.value = 10;
	accessary2.count = 0;
	_mItemList.insert(make_pair(accessary2.code, accessary2));
	tagItem accessary3;
	accessary3.code = 503;
	accessary3.itemtype = TYPE_ACCESSARY;
	accessary3.name = "마력의 목걸이";
	accessary3.price = 20;
	accessary3.value = 10;
	accessary3.count = 0;
	_mItemList.insert(make_pair(accessary3.code, accessary3));

	_iteminventory.clear();
	_equipinventory.clear();

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

void Item::update(void)
{
	_iteminventory.clear();
	for (int i = 0; i < _mItemList.size(); ++i)
	{
		if (_mItemList[i].itemtype != TYPE_USE)continue;
		if (_mItemList[i].count == 0)continue;
		_iteminventory.push_back(_mItemList[i].name);
	}
	_equipinventory.clear();
	for (int i = 0; i < _mItemList.size(); ++i)
	{
		if (_mItemList[i].itemtype == TYPE_USE)continue;
		if (_mItemList[i].count == 0)continue;
		_equipinventory.push_back(_mItemList[i].name);
	}
}

tagItem Item::findItem(string strKey)
{
	for (int i = 0; i <_mItemList.size(); ++i)
	{
		if (_mItemList[i].name == strKey)return _mItemList[i];
	}
	tagItem temp;
	temp.name = "없음";
	return temp;
}

void Item::addItem(string strKey)
{
	for (int i = 0; i <_mItemList.size();++i)
	{
		if (_mItemList[i].name == strKey)++_mItemList[i].count;
	}
	update();
}

void Item::delItem(string strKey)
{
	for (int i = 0; i <_mItemList.size(); ++i)
	{
		if (_mItemList[i].name == strKey)--_mItemList[i].count;
		if (_mItemList[i].count < 0)_mItemList[i].count = 0;
	}
	update();
}

