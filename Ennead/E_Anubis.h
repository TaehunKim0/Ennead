#pragma once
class E_Anubis : public Enemy
{
private:
	Sprite* anubis;

	int Frame;

public:
	E_Anubis();
	~E_Anubis();

	static E_Anubis* Create(Vector2 pos);

	bool Init(Vector2 pos);
	void Release();
	void Update(float deltaTime);
	void Render();

	void OnCollision(GameObject* other);

public:
	void MoveAttackCheck();

	void Move();
	void Attack();
	void ThrowSpear(Vector2 targetPosition, int throwSpeed);
};