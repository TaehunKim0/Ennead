#include "PrevHeader.h"
#include "E_Anubis.h"


E_Anubis::E_Anubis()
{
	m_Speed = 1.f;
}

E_Anubis::~E_Anubis()
{
}

E_Anubis * E_Anubis::Create(Vector2 pos)
{
	auto anubis = new (std::nothrow) E_Anubis();
	if (anubis && anubis->Init(pos))
	{
		return anubis;
	}

	SAFE_DELETE(anubis);
	return nullptr;
}

bool E_Anubis::Init(Vector2 pos)
{
	m_Position = pos;
	anubis = Sprite::Create(L"Resources/Enemy/E_Anubis.png");

	m_Size = Vector2(80, 100);

	m_Collision = BoxCollider::Create(pos, m_Size);

	m_Tag = Tag::Enemy;
	m_EName = EnemyName::Anubis;

	AddChild(anubis);
	AddChild(m_Collision);

	return true;
}

void E_Anubis::Release()
{
	Enemy::Release();
}

void E_Anubis::Update(float deltaTime)
{
	Enemy::Update(deltaTime);

	if (m_Health <= 0)
	{
		CollisionMgr::GetInstance()->Destroy(m_Collision);
		Destroy();
	}

}

void E_Anubis::Render()
{
	Enemy::Render();
}

void E_Anubis::OnCollision(GameObject * other)
{
	if (other->GetTag() == Tag::Player)
	{
		m_Health -= 1;
	}
}
