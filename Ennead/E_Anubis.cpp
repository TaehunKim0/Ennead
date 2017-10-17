#include "PrevHeader.h"
#include "E_Anubis.h"


E_Anubis::E_Anubis()
	:Frame(0)
{
	m_Speed = 1.f;
	m_State = EnemyState::Move;
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
	if (Frame % 10 == 60)
	{
		m_State = EnemyState::Attack;
	}

	Frame++;

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

void E_Anubis::MoveAttackCheck()
{
	switch (m_State)
	{
	case EnemyState::Move:
		Move();
		break;

	case EnemyState::Attack:
		Attack();
		break;

	}
}

void E_Anubis::Move()
{

}

void E_Anubis::Attack()
{
	//if(창을 던지고 나서)
	//m_State = Move;
}
