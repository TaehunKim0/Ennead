#pragma once
class Stair : public GameObject
{
private:
	BoxCollider* Left;
	BoxCollider* Right;

	Sprite* stair;

public:
	Stair();
	~Stair();

	static Stair* Create(Vector2 pos);

	bool Init(Vector2 pos);
	void Update(float deltaTime);
	void Render();

	void OnCollision(GameObject* other);

};

/*
Stair1L = BoxCollider::Create(block->GetPosition() + Vector2{ block->GetSize().x, 0.f }, block->GetSize());
Stair1R = BoxCollider::Create(block->GetPosition() - Vector2{ block->GetSize().x, 0.f }, block->GetSize());

Stair1L->SetTag(Tag::Structure);
Stair1R->SetTag(Tag::Structure);

CollisionMgr::GetInstance()->AddBoxCollider(Stair1L);
CollisionMgr::GetInstance()->AddBoxCollider(Stair1R);


*/