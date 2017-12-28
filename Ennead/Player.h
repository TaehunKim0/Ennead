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

	float GetAngle(Vector2 p1, Vector2 p2)
	{
		float xdf = p2.x - p1.x;
		float ydf = p2.y - p1.y;

		float ang = D3DXToRadian((atan2(ydf, xdf)));

		//printf("angle = %f\n", ang2);

		return ang;
	}

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

public:
	int GetHp()
	{
		return m_Health;
	}

};

