#include "stdafx.h"
#include "DLCManager.h"

HRESULT DLCManager::init(void)
{
	return S_OK;
}

void DLCManager::release(void)
{

}

bool DLCManager::addDLC(string strKey, bool istrue)
{
	bool isTrue = findDLC(strKey);

	//이미지가 이미 있다면 그 이미지를 반환
	if (isTrue) return isTrue;

	_mDLCList.insert(make_pair(strKey, istrue));
	
	return istrue;
}

bool DLCManager::findDLC(string strKey)
{
	mapDLCIter key = _mDLCList.find(strKey);

	if (key != _mDLCList.end())
	{
		return key->second;
	}
	return NULL;
}

void DLCManager::setTrue(string strKey, bool istrue)
{
	mapDLCIter key = _mDLCList.find(strKey);

	if (key != _mDLCList.end())
	{
		key->second = istrue;
	}
}