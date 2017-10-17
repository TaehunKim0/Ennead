#include"PrevHeader.h"
#include "Stage1.h"

Stage1::Stage1()
{
}


Stage1::~Stage1()
{
}

void Stage1::Release()
{
}

bool Stage1::Init()
{
	Scene::Init();
	player = new Player();
	player->Init();

	player->SetPosition(850, 500);
	Map1 = Sprite::Create(L"Resources/Map/Stage1.png");
	
	EnemySpawner::GetInstance()->SpawnEnemy(Vector2(700, 0), EnemyName::Anubis);

	AddChild(Map1);
	AddChild(player);

	AddChild(BulletMgr::GetInstance());
	AddChild(EnemySpawner::GetInstance());

	return true;
}

void Stage1::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	//BulletMgr::GetInstance()->Update(deltaTime); <-BulletMgr �� Ŭ�����ȿ� �ν��Ͻ��� ������ //���� ������ �������� ���� �ʱ�ȭ ����

	//player->m_Collision->IsCollisionWith(Map1->m_c)

	if (Input::GetInstance()->GetKeyState('1') == KeyState::Pressed)
	{
		GetCamera()->Translate(0, 10);
	}

	if (Input::GetInstance()->GetKeyState('2') == KeyState::Pressed)
	{
		GetCamera()->Translate(0, -10);
	}

}

void Stage1::Render()
{
	GameObject::Render();
	//BulletMgr::GetInstance()->Render();
}
