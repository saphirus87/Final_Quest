#pragma once
#include "gameNode.h"
#include "progressBar.h"
#include "Item.h"

#define COMMAND1_POSY 580
#define COMMAND2_POSY 620
#define COMMAND3_POSY 660
#define COMMAND4_POSY 700

#define PLAYER1_NAME_Y 580
#define PLAYER2_NAME_Y 620
#define PLAYER3_NAME_Y 660

#define MAX_ACT_GAUGE 1000

enum BATTLE_COMAAND
{
	NO_COMMAND = 0,
	ATTACK_COMMAND = 1,
	ITEM_COMMAND = 2,
	MAGIC_COMMAND = 4,
	RUN_COMMAND = 8,
	DEFFENCE_COMMAND = 16,
	ALL_COMMAND = ATTACK_COMMAND | ITEM_COMMAND | MAGIC_COMMAND | RUN_COMMAND | DEFFENCE_COMMAND
};

class player : public gameNode
{
protected:
	enum SKILL
	{
		FIRST_SKILL,
		SECOND_SKILL,
	};
	enum MOVEDIR
	{
		PLAYER_DOWN,
		PLAYER_UP,
		PLAYER_LEFT,
		PLAYER_RIGHT
	};
	enum BATTLE_MOTION
	{
		ATTACK_MOTION,
		ITEM_MOTION,
		MAGIC_MOTION,
		DEFFENCE_MOTION,
		RUN_MOTION,
		MOTION_END
	};
	
	enum DAMAGETYPE
	{
		SKILL_DAMAGE,
		NORMAL_DAMAGE
	};

	struct tagCommandInfo
	{
		BATTLE_COMAAND selectCommand;
		int target;
		DAMAGETYPE damagetype;
		int totalDamage;
	};

protected:
	string _name;						// �÷��̾� �̸�
	int _partyPos;						// ��Ƽ���� ��ġ
	int _level;							// �÷��̾� ����
	int _str, _int, _agi;				// ��, ����, ��ø
	float _curActGauge, _maxActGauge;	// �ӵ� Ÿ�̸� _curActGauge = ���� �ൿ ������ / _maxActGauge = �ִ� �ൿ ������  
										// _curActGauge �� 0.1�� �ö� _maxActGauge�� �����ϸ� �ൿ ����
	progressBar* _actGauge;				// �ൿ ������
	progressBar* _completeActGauge;		// �ൿ ������ �ִ�

	int _x, _y;							// �÷��̾� x,y ��ǥ
	int _frameX, _frameY;				// ������ ��ǥ
						
	int _maxHp, _currentHp;				// ü��
	int _maxMp, _currentMp;				// ����
	int _mp;							// �Һ񸶳�
	int _damage, _m_Damage;				// �������ݷ�, �������ݷ�
	int _min, _max;						// ���� �ּҰ��ݷ�, �ִ���ݷ�
	int _m_min, _m_max;					// ���� �ּҰ��ݷ�, �ִ���ݷ�
	int _def, _m_def;					// ��������, ��������
	int _gold;							// ���
	int _exp;							// ����ġ
	int _maxExp;						// �ִ����ġ
	int _currentExp;					// �������ġ

	bool _isDead;						// ������� true = ���� , false ����

	bool _isBattle;						// ��Ʋ�������� true = ��Ʋ �ϰ� ����, false = ��Ʋ ���ϰ� ���� 
	bool _isFight;						// �ο����� true = �ο����, false = �Ƚο����
	bool _isAttack;						// ���� ���� true = ���� ����, false ���� �Ұ���
	bool _isCommandReady;				// �÷��̾� �ൿ �غ� ����

	int _enableCommand;
	BATTLE_COMAAND _curCommand;
	BATTLE_COMAAND _selectCommand;

	MOVEDIR _dir;						// �����¿� �Ǵ�
	SKILL _skill;						// ��ų ����
	BATTLE_MOTION _battleMotion;		// ������ �ൿ

	tagCommandInfo _commandInfo;

	int _count;

