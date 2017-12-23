#pragma once
class E_Cobra : public Enemy
{
public:
	E_Cobra();
	~E_Cobra();

	static E_Cobra* Create(Vector2 pos);
	
public:
	bool Init(Vector2 pos);
	void Release();

	void Update(float deltaTime);
	void Render();

public:
	void Move();
	void Attack();
};

