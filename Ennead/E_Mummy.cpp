#include "PrevHeader.h"
#include "E_Mummy.h"


E_Mummy::E_Mummy()
{
}


E_Mummy::~E_Mummy()
{
}

E_Mummy * E_Mummy::Create(Vector2 pos)
{
	auto mummy = new (std::nothrow) E_Mummy();
	if (mummy && mummy->Init(pos))
	{
		return mummy;
	}
	SAFE_DELETE(mummy);
	return nullptr;
}

bool E_Mummy::Init(Vector2 pos)
{
	Enemy::Init(pos);

	m_Position = pos;

	m_Name = EnemyName::Mummy;
	mummy = Sprite::Create(L"Resources/Enemy/E_Mummy.png");

	AddChild(mummy);

	return true;
}

void E_Mummy::Update(float deltaTime)
{
	Enemy::Update(deltaTime);

	SetPosition(0.f, 1.f);

}

void E_Mummy::Render()
{
	GameObject::Render();
}
