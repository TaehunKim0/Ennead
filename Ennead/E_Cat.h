#pragma once
class E_Cat : public Enemy
{
public:
	E_Cat();
	~E_Cat();

	static E_Cat* Create(Vector2 pos);

	bool Init(Vector2 pos);
	void Release();

	void Update(float deltaTime);
	void Render();

public:
	void Move();
	void Attack();
};