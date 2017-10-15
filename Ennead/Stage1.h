#pragma once
class Stage1 : public Scene
{
private:
	Player* player;

public:
	CREATE_FUNC(Stage1);

	Stage1();
	~Stage1();

	bool Init();
	void Update(float deltaTime);
	void Render();
};

