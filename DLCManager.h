#pragma once
#include "singletonBase.h"
#include <map>

class DLCManager : public singletonBase<DLCManager>
{
private:
	//typedef map<string, image*> �̰��� mapImageList�� Ī�Ѵ�
	typedef map<string, bool>				mapDLCList;
	typedef map<string, bool>::iterator		mapDLCIter;
	
private:
	mapDLCList _mDLCList;

public:
	DLCManager() {};
	~DLCManager() {};

	HRESULT init(void);
	void release(void);

	bool addDLC(string strKey, bool istrue);

	bool findDLC(string strKey);

	void setTrue(string strKey, bool istrue);
};

