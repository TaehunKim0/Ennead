#include "PrevHeader.h"
#include "Effect.h"


Effect::Effect()
{
}


Effect::~Effect()
{
}

bool Effect::Init(Vector2 pos)
{
	m_Position = pos;

	return true;
}

void Effect::Update(float deltaTime)
{
	GameObject::Update(deltaTime);

}

void Effect::Render()
{
	GameObject::Render();
}
