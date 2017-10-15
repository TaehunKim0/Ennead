#pragma once
enum class BulletTag
{
	Player = 1,
	Enemy
};

class Bullet : public GameObject
{
private:
	Sprite* m_bullet;
	int m_Speed;

public:
	Bullet();
	~Bullet();

	BulletTag m_Tag;

	static Bullet* Create(Vector2 pos, std::wstring img, BulletTag tag);

	bool Init(Vector2 pos,std::wstring img, BulletTag tag);
	void Update(float deltaTime);
	void Render();
	
};

