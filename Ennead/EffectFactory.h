#pragma once
class EffectFactory: public Singleton<EffectFactory> , public GameObject
{
private:
	std::vector<Effect*> m_Effects;

public:
	EffectFactory();
	~EffectFactory();

	void Update(float deltaTime);
	void Render();

public:
	void CreateDeadEffect(float x, float y);
	void CreateCollisionEffect(float x, float y);
};

