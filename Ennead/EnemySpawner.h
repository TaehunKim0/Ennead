#pragma once


class EnemySpawner : public Singleton<EnemySpawner>, public GameObject
{
private:
	int Frame;
	bool WaitEnd;
	int waitTime;
	EnemyName name;
	Vector2 pos;

public:
	EnemySpawner();
	~EnemySpawner();

	void Release();
	void Update(float deltaTime);
	void Render();

	void SpawnEnemy(Vector2 pos, EnemyName name, int waitTime);
	void RandomSpawnEnemy(int y);

};

