#include"PrevHeader.h"
#include "Player.h"


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

		if (job == PlayerClass::Assassin)
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

bool Player::Init()
{
	player = Sprite::Create(L"Resources/Anubis.png");
	m_Tag = Tag::Player;

	AddChild(player);
	
	return true;
}

void Player::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

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


}

void Player::Attack()
{
	if (Input::GetInstance()->GetKeyState(VK_SPACE) == KeyState::Up)
	{
		BulletMgr::GetInstance()->CreateBullet(m_Position + Vector2(23.f, 0.f), L"Resources/Bullet.png", BulletTag::Player);
	}
}
