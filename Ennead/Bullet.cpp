#include "PrevHeader.h"
#include "Bullet.h"


Bullet::Bullet()
	: m_Speed(5.f)
{	
}


Bullet::~Bullet()
{
}

Bullet * Bullet::Create(Vector2 pos,std::wstring img, BulletTag tag)
{
	auto bullet = new (std::nothrow) Bullet();
	
	if (bullet && bullet->Init(pos,img.c_str(), tag))
	{
		return bullet;
	}

	SAFE_DELETE(bullet);
	return nullptr;
}

bool Bullet::Init(Vector2 pos, std::wstring img, BulletTag tag)
{
	m_Position = pos;
	m_bullet = Sprite::Create(img.c_str());
	m_Tag = tag;

	AddChild(m_bullet);
	return true;
}

void Bullet::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	if (m_Tag == BulletTag::Player)
	{
		SetPosition(0.f, -5.f);
	}

	if (m_Tag == BulletTag::Enemy)
	{
		SetPosition(0.f, 5.f);
	}

}

void Bullet::Render()
{
	GameObject::Render();
}
