#pragma once
class Stage1 : public Scene
{
private:
	Sprite* Map1;
	Player* player;

public:
	CREATE_FUNC(Stage1);

	Stage1();
	~Stage1();

	void Release();
	bool Init();
	void Update(float deltaTime);
	void Render();
};