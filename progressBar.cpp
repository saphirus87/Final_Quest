#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{

}

HRESULT progressBar::init(int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage("frontBar", "hpBarTop.bmp", x, y, width, height, true, RGB(255, 0, 255));

	_progressBarBottom = IMAGEMANAGER->addImage("backBar",
		"hpBarBottom.bmp", x, y, width, height, true, RGB(255, 0, 255));

	//������ ����ũ���!
	_maxWidth = _width = _progressBarTop->getWidth();

	return S_OK;
}

// ���α׷��� �� ���ϴ� �̹��� �Ű������� �޾Ƽ�
HRESULT progressBar::frontBarInit(string frontBarKey, const char* frontBarImageName, int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage(frontBarKey, frontBarImageName, x, y, width, height, true, RGB(255, 0, 255));
	_progressBarBottom = NULL;

	//������ ����ũ���!
	_maxWidth = _width = _progressBarTop->getWidth();

	return S_OK;
}

// ���α׷��� �� ���ϴ� �̹��� �Ű������� �޾Ƽ�
HRESULT progressBar::backBarInit(string backBarKey, const char * backBarImageName, int x, int y, int width, int height)
{
	_x = x;
	_y = y;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarBottom = IMAGEMANAGER->addImage(backBarKey, backBarImageName, x, y, width, height, true, RGB(255, 0, 255));
	_progressBarTop = NULL;

	//������ ����ũ���!
	_maxWidth = _width = _progressBarBottom->getWidth();

	return S_OK;
}

void progressBar::release()									  
{

}

void progressBar::update()									  
{
	_rcProgress = RectMakeCenter(_x, _y, _progressBarTop->getWidth(), _progressBarTop->getHeight());
}

void progressBar::render()									  
{
	if (_progressBarBottom != NULL)
		_progressBarBottom->render( getMemDC(),
			_rcProgress.left + _maxWidth / 2,
			_y + _progressBarBottom->getHeight() / 2, 0, 0,
			_maxWidth, _progressBarBottom->getHeight());

	if (_progressBarTop != NULL)
		_progressBarTop->render(getMemDC(),
			_rcProgress.left + _maxWidth / 2,
			_y + _progressBarTop->getHeight() / 2, 0, 0,
			_width, _progressBarTop->getHeight());

}

void progressBar::frontBarRender(void)
{
}

void progressBar::backBarRender(void)
{
}

void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_width = (currentGauge / maxGauge) * _maxWidth;
}
