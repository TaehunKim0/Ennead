#pragma once
class E_Mummy : public Enemy
{
private:
	Animation * mummy;
	
public:
	//BoxCollider* m_Collision;
	E_Mummy();
	~E_Mummy();

	static E_Mummy* Create(Vector2 pos);

	void Release();
	bool Init(Vector2 pos);
	void Update(float deltaTime);
	void Render();

	void OnCollision(GameObject* other);

public:
	void Move();
	void Attack();
};