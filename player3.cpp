#include "stdafx.h"
#include "player3.h"


player3::player3()
{
}


player3::~player3()
{

}


HRESULT player3::init()
{
	player::init();

	_name = "trance";
	_partyPos = 3;

	return S_OK;
}
void player3::release()
{

}
void player3::update() 
{
	player::update();
}
void player3::render()
{
	player::render();
}