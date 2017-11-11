#include "PrevHeader.h"
#include "BulletMgr.h"


BulletMgr::BulletMgr()
{
}


BulletMgr::~BulletMgr()
{
}

void BulletMgr::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void BulletMgr::Render()
{
	GameObject::Render();
}

void BulletMgr::Release()
{
}

void BulletMgr::CreateRBullet(Vector2 pos, std::wstring img, Tag tag, float radius,float speed)
{
	auto rbullet = RBullet::Create(pos, img, tag, radius);
	rbullet->SetSpeed(speed);
	AddChild(rbullet);
}

void BulletMgr::CreateBullet(Vector2 pos, std::wstring img, Tag tag, float speed)
{
	auto bullet = Bullet::Create(pos, img.c_str(), tag);
	bullet->SetSpeed(speed);
	AddChild(bullet);

}
