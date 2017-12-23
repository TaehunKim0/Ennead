#pragma once

enum class ThothDirection
{
	Left = 0,
	Right
};

class E_Thoth : public Enemy
{
public:
	ThothDirection m_Direction;

	int Frame;


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

