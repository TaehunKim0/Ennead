#pragma once
class E_Anubis : public Enemy
{
private:
	Sprite* anubis;

public:
	E_Anubis();
	~E_Anubis();

	static E_Anubis* Create(Vector2 pos);

	bool Init(Vector2 pos);
	void Release();
	void Update(float deltaTime);
	void Render();

	void OnCollision(GameObject* other);
};

