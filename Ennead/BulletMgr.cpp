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

void BulletMgr::CreateRBullet(Vector2 pos, std::wstring img, Tag tag, float radius)
{
	auto rbullet = RBullet::Create(pos, img, tag, radius);
	AddChild(rbullet);
}

void BulletMgr::CreateBullet(Vector2 pos, std::wstring img, Tag tag)
{
	auto bullet = Bullet::Create(pos, img.c_str(), tag);
	AddChild(bullet);

}