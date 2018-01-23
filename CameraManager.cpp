#include "stdafx.h"
#include "CameraManager.h"

//�����Ϸ� ���ñ� ���� �����̹���(32��Ʈ) ���̺귯���� ����ϰڴ�
#pragma comment(lib, "msimg32.lib")


CameraManager::CameraManager()
{
}


CameraManager::~CameraManager()
{
}

HRESULT CameraManager::init()
{

	return S_OK;
}


//�̹��� ������
void CameraManager::release(void)
{
	deleteAll();
}

BOOL CameraManager::deleteAll(void)
{
	mapImageIter iter = _mImageList.begin();

	for (; iter != _mImageList.end();)
	{
		//�̹��� ������ �ִ�!
		if (iter->second != NULL)
		{
			SAFE_DELETE(iter->second);
			iter = _mImageList.erase(iter);
		}
		else ++iter;
	}

	_mImageList.clear();

	return TRUE;
}

image* CameraManager::addImage(string strKey, int width, int height)
{
	image* img = findImage(strKey);

	//�̹����� �̹� �ִٸ� �� �̹����� ��ȯ
	if (img) return img;
	//�װ� �ƴ϶�� ���μ����� ������� �������� ��.!
	img = new image;

	if (FAILED(img->init(width, height, true, RGB(255, 0, 255))))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* CameraManager::addImage(string strKey, const char* fileName, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//�̹����� �̹� �ִٸ� �� �̹����� ��ȯ
	if (img) return img;
	//�װ� �ƴ϶�� ���μ����� ������� �������� ��.!
	img = new image;

	if (FAILED(img->init(fileName, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}

image* CameraManager::addImage(string strKey, const char* fileName, float x, float y, int width, int height, bool trans, COLORREF transColor)
{
	image* img = findImage(strKey);

	//�̹����� �̹� �ִٸ� �� �̹����� ��ȯ
	if (img) return img;
	//�װ� �ƴ϶�� ���μ����� ������� �������� ��.!
	img = new image;

	if (FAILED(img->init(fileName, x, y, width, height, trans, transColor)))
	{
		SAFE_DELETE(img);

		return NULL;
	}

	_mImageList.insert(make_pair(strKey, img));

	return img;
}


image* CameraManager::findImage(string strKey)
{
	mapImageIter key = _mImageList.find(strKey);

	//ã�Ҵ�
	if (key != _mImageList.end())
	{
		return key->second;
	}

	return NULL;
}


BOOL CameraManager::deleteImage(string strKey)
{
	mapImageIter key = _mImageList.find(strKey);

	//���� �̹����� �߰�
	if (key != _mImageList.end())
	{
		key->second->release();
		SAFE_DELETE(key->second);
		_mImageList.erase(key);

		return true;
	}

	return false;
}
