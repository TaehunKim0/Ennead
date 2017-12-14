#include "PrevHeader.h"
#include "EnemySpawner.h"
#include"E_Mummy.h"
#include"E_Eagle.h"
#include"E_Anubis.h"

EnemySpawner::EnemySpawner()
	: Frame(0)
	, WaitEnd(0)
	,waitTime(0)
{
}


EnemySpawner::~EnemySpawner()
{
}

void EnemySpawner::Release()
{
}

void EnemySpawner::Update(float deltaTime)
{
	GameObject::Update(deltaTime);


}

void EnemySpawner::Render()
{
	GameObject::Render();
}

void EnemySpawner::SpawnEnemy(Vector2 pos, EnemyName name, int waitTime)
{
	if (name == EnemyName::Mummy)
		AddChild(E_Mummy::Create(pos));

	if (name == EnemyName::Eagle)
		AddChild(E_Eagle::Create(pos));

	if (name == EnemyName::Anubis)
		AddChild(E_Anubis::Create(pos));
}

void EnemySpawner::RandomSpawnEnemy(int y)
{
	//SpawnEnemy

	//랜덤 y 값으로 소환

}
