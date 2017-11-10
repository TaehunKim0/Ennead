#pragma once


class Bullet : public GameObject
{
private:
	Sprite* m_bullet;
	int m_Speed;
	bool IsCollide;

public:
	Bullet();
	~Bullet();

	static Bullet* Create(Vector2 pos, std::wstring img, Tag tag);

	void SetSpeed(float speed) { m_Speed = speed; }
	void Release();
	bool Init(Vector2 pos,std::wstring img, Tag tag);
	void Update(float deltaTime);
	void Render();
	
	void OnCollision(GameObject* other);

};





