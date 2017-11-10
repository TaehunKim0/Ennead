#pragma once
enum class PlayerClass
{
	Warrior = 1,
	Thief,
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

enum class PlayerState
{
	Idle = 1,
	Move,
	Attack,
};

class Player : public GameObject
{
private:
	static Player* m_Instance;

public:
	static Player* GetInstance();
	static void ReleaseInstance();

private:
	int m_Health;
	int m_Speed;
	bool checkInput;

	Sprite* pplayer;

	Animation* Straight;
	Animation* Left;
	Animation* Right;

	int latingTime;
	bool CanAttack;

public:
	//BoxCollider* m_Collision;

	Player();
	~Player();

	PlayerClass Job;
	PlayerDirection pDirection;
	PlayerState pState;

	void SetAnimWithClass(PlayerClass job);

	

	bool Init();
	void Update(float deltaTime);
	void Render();
	void Release();

	void OnCollision(GameObject* other);

public:
	void Move(); //이동
	void Attack(); //총알 발사

};

