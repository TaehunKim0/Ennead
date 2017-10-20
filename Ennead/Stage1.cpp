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
	player = Player::GetInstance();
	player->Init();

	player->SetPosition(850, 500);
	Map1 = Sprite::Create(L"Resources/Map/Stage1.png");
	
	EnemySpawner::GetInstance()->SpawnEnemy(Vector2(600, 0), EnemyName::Anubis, 60 * 2);
 //시간 조절해서 생성하자
	EnemySpawner::GetInstance()->SpawnEnemy(Vector2(600, 0), EnemyName::Anubis, 60 * 3);

	/*EnemySpawner::GetInstance()->SpawnEnemy(Vector2(810, -74), EnemyName::Eagle);
	EnemySpawner::GetInstance()->SpawnEnemy(Vector2(720, -148), EnemyName::Eagle);
	EnemySpawner::GetInstance()->SpawnEnemy(Vector2(630, -212), EnemyName::Eagle);*/


	AddChild(Map1);
	AddChild(player);

	AddChild(BulletMgr::GetInstance());
	AddChild(EnemySpawner::GetInstance());

	return true;
}

void Stage1::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
	//BulletMgr::GetInstance()->Update(deltaTime); <-BulletMgr 는 클래스안에 인스턴스르 만들자 //씬이 릴리즈 하지말고 따로 초기화 하자

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