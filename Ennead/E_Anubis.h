#pragma once
class E_Anubis : public Enemy
{
private:
	int getAngle(Vector2 mPosition,Vector2 targetPosition )
	{
		int dx = static_cast<int>(targetPosition.x - mPosition.x);
		int dy = static_cast<int>(targetPosition.y - mPosition.y);

		double rad = atan2(dx, dy);

		double degree = (rad * 180) / Math_PI;

		printf("Degree : %lf", degree);

		return degree;
	}

private:
	Sprite* anubis;

	int Frame;
	float radius;

	int KeepTime;

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