#include "PrevHeader.h"
#include "E_Cobra.h"


E_Cobra::E_Cobra()
{
}


E_Cobra::~E_Cobra()
{
}

E_Cobra * E_Cobra::Create(Vector2 pos)
{
	auto cobra = new (std::nothrow) E_Cobra();
	if (cobra && cobra->Init(pos))
	{
		return cobra;
	}

	SAFE_DELETE(cobra);
	return nullptr;
}

bool E_Cobra::Init(Vector2 pos)
{




	return true;
}

void E_Cobra::Release()
{
	Enemy::Release();
}

void E_Cobra::Update(float deltaTime)
{
	Enemy::Update(deltaTime);
}

void E_Cobra::Render()
{
	Enemy::Render();
}

void E_Cobra::Move()
{
}

void E_Cobra::Attack()
{
}
