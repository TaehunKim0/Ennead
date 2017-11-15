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

bool Enemy::Init(Vector2 pos, std::wstring fileName, EnemyName name)
{
	m_Position = pos;
	m_Sprite = Sprite::Create(fileName.c_str());

	m_Size = m_Sprite->GetSize();

	m_Collision = BoxCollider::Create(m_Position, m_Size);

	m_Tag = Tag::Enemy;
	m_EName = name;

	AddChild(m_Collision);
	AddChild(m_Sprite);

	return true;
}



void Enemy::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void Enemy::Render()
{
	GameObject::Render();
}
