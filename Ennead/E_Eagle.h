#pragma once
class E_Eagle : public Enemy
{
private:
	Animation* Flying;
	Sprite * eagle;
	float radius;
	float c;

public:
	E_Eagle();
	~E_Eagle();

	static E_Eagle* Create(Vector2 pos);

	bool Init(Vector2 pos);
	void Release();
	void Update(float deltaTime);
	void Render();

public:
	void Move();
	void OnCollision(GameObject* other);
};

