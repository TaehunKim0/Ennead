#pragma once
class MenuScene : public Scene
{
private:

public:
	CREATE_FUNC(MenuScene);

	MenuScene();
	~MenuScene();

	void Release();
	bool Init();
	void Update(float deltaTime);
	void Render();
};

