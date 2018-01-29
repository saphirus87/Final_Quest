#pragma once
#include "singletonBase.h"
#include <map>
#include <vector>

class DLCManager : public singletonBase<DLCManager>
{
private:
	//typedef map<string, image*> 이것을 mapImageList라 칭한다
	typedef map<string, bool>				mapDLCList;
	typedef map<string, bool>::iterator		mapDLCIter;
	
private:
	mapDLCList _mDLCList;
	mapDLCIter _mDLCIter;
	vector<string> _vDLCinvenlist;
	vector<string> _vDLCshoplist;

public:
	DLCManager() {};
	~DLCManager() {};

	HRESULT init(void);
	void release(void);
	void update(void);

	bool addDLC(string strKey, bool istrue);

	bool findDLC(string strKey);

	void setTrue(string strKey, bool istrue);

	mapDLCList getmdlclist() { return _mDLCList; }
	vector<string> getDLCinven() { return _vDLCinvenlist; }
	vector<string> getDLCshop() { return _vDLCshoplist; }
};

