#pragma once


class EnemySpawner : public Singleton<EnemySpawner>, public GameObject
{
public:
	EnemySpawner();
	~EnemySpawner();

	void Release();
	void Update(float deltaTime);
	void Render();

	void SpawnEnemy(Vector2 pos, EnemyName name);
	void RandomSpawnEnemy(int y);

};

