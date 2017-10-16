#include "PrevHeader.h"
#include "EnemySpawner.h"
#include"E_Mummy.h"

EnemySpawner::EnemySpawner()
{
}


EnemySpawner::~EnemySpawner()
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

void EnemySpawner::SpawnEnemy(Vector2 pos, EnemyName name)
{
	if(name == EnemyName::Mummy)
		AddChild(E_Mummy::Create(pos));

}

void EnemySpawner::RandomSpawnEnemy(int y)
{
	//SpawnEnemy
}
