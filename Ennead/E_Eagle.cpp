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
	Flying = Animation::Create(30);

	Flying->AddFrame(L"Resources/Enemy/E_Eagle.png");	

	Enemy::Init(pos, Flying, EnemyName::Eagle);

	AddChild(Flying);

	return true;

}

void E_Eagle::Release()
{
	Enemy::Release();
}

void E_Eagle::Update(float deltaTime)
{
	Enemy::Update(deltaTime);
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

void E_Eagle::Attack()
{
}

void E_Eagle::OnCollision(GameObject * other)
{
	if (other->GetTag() == Tag::None)
		return;

	if (other->GetTag() == Tag::Player)
	{
		EffectFactory::GetInstance()->CreateCollisionEffect(m_Position.x, m_Position.y);
		m_Health -= 1;
	}
}
