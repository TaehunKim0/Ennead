#include"PrevHeader.h"
#include "Player.h"

Player* Player::m_Instance = nullptr;

Player::Player()
	: m_Health(1)
	, m_Speed(4.f)
{
}

Player::~Player()
{
}

void Player::SetAnimWithClass(PlayerClass job)
{
	for (int i = 0; i < 4; i++)
	{
		if (job == PlayerClass::Warrior)
		{
			//Straight->AddFrame
			//Left->
			//Right->
		}

		if (job == PlayerClass::Thief)
		{
			//Straight->AddFrame
			//Left->
			//Right->
		}

		if (job == PlayerClass::Magician)
		{
			//Straight->AddFrame
			//Left->
			//Right->
		}

		if (job == PlayerClass::Archer)
		{
			//Straight->AddFrame
			//Left->
			//Right->
		}

	}
}

Player * Player::GetInstance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new Player();
	}

	return m_Instance;


	return nullptr;
}

void Player::ReleaseInstance()
{
	if (m_Instance != nullptr)
	{
		SAFE_REDELETE(m_Instance);
	}
}

bool Player::Init()
{
	pplayer = Sprite::Create(L"Resources/Player.png");
	pplayer->SetScale(Vector2(0.25f, 0.25f));

	m_Tag = Tag::Player;

	m_Size = Vector2(95, 204);

	m_Collision = BoxCollider::Create(m_Position, m_Size);

	CollisionMgr::GetInstance()->AddBoxCollider(m_Collision);

	AddChild(pplayer);
	AddChild(m_Collision);

	return true;
}

void Player::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	if (m_Health <= 0)
	{
		CollisionMgr::GetInstance()->Destroy(m_Collision);
		Destroy();

		printf("Player dead\n");
	}

	m_Collision->SetPosition(m_Position);

	Move();
	Attack();
	
	if (pState == PlayerState::Move)
	{
		switch (pDirection)
		{
		case PlayerDirection::Up:

			break;

		case PlayerDirection::Down:

			break;

		case PlayerDirection::Left:

			break;

		case PlayerDirection::Right:

			break;

		}
	}


}

void Player::Render()
{
	GameObject::Render();

	if (pState == PlayerState::Move)
	{
		switch (pDirection)
		{
		case PlayerDirection::Up:

			break;

		case PlayerDirection::Down:

			break;

		case PlayerDirection::Left:

			break;

		case PlayerDirection::Right:

			break;

		}
	}
}

void Player::Release()
{
}

void Player::OnCollision(GameObject * other)
{
	if (other->GetTag() == Tag::None)
		return;

	if (other->GetTag() == Tag::Enemy)
		m_Health == 1;



}

void Player::Move()
{
	checkInput = false;

	if (Input::GetInstance()->GetKeyState(VK_LEFT) == KeyState::Pressed)
	{
		this->SetPosition(-m_Speed, 0.f);
		pDirection = PlayerDirection::Left;
		pState = PlayerState::Move;

		checkInput = true;
	}

	if (Input::GetInstance()->GetKeyState(VK_RIGHT) == KeyState::Pressed)
	{
		this->SetPosition(m_Speed, 0.f);
		pDirection = PlayerDirection::Right;
		pState = PlayerState::Move;

		checkInput = true;
	}

	if (Input::GetInstance()->GetKeyState(VK_UP) == KeyState::Pressed)
	{
		this->SetPosition(0.f, -m_Speed);
		pDirection = PlayerDirection::Up;
		pState = PlayerState::Move;

		checkInput = true;
	}

	if (Input::GetInstance()->GetKeyState(VK_DOWN) == KeyState::Pressed)
	{
		this->SetPosition(0.f, m_Speed);
		pDirection = PlayerDirection::Down;
		pState = PlayerState::Move;

		checkInput = true;

	}

	if (!checkInput)
		pState = PlayerState::Idle;

	latingTime++;
	if (latingTime >= 25)
		CanAttack = 1;

}

void Player::Attack()
{
	if(CanAttack)
		if (Input::GetInstance()->GetKeyState(VK_SPACE) == KeyState::Up)
		{
			latingTime = 0;
			CanAttack = 0;

			BulletMgr::GetInstance()->CreateBullet(m_Position + Vector2(15.f, -10.f), L"Resources/sword.png", Tag::Player, 5.f);
			 
  			//BulletMgr::GetInstance()->CreateRBullet(m_Position + Vector2(23.f, -10.f), L"Resources/Bullet.png", Tag::Player, 17.f , 5.f);

			//BulletMgr::GetInstance()->CreateRBullet(m_Position + Vector2(23.f, -10.f), L"Resources/Bullet.png", Tag::Player, -20.f);
		}
	
}
