#pragma once
class BulletMgr : public Singleton<BulletMgr> , public GameObject
{
private:


public:
	BulletMgr();
	~BulletMgr();

	void Update(float deltaTime);
	void Render();

	void CreateBullet(Vector2 pos, std::wstring img, BulletTag tag);
};

