#include "PrevHeader.h"
#include "Stair.h"


Stair::Stair()
{
	
}


Stair::~Stair()
{
}

Stair * Stair::Create(Vector2 pos)
{
	auto _stair = new (std::nothrow) Stair();
	if (_stair && _stair->Init(pos))
	{
		return _stair;
	}

	SAFE_DELETE(_stair);
	return nullptr;
}

bool Stair::Init(Vector2 pos)
{
	//SetPosition(pos);

	printf("Stair init");
	SetPosition(pos);
	SetTag(Tag::Structure);
	
	stair = Sprite::Create(L"Resources/block1.png");

	m_Size = stair->GetSize();

	//stair->SetVisible(0);

	//stair->Alpha(1);

	m_Collision = BoxCollider::Create(m_Position, stair->GetSize());

	/*Right = BoxCollider::Create(stair->GetPosition() + Vector2{ stair->GetSize().x, 0.f }, stair->GetSize());
	Left = BoxCollider::Create(Vector2{ stair->GetPosition().x - stair->GetSize().x, stair->GetPosition().y }, stair->GetSize());

	Right->SetDirection(Direction::Right);
	Left->SetDirection(Direction::Left);

	auto sp = Sprite::Create(L"Resources/block.png");
	sp->SetPosition(stair->GetPosition() + Vector2{ stair->GetSize().x, 0.f });

	auto sp2 = Sprite::Create(L"Resources/block.png");
	sp2->SetPosition(stair->GetPosition() - Vector2{ stair->GetSize().x, 0.f });
*/
	//stair->SetVisible(0);
	//sp->SetVisible(0);
	//sp2->SetVisible(0);

	AddChild(m_Collision);
	//AddChild(stair);
	//AddChild(Left);
	//AddChild(Right);
	//AddChild(sp);
	//AddChild(sp2);

	return true;
}

void Stair::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

	m_Collision->PositionSet(m_Position.x, m_Position.y + 100.f);

	//Right->PositionSet(stair->GetPosition().x + stair->GetSize().x + 30.f, stair->GetPosition().y);
	//Left->PositionSet( stair->GetPosition().x - stair->GetSize().x, stair->GetPosition().y);

	printf("Stair : %f , %f \n", GetPosition().x, GetPosition().y);
	//printf("LeftCollider : %f , %f\n", Left->GetPosition().x, Left->GetPosition().y);
	//printf("RightCollider : %f , %f\n", Right->GetPosition().x, Right->GetPosition().y);

}

void Stair::Render()
{
	GameObject::Render();
}

void Stair::OnCollision(GameObject * other)
{

}

