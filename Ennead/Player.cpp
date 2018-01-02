#include"PrevHeader.h"
#include "Player.h"

Player* Player::m_Instance = nullptr;

Player::Player()
	: m_Health(1)
	, m_Speed(4.f)
	, canMoveRight(1)
	, canMoveLeft(1)
	, canMoveDown(1)
	, canMoveUp(1)
{
	m_State = PlayerState::Move;
	m_Location = PlayerLocation::None;
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
	//pplayer->SetScale(Vector2{ 0.5f,0.5f });

	pplayer->SetScale(Vector2(2.f, 2.f));

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

	printf("Player Position : %f, %f \n", m_Position.x, m_Position.y);

	if (m_Health <= 0)
	{
		CollisionMgr::GetInstance()->Destroy(m_Collision);
		Destroy();

		printf("Player dead\n");
	}

	m_Collision->SetPosition(m_Position);

	//if(m_State == PlayerState::Move)
	Move();

	//Attack();
	
	if (m_State == PlayerState::Move)
	{
		switch (m_Direction)
		{
		case Direction::Up:

			break;

		case Direction::Down:

			break;

		case Direction::Left:

			break;

		case Direction::Right:

			break;

		}
	}

}

void Player::Render()
{
	GameObject::Render();

	if (m_State == PlayerState::Move)
	{
		switch (m_Direction)
		{
		case Direction::Up:

			break;

		case Direction::Down:

			break;

		case Direction::Left:

			break;

		case Direction::Right:

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

	if (other->GetTag() == Tag::Structure)
	{
		printf("Structure Collision\n");
		m_Location = PlayerLocation::Stair;
		OtherPos = other->GetPosition();
		OtherSize = other->GetSize();

	}

}

void Player::Move()
{
	checkInput = false;

	if (m_Location == PlayerLocation::Stair)
	{
		if (m_Position.x < OtherPos.x)
		{
			canMoveLeft = 0;
		}

		if (m_Position.x > OtherPos.x + OtherSize.x - 50.f)
		{
			canMoveRight = 0;
		}

		if (m_Position.y < OtherPos.y)
		{
			m_Location = PlayerLocation::None;
		}

		if (m_Position.y > OtherPos.y + OtherSize.y)
			m_Location = PlayerLocation::None;

		


	}


	if (canMoveLeft)
	{
		if (Input::GetInstance()->GetKeyState('A') == KeyState::Pressed)
		{
			this->SetPosition(-m_Speed, 0.f);
			m_Direction = Direction::Left;
			m_State = PlayerState::Move;

			checkInput = true;
			canMoveRight = 1;
			canMoveUp = 1;
			canMoveDown = 1;
		}
	}

	if (canMoveRight)
	{
		if (Input::GetInstance()->GetKeyState('D') == KeyState::Pressed)
		{
			this->SetPosition(m_Speed, 0.f);
			m_Direction = Direction::Right;
			m_State = PlayerState::Move;

			checkInput = true;
			canMoveLeft = 1;
			canMoveDown = 1;
			canMoveUp = 1;
		}
	}
	
	if (canMoveUp)
	{
		if (Input::GetInstance()->GetKeyState('W') == KeyState::Pressed)
		{
			this->SetPosition(0.f, -m_Speed);
			m_Direction = Direction::Up;
			m_State = PlayerState::Move;

			checkInput = true;
			canMoveLeft = 1;
			canMoveRight = 1;
			canMoveUp = 1;
		}
	}

	if (canMoveDown)
	{
		if (Input::GetInstance()->GetKeyState('S') == KeyState::Pressed)
		{
			this->SetPosition(0.f, m_Speed);
			m_Direction = Direction::Down;
			m_State = PlayerState::Move;

			checkInput = true;
			canMoveLeft = 1;
			canMoveRight = 1;
			canMoveUp = 1;
		}
	}

	if (!checkInput)
		m_State = PlayerState::Idle;

	latingTime++;
	if (latingTime >= 25)
		CanAttack = 1;

}

void Player::Attack()
{
	if(CanAttack)
		if (Input::GetInstance()->GetKeyState(VK_LBUTTON) == KeyState::Up)
		{
			latingTime = 0;
			CanAttack = 0;

			auto angle = GetAngle(m_Position, Input::GetInstance()->GetMousePosition());

			BulletMgr::GetInstance()->CreateRBullet(m_Position + Vector2(10.f, -10.f), L"Resources/Bullet.png", Tag::Player, -angle , 10.f);

			//BulletMgr::GetInstance()->CreateBullet(m_Position + Vector2(15.f, -10.f), L"Resources/sword.png", Tag::Player, 5.f);
			 
  			//BulletMgr::GetInstance()->CreateRBullet(m_Position + Vector2(23.f, -10.f), L"Resources/Bullet.png", Tag::Player, 17.f , 5.f);

			//BulletMgr::GetInstance()->CreateRBullet(m_Position + Vector2(23.f, -10.f), L"Resources/Bullet.png", Tag::Player, -20.f);
		}
	
}
