#pragma once
class MenuScene : public Scene
{
private:

public:
	CREATE_FUNC(MenuScene);

	MenuScene();
	~MenuScene();

	bool Init();
	void Update(float deltaTime);
	void Render();
};

