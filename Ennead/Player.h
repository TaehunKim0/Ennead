#pragma once
enum class PlayerClass
{
	Warrior = 1,
	Assassin,
	Archer,
	Magician
};

enum class PlayerDirection
{
	Up = 1,
	Down,
	Left,
	Right
};

class Player : public GameObject
{
private:
	int Health;
	int Speed;

	Sprite* player;

	Animation* Straight;
	Animation* Left;
	Animation* Right;

public:
	Player();
	~Player();

	PlayerClass Job;
	PlayerDirection pDirection;

	void SetAnimWithClass(PlayerClass job);

	bool Init();
	void Update(float deltaTime);
	void Render();

};

