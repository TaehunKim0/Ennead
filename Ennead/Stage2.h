#pragma once
class Stage2 : public Scene
{
public:
	Stage2();
	~Stage2();

	CREATE_FUNC(Stage2);

	bool Init();

	void Update(float deltaTime);
	void Render();

};

