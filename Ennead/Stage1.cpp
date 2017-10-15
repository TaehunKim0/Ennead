#include"PrevHeader.h"
#include "Stage1.h"


Stage1::Stage1()
{
}


Stage1::~Stage1()
{
}

bool Stage1::Init()
{
	player = new Player();
	player->Init();

	AddChild(player);
	return true;
}

void Stage1::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	BulletMgr::GetInstance()->Update(deltaTime);
}

void Stage1::Render()
{
	GameObject::Render();
	BulletMgr::GetInstance()->Render();
}
