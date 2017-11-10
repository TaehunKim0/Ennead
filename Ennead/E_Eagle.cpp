#include "PrevHeader.h"
#include "E_Eagle.h"


E_Eagle::E_Eagle()
{
	radius = 10.f;
	radius = D3DXToRadian(radius);
	m_Speed = 3.f;
	c = 0.f;
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

	m_Size = Vector2(82, 74);

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

	//for (int i = 1; i < 100;)
	//	radius = -190.f * -i;

	//if (m_Position.x >= 1200)
	//{
	//	radius = -190.f;
	//	radius = D3DXToRadian(radius);
	//}

	Move();

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
	c += 0.02f;

	

	SetPosition(cos(c) * 5, 1);
	
}

void E_Eagle::OnCollision(GameObject * other)
{
	if (other->GetTag() == Tag::None)
		return;

	if (other->GetTag() == Tag::Player)
	{
		m_Health -= 1;
	}
}
