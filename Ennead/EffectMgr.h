#pragma once
class EffectMgr : public Singleton<EffectMgr>, public GameObject
{
public:
	EffectMgr();
	~EffectMgr();

	void Update(float deltaTime);
	void Render();

	//void CreateEffect
};

