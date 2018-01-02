#include "PrevHeader.h"
#include "Enemy.h"


Enemy::Enemy()
	:m_Health(1)
	,m_Speed(2.f)
{
}

Enemy::~Enemy()
{
}

void Enemy::Release()
{
	GameObject::Release();
}

bool Enemy::Init(Vector2 pos, Animation *anim, EnemyName name)
{
	m_Position = pos;
	m_Size = anim->GetSize();
	m_Collision = BoxCollider::Create(m_Position, m_Size);
	m_Tag = Tag::Enemy;
	m_EName = name;

	AddChild(m_Collision);

	return true;
}

void Enemy::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	if (m_Health <= 0)
		m_State = EnemyState::Dead;

	m_Collision->SetPosition(m_Position);

	UpdateState();
	UpdateMoveMent();
}

void Enemy::Render()
{
	GameObject::Render();
}

void Enemy::UpdateState()
{
	switch (m_State)
	{
	case EnemyState::Move:
		Move();
		break;

	case EnemyState::Attack:
		Attack();
		break;

	case EnemyState::Dead:
	{
		CollisionMgr::GetInstance()->Destroy(m_Collision);
		Destroy();
		break;
	}
	}
}

void Enemy::UpdateMoveMent()
{

}
