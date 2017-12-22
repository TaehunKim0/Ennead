#include"PrevHeader.h"
#include "Stage1.h"
#include "Stage2.h"
Stage1::Stage1()
{
	SpawnTime = 0;
}

Stage1::~Stage1()
{
}

void Stage1::Release()
{
	Scene::Release();
}

bool Stage1::Init()
{
	Scene::Init();
	player = Player::GetInstance();
	player->Init();
	//EnemySpawner::GetInstance()->SpawnEnemy(Vector2(800, -100), EnemyName::Anubis, 60 * 2);

	player->SetPosition(850, 500);
	Map1 = Sprite::Create(L"Resources/Stage3.png");
	srand(time(NULL));

	//L"Resources/Map/Stage1.png"
	 
	//시간 조절해서 생성하자

	AddChild(Map1);
	AddChild(player);

	AddChild(BulletMgr::GetInstance());
	AddChild(EnemySpawner::GetInstance());
	AddChild(EffectFactory::GetInstance());


	return true;
}



void Stage1::Update(float deltaTime)
{
	SpawnTime++;
	if (SpawnTime == 60)
	{
		//EffectFactory::GetInstance()->CreateCollisionEffect(500.f, 500.f);
		//EnemySpawner::GetInstance()->SpawnEnemy(Vector2(1000, -100), EnemyName::Anubis, 60 * 2);
		SpawnEnemys();
		SpawnTime = 0;
	}

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

	//if (Input::GetInstance()->GetKeyState(VK_LBUTTON) == KeyState::Down)
	//{
	//	BulletMgr::GetInstance()->Destroy();
	//	EnemySpawner::GetInstance()->Destroy();
	//	EffectFactory::GetInstance()->Destroy();

	//	//BulletMgr::GetInstance()->Release();

	//	Director::GetInstance()->SetScene(Stage2::Create());
	//}

}

void Stage1::Render()
{
	GameObject::Render();
	//BulletMgr::GetInstance()->Render();
}

void Stage1::SpawnEnemys() //랜덤으로 소환 되는 곳
{
	int randomX = 0;
	int randomMonster = 0;
	
	randomX = (rand() % 800) + 600;
	randomMonster = (rand() % 3) + 1;

	/*printf("randomX = %d\n", randomX);
	printf("randomMonster = %d\n", randomMonster);*/

	//andomMonster = 1;

	//아누비스 
	if(randomMonster == 1)
		EnemySpawner::GetInstance()->SpawnEnemy(Vector2(randomX, -100), EnemyName::Anubis, 60 * 2);

	//독수리
	if (randomMonster == 2)
		EnemySpawner::GetInstance()->SpawnEnemy(Vector2(800, -100), EnemyName::Eagle, 60 * 2);

	//미라
	if (randomMonster == 3)
		EnemySpawner::GetInstance()->SpawnEnemy(Vector2(randomX, -100), EnemyName::Mummy, 60 * 2);

	//EnemySpawner::GetInstance()->SpawnEnemy(Vector2(600, 0), EnemyName::Eagle, 60 * 2);
	//EnemySpawner::GetInstance()->SpawnEnemy(Vector2(800, 0), EnemyName::Anubis, 60 * 2);
	//EnemySpawner::GetInstance()->SpawnEnemy(Vector2(1000, 0), EnemyName::Eagle, 60 * 2);
	//EnemySpawner::GetInstance()->SpawnEnemy(Vector2(1200, 0), EnemyName::Eagle, 60 * 2);
}
