#include "PrevHeader.h"
#include "Stage2.h"


Stage2::Stage2()
{
}


Stage2::~Stage2()
{
}

bool Stage2::Init()
{
	printf("Stage2 Init\n");

	AddChild(BulletMgr::GetInstance());

	return true;
}

void Stage2::Update(float deltaTime)
{
	Scene::Update(deltaTime);
}

void Stage2::Render()
{
	Scene::Render();
}
