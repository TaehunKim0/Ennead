#pragma once
enum class EnemyState
{
	Stand,
	Move,
	Attack,
	Dead
};

enum class EnemyName
{
	Eagle = 1,
	Mummy,
	Anubis,
	Cat,
	Cobra,
	Thoth,
	Spinks
};

enum class EnemyDirection
{
	Left = 1,
	Right,
	Up,
	Down
};

class Enemy : public GameObject
{
protected:
	EnemyName m_EName;
	EnemyState m_State;
	EnemyDirection m_Direction;
	Animation * m_Anim;

protected:
	int m_Health;
	int m_Speed;
	Sprite* m_Sprite;

public:
	Enemy();
	~Enemy();

	void Release();
	bool Init(Vector2 pos,Animation* anim, EnemyName name);

	void Update(float deltaTime);
	void Render();

public:
	void UpdateState();
	void UpdateMoveMent();

public:
	virtual void Move() = 0;
	virtual void Attack() = 0;
};