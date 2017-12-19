#pragma once
class MenuScene : public Scene
{
private:
	Sprite* m_Background;
	Sprite* m_GameStart;
	Sprite* m_Exit;
	Sprite* m_Setting;
	Sprite* m_Loading;

public:
	CREATE_FUNC(MenuScene);

	MenuScene();
	~MenuScene();

	void Release();
	bool Init();
	void Update(float deltaTime);
	void Render();
};

