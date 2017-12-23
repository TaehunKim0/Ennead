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

class Enemy : public GameObject
{
protected:
	Sprite* m_Sprite;
	Animation * m_Anim;

	int m_Health;
	int m_Speed;

	EnemyName m_EName;
	EnemyState m_State;
public:
	Enemy();
	~Enemy();

	void Release();
	bool Init(Vector2 pos,Animation* anim, EnemyName name);

	void Update(float deltaTime);
	void Render();

};

//void Idle() Enemy 들의 공통 Idle
//void OnIdle() Enemy 를 상속받은 각각의 Idle
