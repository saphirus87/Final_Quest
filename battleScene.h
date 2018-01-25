#pragma once
#include "gameNode.h"
#include <vector>

typedef void(*ACTION_FUNTION)(void*, void*);

class battleScene : public gameNode
{
private:
	vector<CALLBACK_FUNCTION> _vActionList;

public:
	battleScene();
	~battleScene();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);
	
	// 플레이어 행동 선택 함수
	void selectCommand(void);

	// 플레이어 & 적 행동 함수
	void attack(void);
	void useSkill(void);
	void useItem(void);
	void defense(void);
	void escape(void);
	// 행동 게이지 증가 함수
	void increasedActionGauge(void);
};

