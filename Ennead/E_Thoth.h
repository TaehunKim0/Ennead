#pragma once



class E_Thoth : public Enemy
{
public:
	
	int Frame;
	int AFrame;

public:
	E_Thoth();
	~E_Thoth();

	static E_Thoth* Create(Vector2 pos);

	bool Init(Vector2 pos);

	void Update(float deltaTime);
	void Render();

public:
	void Move();
	void Attack();

};

