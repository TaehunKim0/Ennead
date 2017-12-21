#include "PrevHeader.h"
#include "E_Thoth.h"


E_Thoth::E_Thoth()
{
}


E_Thoth::~E_Thoth()
{
}

E_Thoth * E_Thoth::Create(Vector2 pos)
{
	auto thoth = new(std::nothrow) E_Thoth();
	if (thoth && thoth->Init(pos))
	{
		return thoth;
	}

	SAFE_DELETE(thoth);
	return nullptr;
}

bool E_Thoth::Init(Vector2 pos)
{


	m_Position = pos;

	return true;
}

void E_Thoth::Update(float deltaTime)
{
	Enemy::Update(deltaTime);
}

void E_Thoth::Render()
{
	Enemy::Render();
}

void E_Thoth::Attack()
{
	BulletMgr::GetInstance()->CreateRBullet(m_Position, L"Resources/Bullet.png", Tag::Enemy, 90, 2.f);
	BulletMgr::GetInstance()->CreateRBullet(m_Position, L"Resources/Bullet.png", Tag::Enemy, 90, 2.f);
	BulletMgr::GetInstance()->CreateRBullet(m_Position, L"Resources/Bullet.png", Tag::Enemy, 90, 2.f);

}
