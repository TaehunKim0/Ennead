#include"PrevHeader.h"
#include "Stage1.h"

Stage1::Stage1()
{
	SpawnTime = 0;
	
	

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
	EnemySpawner::GetInstance()->SpawnEnemy(Vector2(800, -100), EnemyName::Anubis, 60 * 2);
	player->SetPosition(850, 500);
	Map1 = Sprite::Create(L"Resources/Map/Stage1.png");
	srand(time(NULL));
	

	//�ð� �����ؼ� ��������

	AddChild(Map1);
	AddChild(player);

	AddChild(BulletMgr::GetInstance());
	AddChild(EnemySpawner::GetInstance());

	return true;
}



void Stage1::Update(float deltaTime)
{
	SpawnTime++;
	if (SpawnTime == 40)
	{
		SpawnEnemys();
		SpawnTime = 0;
	}

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

void Stage1::SpawnEnemys() //�������� ��ȯ �Ǵ� ��
{
	int randomX = 0;
	int randomMonster = 0;
	
	randomX = (rand() % 800) + 600;
	randomMonster = (rand() % 3) + 1;

	printf("randomX = %d\n", randomX);
	printf("randomMonster = %d\n", randomMonster);

	//�ƴ��� 
	if(randomMonster == 1)
		EnemySpawner::GetInstance()->SpawnEnemy(Vector2(randomX, -100), EnemyName::Anubis, 60 * 2);

	//������
	if (randomMonster == 2)
		EnemySpawner::GetInstance()->SpawnEnemy(Vector2(800, -100), EnemyName::Eagle, 60 * 2);

	//�̶�
	if (randomMonster == 3)
		EnemySpawner::GetInstance()->SpawnEnemy(Vector2(randomX, -100), EnemyName::Mummy, 60 * 2);

	//EnemySpawner::GetInstance()->SpawnEnemy(Vector2(600, 0), EnemyName::Eagle, 60 * 2);
	//EnemySpawner::GetInstance()->SpawnEnemy(Vector2(800, 0), EnemyName::Anubis, 60 * 2);
	//EnemySpawner::GetInstance()->SpawnEnemy(Vector2(1000, 0), EnemyName::Eagle, 60 * 2);
	//EnemySpawner::GetInstance()->SpawnEnemy(Vector2(1200, 0), EnemyName::Eagle, 60 * 2);
}
