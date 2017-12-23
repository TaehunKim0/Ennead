#include "PrevHeader.h"
#include "E_Cat.h"


E_Cat::E_Cat()
{
}


E_Cat::~E_Cat()
{
}

E_Cat * E_Cat::Create(Vector2 pos)
{
	auto cat = new (std::nothrow) E_Cat();
	if (cat && cat->Init(pos))
	{
		return cat;
	}

	SAFE_DELETE(cat);
	return nullptr;
}

bool E_Cat::Init(Vector2 pos)
{
	

	return true;
}

void E_Cat::Release()
{
	Enemy::Release();
}

void E_Cat::Update(float deltaTime)
{
	Enemy::Update(deltaTime);
}

void E_Cat::Render()
{
	Enemy::Render();
}

void E_Cat::Move()
{
}

void E_Cat::Attack()
{
}
