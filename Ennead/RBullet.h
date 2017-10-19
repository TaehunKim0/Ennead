#pragma once
class RBullet : public GameObject
{
private:
	Sprite* m_bullet;
	int m_Speed;
	bool IsCollide;

	float m_Radius;

public:
	RBullet();
	~RBullet();

	static RBullet* Create(Vector2 pos, std::wstring img, Tag tag, float radius);

	void SetSpeed(float speed) { m_Speed = speed; }
	void Release();
	bool Init(Vector2 pos, std::wstring img, Tag tag, float radius);
	void Update(float deltaTime);
	void Render();

	void OnCollision(GameObject* other);
};

