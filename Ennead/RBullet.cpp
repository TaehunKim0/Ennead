#include "PrevHeader.h"
#include "RBullet.h"


RBullet::RBullet()
	: IsCollide(0)
	, m_Speed(5.f)
{
}

RBullet::~RBullet()
{
}

RBullet * RBullet::Create(Vector2 pos, std::wstring img, Tag tag, float radius)
{
	auto rbullet = new (std::nothrow) RBullet();
	if (rbullet && rbullet->Init(pos, img, tag, radius))
	{
		return rbullet;
	}

	SAFE_DELETE(rbullet);
	return nullptr;
}

void RBullet::Release()
{
	GameObject::Release();
}

bool RBullet::Init(Vector2 pos, std::wstring img, Tag tag, float radius)
{
	m_Position = pos;
	m_bullet = Sprite::Create(img.c_str());
	m_Tag = tag;
	m_Radius =  radius;

	m_Collision = BoxCollider::Create(m_Position, m_Size);

	AddChild(m_Collision);
	AddChild(m_bullet);

	return true;
}

void RBullet::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	if (IsCollide)
	{
		CollisionMgr::GetInstance()->Destroy(m_Collision);
		Destroy();
	}

	if (m_Tag == Tag::Player)
	{
		SetPosition(cos(m_Radius) * m_Speed,sin(m_Radius) *m_Speed);
	}

	if (m_Tag == Tag::Enemy)
	{
		SetPosition(-cos(m_Radius),-sin(m_Radius));
	}

}

void RBullet::Render()
{
	GameObject::Render();
}

void RBullet::OnCollision(GameObject * other)
{

}
