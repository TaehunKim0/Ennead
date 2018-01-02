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
	case EnemyState::Stand:
		
		break;

	case EnemyState::Walk:

		break;

	case EnemyState::Attack:

		break;
	}
}

void Enemy::UpdateMoveMent()
{
}
