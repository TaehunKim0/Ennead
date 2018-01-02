#pragma once
class Effect : public GameObject
{
protected:
	Animation* m_Effect;

public:
	Effect();
	~Effect(); 

public:
	bool Init(Vector2 pos);
	void Update(float deltaTime);
	void Render();
};