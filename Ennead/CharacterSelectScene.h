#pragma once
class CharacterSelectScene : public Scene
{
private:

public:
	CREATE_FUNC(CharacterSelectScene);

	CharacterSelectScene();
	~CharacterSelectScene();

	void Release();
	bool Init();
	void Update(float deltaTime);
	void Render();

};

