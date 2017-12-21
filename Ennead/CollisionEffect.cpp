#include "PrevHeader.h"
#include "CollisionEffect.h"


CollisionEffect::CollisionEffect()
{
}

CollisionEffect::~CollisionEffect()
{
}

CollisionEffect * CollisionEffect::Create(Vector2 pos)
{
	auto collsionEffect = new(std::nothrow) CollisionEffect;
	if (collsionEffect && collsionEffect->Init(pos))
	{
		return collsionEffect;
	}

	SAFE_DELETE(collsionEffect);
	return nullptr;
}

bool CollisionEffect::Init(Vector2 pos)
{
	m_Position = pos;

	m_Effect = Animation::Create(5);
	m_Effect->AddFrame(L"Resources/Effect/collisioneffect1.png");
	m_Effect->AddFrame(L"Resources/Effect/collisioneffect2.png");
	m_Effect->AddFrame(L"Resources/Effect/collisioneffect3.png");

	AddChild(m_Effect);

	return true;
}

void CollisionEffect::Update(float deltaTime)
{
	Effect::Update(deltaTime);

	if (m_Effect->GetIsAnd())
	{
		Destroy();
	}
}

void CollisionEffect::Render()
{
	Effect::Render();
}
