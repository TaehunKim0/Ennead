#include "PrevHeader.h"
#include "RBullet.h"

/*
회전하는 총알

*/

RBullet::RBullet()
	: IsCollide(0)
	, m_Speed(5.f)
	,m_LifeTime(120)
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

	m_Size = { 50.f,50.f };

	m_Collision = BoxCollider::Create(m_Position, m_Size);

	AddChild(m_Collision);
	AddChild(m_bullet);

	return true;
}

void RBullet::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	m_LifeTime--;

	if (IsCollide || m_LifeTime <= 0)
	{
		printf("RBullet Delete\n");
		CollisionMgr::GetInstance()->Destroy(m_Collision);
		Destroy();
	}

	if (m_Tag == Tag::Player)
	{
		//m_Radius = (m_Radius * 180) / Math_PI;
		//auto Radius = D3DXToRadian(m_Radius);

		auto Radius = (m_Radius * 180) / Math_PI;
		SetPosition(cos(Radius) * m_Speed, -sin(Radius) *m_Speed);
	}

	if (m_Tag == Tag::Enemy)
	{
		auto Radius = (m_Radius * 180) / Math_PI;

		

		SetPosition(cos(Radius)* m_Speed, -sin(Radius)*m_Speed);
	}
}

void RBullet::Render()
{
	GameObject::Render();
}

void RBullet::OnCollision(GameObject * other)
{
	if (other)
	{
		IsCollide = 1;
	}

}
