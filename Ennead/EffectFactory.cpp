#include "PrevHeader.h"
#include "EffectFactory.h"
#include"CollisionEffect.h"

EffectFactory::EffectFactory()
{
}


EffectFactory::~EffectFactory()
{
}

void EffectFactory::CreateDeadEffect(float x, float y)
{

}

void EffectFactory::CreateCollisionEffect(float x, float y)
{
	auto effect = CollisionEffect::Create(Vector2{ x,y });
	
	AddChild(effect);
}

void EffectFactory::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void EffectFactory::Render()
{
	GameObject::Render();
}
