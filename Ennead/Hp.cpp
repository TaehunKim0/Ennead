#include "PrevHeader.h"
#include "Hp.h"


Hp::Hp()
{
}


Hp::~Hp()
{
}

void Hp::GetHp(int hp)
{
	PlayerHp = hp;
}

bool Hp::Init(Vector2 pos)
{
	m_Hp = Sprite::Create(L"Resources/hp.png");

	AddChild(m_Hp);

	return true;
}

void Hp::Update(float deltaTime)
{
	GameObject::Update(deltaTime);




}

void Hp::Render()
{
	GameObject::Render();
}
