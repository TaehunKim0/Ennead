#include "PrevHeader.h"
#include "E_Spinks.h"


E_Spinks::E_Spinks()
{
}


E_Spinks::~E_Spinks()
{
}

E_Spinks * E_Spinks::Create(Vector2 pos)
{
	auto spinks = new (std::nothrow) E_Spinks();
	if (spinks && spinks->Init(pos))
	{
		return spinks;
	}

	SAFE_DELETE(spinks);
	return nullptr;
}

void E_Spinks::Update(float deltaTime)
{
	Enemy::Update(deltaTime);
}

void E_Spinks::Render()
{
	Enemy::Render();
}

bool E_Spinks::Init(Vector2 pos)
{
	m_Anim = Animation::Create(10);
	m_Anim->AddFrame(L"Resources/Enemy/E_Spinks.png");

	Enemy::Init(pos, m_Anim, EnemyName::Spinks);

	AddChild(m_Anim);

	return true;
}
