#pragma once
enum class EnemyState
{
	Move = 1,
	Attack,
	Idle
};

enum class EnemyName
{
	Eagle = 1,
	Mummy,
	Anubis,
};

class Enemy : public GameObject
{
protected:

	int m_Health;
	int m_Speed;

	EnemyName m_EName;
	EnemyState m_State;
public:
	Enemy();
	~Enemy();

	void Release();
	bool Init(Vector2 pos);
	void Update(float deltaTime);
	void Render();
};

