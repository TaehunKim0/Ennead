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
	Cat,
	Cobra,
	Thoth
};

enum class EnemyDirection
{
	None,
	Left = 1,
	Right
};

class Enemy : public GameObject
{
protected:
	Sprite* m_Sprite;
	Animation * m_Anim;

	int m_Health;
	int m_Speed;

	EnemyName m_EName;
	EnemyState m_State;
	EnemyDirection m_Direction;

public:
	Enemy();
	~Enemy();

	void Release();
	bool Init(Vector2 pos,Animation* anim, EnemyName name);

	void Update(float deltaTime);
	void Render();

};

//void Idle() Enemy ���� ���� Idle
//void OnIdle() Enemy �� ��ӹ��� ������ Idle
