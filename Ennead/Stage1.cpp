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
	Scene::Init();
	player = new Player();
	player->Init();

	Map1 = Sprite::Create(L"Resources/Map/Stage1.png");
	
	AddChild(Map1);
	AddChild(player);
	return true;
}

void Stage1::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	BulletMgr::GetInstance()->Update(deltaTime);

	if (Input::GetInstance()->GetKeyState('1') == KeyState::Pressed)
	{
		GetCamera()->Translate(0, 10);
	}

}

void Stage1::Render()
{
	GameObject::Render();
	BulletMgr::GetInstance()->Render();
}
