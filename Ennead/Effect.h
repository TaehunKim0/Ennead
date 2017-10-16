#pragma once
class Effect : public GameObject
{
private:


public:
	Effect();
	~Effect();

	void Update(float deltaTime);
	void Render();
};