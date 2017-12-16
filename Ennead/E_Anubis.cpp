#include "PrevHeader.h"
#include "E_Anubis.h"


E_Anubis::E_Anubis()
	:Frame(0)
	, KeepTime(0)
{
	m_Speed = 1.f;
	m_State = EnemyState::Move;
	m_Direction = AnubisDirection::Left;
}

E_Anubis::~E_Anubis()
{
}

E_Anubis * E_Anubis::Create(Vector2 pos)
{
	auto anubis = new (std::nothrow) E_Anubis();
	if (anubis && anubis->Init(pos))
	{
		return anubis;
	}

	SAFE_DELETE(anubis);
	return nullptr;
}

bool E_Anubis::Init(Vector2 pos)
{
	anubis = Animation::Create(10);
	anubis->AddFrame(L"Resources/Enemy/E_Anubis.png");

	Enemy::Init(pos, anubis, EnemyName::Anubis);
	AddChild(anubis);

	return true;
}

void E_Anubis::Release()
{
	Enemy::Release();
}

void E_Anubis::Update(float deltaTime)
{
	Enemy::Update(deltaTime);
	MoveAttackCheck();

	if (m_Health <= 0)
	{
		CollisionMgr::GetInstance()->Destroy(m_Collision);
		Destroy();
	}

	/////////////////////////
	if (Frame / 60  == 2)
	{
		m_State = EnemyState::Attack;
		Frame = 0;
	}

	if(m_State == EnemyState::Move)
		Frame++;
	
}

void E_Anubis::Render()
{
	Enemy::Render();
}

void E_Anubis::OnCollision(GameObject * other)
{
	if (other->GetTag() == Tag::Player)
	{
		m_Health -= 1;
	}
}

void E_Anubis::MoveAttackCheck()
{
	switch (m_State)
	{
	case EnemyState::Move:
		Move();
		break;

	case EnemyState::Attack:
		Attack();
		break;

	}
}

void E_Anubis::Move()
{
	SetPosition(0.f, 0.1f);
}

void E_Anubis::Attack()
{

	//+90

	radius = 20.f;
	radius = D3DXToRadian(radius);
	++KeepTime;

	if (KeepTime < 60 * 2)
	{
		switch (m_Direction)
		{
		case AnubisDirection::Left:
			if (KeepTime < 60 * 2)
				SetPosition(cos((120)*3.f), sin((120)*3.f));

			break;

		case AnubisDirection::Right:
			if (KeepTime < 60 * 2)
				SetPosition(cos(radius*3.f), sin(radius*3.f));

			break;
		}

	}
	else
	{
		ThrowSpear(Player::GetInstance()->GetPosition(),10.f);
		KeepTime = 0;
	}
}

void E_Anubis::ThrowSpear(Vector2 targetPosition, int throwSpeed)
{
	float angle = GetAngle(m_Position , targetPosition);

	BulletMgr::GetInstance()->CreateRBullet(m_Position, L"Resources/Bullet.png", Tag::Enemy, angle, throwSpeed);

	m_State = EnemyState::Move;
}
