#include "PrevHeader.h"
#include "EffectMgr.h"


EffectMgr::EffectMgr()
{
}


EffectMgr::~EffectMgr()
{
}

void EffectMgr::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void EffectMgr::Render()
{
	GameObject::Render();
}