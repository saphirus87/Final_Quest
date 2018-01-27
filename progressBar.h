#pragma once
#include "gameNode.h"

//12.12�� ����� �ʰ�
//** ##const ����## **, ����, ȣ��, �缱, ����, ����, �������� ���� ���ٲ�
//����� �ʰ� 12.14�� �����ӟp ������ ���� ��.
//���� ȣ��� ������� ���� �ڱ��� ��Ĵ�� �ڵ��� �ؼ�
//���������� �ø����� �� ģ���鿡�� �������� ^^*�� �մϴ�
//�޾ƺ� �� ģ������ �������� ���ٸ� ������ �޾��ֱ� �ٶ��ϴ�

//�ϴ� ���� -> 
//������ 18������ 3��Ʈ�� �� �����ϴµ�
//1��Ʈ�� �¿�� �����δ�
//2��Ʈ�� ���Ʒ��� �����δ�
//3��Ʈ�� (������ �����ְ�������) �����δ�

//��� �̴Ͼ���� ü�¹ٰ� �޷��ִ�
//��� �̴Ͼ���� �� ������ ȭ�� ������ �Ŵ��� ������ �����´�

//���� ���� �������·δ� ü�¹ٰ� �� ó�� ������ ��ġ�� ũ�Ⱑ ������ �ȴ�
//��Ÿ���� �ϵ�ĥ������ ���� ���α׷����� Ŭ������ �����Ͽ�
//ũ�� ������ ��������� �ǰԲ� �Ѵ�

//����� ���ϵ� �ϵ�ĥ���鸸�� ������ �ִ� *^^* �����ϰ� �� ��.
class progressBar : public gameNode
{
private:
	RECT _rcProgress;
	int _x, _y;
	float _width;
	float _maxWidth;

	image* _progressBarTop;
	image* _progressBarBottom;

public:
	progressBar();
	~progressBar();

	HRESULT init(int x, int y, int width, int height);
	HRESULT frontBarInit(string frontBarKey, const char* frontBarImageName, int x, int y, int width, int height);
	HRESULT backBarInit(string backBarKey, const char* backBarImageName, int x, int y, int width, int height);
	void release();
	void update();
	void render();

	void frontBarRender(void);
	void backBarRender(void);
	void setGauge(float currentGauge, float maxGauge);

	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
};

