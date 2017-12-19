#pragma once
class Effect : public GameObject
{
protected:
	Animation* m_Effect;

public:
	Effect();
	~Effect(); 

	bool Init(Vector2 pos);
	void Update(float deltaTime);
	void Render();
};