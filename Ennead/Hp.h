#pragma once

class Hp : public GameObject
{
private:
	Sprite* m_Hp;
	int PlayerHp;

public:
	Hp();
	~Hp();

	void GetHp(int hp);

	bool Init(Vector2 pos);

	void Update(float deltaTime);
	void Render();


};

