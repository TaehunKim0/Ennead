#include "PrevHeader.h"
#include "Enemy.h"


Enemy::Enemy()
	:m_Health(1)
	,m_Speed(5.f)
{
}


Enemy::~Enemy()
{
}


void Enemy::Release()
{
}

bool Enemy::Init(Vector2 pos)
{
	m_Position = pos;

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
