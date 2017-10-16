#include "PrevHeader.h"
#include "E_Eagle.h"


E_Eagle::E_Eagle()
{
	radius = 10.f;
	radius = D3DXToRadian(radius);
	m_Speed = 3.f;
}

E_Eagle::~E_Eagle()
{
}

E_Eagle * E_Eagle::Create(Vector2 pos)
{
	auto eagle = new (std::nothrow) E_Eagle();
	if (eagle && eagle->Init(pos))
	{
		return eagle;
	}

	SAFE_DELETE(eagle);
	return nullptr;
}

bool E_Eagle::Init(Vector2 pos)
{
	m_Position = pos;
	eagle = Sprite::Create(L"Resources/Enemy/E_Eagle.png");

	m_Collision = BoxCollider::Create(m_Position, m_Size);

	m_Tag = Tag::Enemy;
	m_EName = EnemyName::Eagle;

	AddChild(m_Collision);
	AddChild(eagle);

	return true;
}

void E_Eagle::Release()
{
	Enemy::Release();
}

void E_Eagle::Update(float deltaTime)
{
	Enemy::Update(deltaTime);

	Move();

	if (m_Position.x >= 1200)
	{
		radius = -190.f;
		radius = D3DXToRadian(radius);
	}

	m_Collision->SetPosition(m_Position);

	if (m_Health <= 0)
	{
		CollisionMgr::GetInstance()->Destroy(m_Collision);
		Destroy();
	}

}

void E_Eagle::Render()
{
	Enemy::Render();
}

void E_Eagle::Move()
{
	SetPosition(cos(radius)*m_Speed, sin(radius)*m_Speed);
}

void E_Eagle::OnCollision(GameObject * other)
{
	if (other->GetTag() == Tag::Player)
	{
		m_Health -= 1;
	}
}
