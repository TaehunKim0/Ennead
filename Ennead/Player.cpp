#include"PrevHeader.h"
#include "Player.h"


Player::Player()
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
	AddChild(player);
	
	return true;
}

void Player::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void Player::Render()
{
	GameObject::Render();
}
