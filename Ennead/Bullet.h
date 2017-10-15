#pragma once


class Bullet : public GameObject
{
private:
	Sprite* m_bullet;
	int m_Speed;
	BoxCollider* m_Collider;

public:
	Bullet();
	~Bullet();

	static Bullet* Create(Vector2 pos, std::wstring img, Tag tag);

	bool Init(Vector2 pos,std::wstring img, Tag tag);
	void Update(float deltaTime);
	void Render();
	
};

