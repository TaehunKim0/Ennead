#include "PrevHeader.h"
#include "E_Thoth.h"


E_Thoth::E_Thoth()
	:Frame(0)
	,AFrame(0)
{
	m_State = EnemyState::Move;
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

	if (m_Health <= 0)
	{
		CollisionMgr::GetInstance()->Destroy(m_Collision);
		Destroy();
	}

	if (Frame >= 360)
	{
		m_State = EnemyState::Attack;
		Frame = 0;
	}

	switch (m_State)
	{

	case EnemyState::Attack:
		{
			Attack();
			break;
		}

	case EnemyState::Move:
		{
			Frame++;
			Move();
			break;
		}

	}

}

void E_Thoth::Render()
{
	Enemy::Render();
}

void E_Thoth::Move()
{
	SetPosition(0.f, 1.f);
	
}

void E_Thoth::Attack()
{
	AFrame++;
	if (AFrame <= 270)
	{
		switch (m_Direction)
		{

		case EnemyDirection::Left:
		{
			SetPosition(-1.f, 0.f);
			break;
		}


		case EnemyDirection::Right:
		{
			SetPosition(1.f, 0.f);
			break;
		}
		}
	}
	else
	{
		BulletMgr::GetInstance()->CreateRBullet(m_Position + Vector2{ 20.f,30.f }, L"Resources/Bullet.png", Tag::Enemy, -60.f, 5.f);

		BulletMgr::GetInstance()->CreateRBullet(m_Position + Vector2{ 20.f,30.f }, L"Resources/Bullet.png", Tag::Enemy, -45.f, 5.f);

		BulletMgr::GetInstance()->CreateBullet(m_Position + Vector2{ 20.f,30.f }, L"Resources/Bullet.png", Tag::Enemy, 5.f);
		
		m_State = EnemyState::Move;

		AFrame = 0;

	}
	
	}

	/*BulletMgr::GetInstance()->CreateRBullet(m_Position + Vector2{ 20.f,30.f }, L"Resources/Bullet.png", Tag::Enemy, -60.f, throwSpeed);

	BulletMgr::GetInstance()->CreateRBullet(m_Position + Vector2{ 20.f,30.f }, L"Resources/Bullet.png", Tag::Enemy, -45.f, throwSpeed);

	BulletMgr::GetInstance()->CreateBullet(m_Position + Vector2{ 20.f,30.f }, L"Resources/Bullet.png", Tag::Enemy, throwSpeed);
	*/
