#pragma once
enum class PlayerClass
{
	Warrior = 1,
	Thief,
	Archer,
	Magician
};

enum class PlayerState
{
	Idle = 1,
	Move,
	Attack,
};

enum class PlayerLocation
{
	Stair =1
};

class Player : public GameObject
{
private:
	static Player* m_Instance;

public:
	Vector2 OtherPos;
	Vector2 OtherSize;

	bool a;
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
	bool canMoveRight;
	bool canMoveLeft;

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
	Direction m_Direction;
	PlayerState m_State;
	PlayerLocation m_Location;

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

