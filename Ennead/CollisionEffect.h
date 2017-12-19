#pragma once
class CollisionEffect : public Effect
{
private:


public:
	CollisionEffect();
	~CollisionEffect();

	static CollisionEffect* Create(Vector2 pos);

	bool Init(Vector2 pos);
	void Update(float deltaTime);
	void Render();
};

