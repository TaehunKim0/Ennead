#pragma once
class TestMap : public Scene
{
private:
	Sprite* block;
	Sprite* character;


public:

	CREATE_FUNC(TestMap);

	TestMap();
	~TestMap();

	bool Init();
	void Update(float deltaTime);
	void Render();

	int PixelPerfectCollision(Sprite* sp1, Sprite* sp2);
};

