#pragma once



class E_Anubis : public Enemy
{
private:
	
	 float GetAngle(Vector2 p1, Vector2 p2)
	 {
		float xdf = p2.x - p1.x;
		float ydf = p2.y - p1.y;

		float ang = D3DXToRadian((atan2(ydf, xdf)));

		//printf("angle = %f\n", ang2);

		return ang;
	}
	
private:
	Animation* anubis;
	
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