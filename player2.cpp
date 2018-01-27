#include "stdafx.h"
#include "player2.h"


player2::player2()
{
}


player2::~player2()
{

}

HRESULT player2::init()
{

	player::init();

	_name = "Moogle";
	_partyPos = 2;

	return S_OK;
}
void player2::release()
{

}
void player2::update() 
{
	player::update();
}
void player2::render()
{
	player::render();
}