	tagItem _playerEquip[5];

public:
	player();
	~player();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render(void) = 0;
	void statusRender(void);
	void equipRender(void);

	virtual void drawCommand(void);
	virtual void selectCommand(void);
	virtual void levelUp(void);

	void drawPlayerInfoInBattle(void);
	void increaseActGauge(void);

	void commandAttack(void);
	void commandItem(void);
	void commandMagic(void);
	void commandRun(void);
	void commandReset(void);

public:
	// getset �κ�
	inline void setLevel(int Level) { _level = Level ; }
	inline int getLevel(void) { return _level; }

	inline void setpartyPos(int partyPos) { _partyPos = partyPos; }
	inline int getpartyPos(void) { return _partyPos; }

	inline void setStr(int Str) { _str = Str; }
	inline int getStr(void) { return _str; }

	inline void setAgi(int Agi) { _agi = Agi; }
	inline int getAgi(void) { return _agi; }

	inline void setInt(int Int) { _int = Int; }
	inline int getInt(void) { return _int; }

	inline void setCurActGauge(float curActGauge) { _curActGauge = curActGauge; }
	inline float getCurActGauge(void) { return _curActGauge; }

	inline void setEndTime(float maxActGauge) { _maxActGauge = maxActGauge; }
	inline float getEndTime(void) { return _maxActGauge; }

	inline void setMaxHp(int MaxHp) { _maxHp = MaxHp; }
	inline int getMaxHp(void) { return _maxHp; }

	inline void setDef(int Def) { _def = Def; }
	inline int getDef(void) { return _def; }

	inline void setMDef(int MDef) { _m_def = MDef; }
	inline int getMDef(void) { return _m_def; }

	inline void setCurrentHp(int CurrentHp) { _currentHp = CurrentHp; }
	inline int getCurrentHp(void) { return _currentHp; }

	inline void setMaxMp(int MaxMp) { _maxHp = MaxMp; }
	inline int getMaxMp(void) { return _maxMp; }

	inline void setCurrentMp(int CurrentMp) { _currentMp = CurrentMp; }
	inline int getCurrentMp(void) { return _currentMp; }

	inline void setMp(int Mp) { _mp = Mp; }
	inline int getMp(void) { return _mp; }

	inline void setDamage(int Damage) { _damage = Damage; }
	inline int getDamage(void) { return _damage; }

	inline void setMDamage(int m_damage) { _m_Damage = m_damage; }
	inline int getMDamage(void) { return _m_Damage; }

	inline void setMin(int Min) { _min = Min; }
	inline int getMin(void) { return _min; }

	inline void setMax(int Max) { _max = Max; }
	inline int getMax(void) { return _max; }

	inline void setM_Max(int m_Max) { _m_max = m_Max; }
	inline int getM_Max(void) { return _m_max; }

	inline void setExp(int Exp) { _exp = Exp; }
	inline int getExp(void) { return _exp; }

	inline void setMaxExp(int MaxExp) { _maxExp = MaxExp; }
	inline int getMaxExp(void) { return _maxExp; }

	inline void setCurrentExp(int CurrentExp) { _currentExp = CurrentExp; }
	inline int getCurrentExp(void) { return _currentExp; }

	inline void setIsDead(bool IsDead) { _isDead = IsDead; }
	inline bool getIsDead(void) { return _isDead; }

	inline void setIsAttack(bool IsAttack) { _isAttack = IsAttack; }
	inline bool getIsAttack(void) { return _isAttack; }

	inline void setIsCommandReady(bool ready) { _isCommandReady = ready; }
	inline bool getIsCommandReady(void) { return _isCommandReady; }

	inline string getName(void) { return _name; }

	inline tagCommandInfo* getCommand(void) { return &_commandInfo; }

	inline void setplayerEquip(tagItem equips, int num) { _playerEquip[num] = equips; }
	inline tagItem getplayerEquip(int num) { return _playerEquip[num]; }

	inline BATTLE_COMAAND getSelectCommand(void) { return _selectCommand; }
};

