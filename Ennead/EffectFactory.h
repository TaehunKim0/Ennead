#pragma once
class EffectFactory: public Singleton<EffectFactory>
{
private:
	

public:
	EffectFactory();
	~EffectFactory();

	void CreateDeadEffect();
	void CreateColliderEffect();

};

