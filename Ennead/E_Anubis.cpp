#include "PrevHeader.h"
#include "E_Anubis.h"


E_Anubis::E_Anubis()
	:Frame(0)
	, KeepTime(0)
{
	m_Speed = 1.f;
	m_State = EnemyState::Move;
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
	m_Position = pos;
	anubis = Sprite::Create(L"Resources/Enemy/E_Anubis.png");

	m_Size = Vector2(80, 100);

	m_Collision = BoxCollider::Create(pos, m_Size);

	m_Tag = Tag::Enemy;
	m_EName = EnemyName::Anubis;

	AddChild(anubis);
	AddChild(m_Collision);

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

	printf("Frame : %d\n", Frame);

	if (m_State == EnemyState::Attack)
		printf("Attack \n");

	if (m_State == EnemyState::Move)
		printf("Move \n");

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
	radius = 20.f;
	radius = D3DXToRadian(radius);
	++KeepTime;

	if(KeepTime < 60 * 2)
		SetPosition(cos(radius), sin(radius));

	else
	{
		ThrowSpear(Player::GetInstance()->GetPosition(),3.f);
		KeepTime = 0;
	}

	//if(창을 던지고 나서)
	//m_State = Move;
}

void E_Anubis::ThrowSpear(Vector2 targetPosition, int throwSpeed)
{
	double angle = getAngle(m_Position , targetPosition);

	BulletMgr::GetInstance()->CreateRBullet(m_Position, L"Resources/Bullet.png", Tag::Enemy, 70, throwSpeed);

	m_State = EnemyState::Move;
}
