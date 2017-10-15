#include "PrevHeader.h"
#include "Bullet.h"


Bullet::Bullet()
	: m_Speed(5.f)
{	
}


Bullet::~Bullet()
{
}

Bullet * Bullet::Create(Vector2 pos,std::wstring img, Tag tag)
{
	auto bullet = new (std::nothrow) Bullet();
	if (bullet && bullet->Init(pos,img.c_str(), tag))
	{
		return bullet;
	}

	SAFE_DELETE(bullet);
	return nullptr;
}

bool Bullet::Init(Vector2 pos, std::wstring img, Tag tag)
{
	m_Position = pos;
	m_bullet = Sprite::Create(img.c_str());
	m_Tag = tag;

	m_Collider = BoxCollider::Create(m_Position, m_Size);

	AddChild(m_Collider);
	AddChild(m_bullet);

	return true;
}

void Bullet::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	if (m_Tag == Tag::Player)
	{
		SetPosition(0.f, -5.f);
	}

	if (m_Tag == Tag::Enemy)
	{
		SetPosition(0.f, 5.f);
	}

}

void Bullet::Render()
{
	GameObject::Render();
}
