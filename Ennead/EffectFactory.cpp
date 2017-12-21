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
	//m_Effects.push_back(effect);
	
	AddChild(effect);
}
/*
void EffectFactory::Destory(Effect* child)
{
	auto iterator = std::find(std::begin(m_Effects), std::end(m_Effects), child);
	if (iterator != m_Effects.end())
	{
		m_Effects.erase(iterator); 
		SAFE_REDELETE(child);
	}
}
*/
void EffectFactory::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	/*for (int i = 0; i < m_Effects.size(); i++)
	{
		m_Effects[i]->Update(deltaTime);
	}*/
}

void EffectFactory::Render()
{
	GameObject::Render();
	/*for (int i = 0; i < m_Effects.size(); i++)
	{
		m_Effects[i]->Render();
	}*/
}
