#pragma once
class E_Mummy : public Enemy
{
private:
	Sprite* mummy;


public:
	E_Mummy();
	~E_Mummy();

	static E_Mummy* Create(Vector2 pos);

	bool Init(Vector2 pos);
	void Update(float deltaTime);
	void Render();
};

