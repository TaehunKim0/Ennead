#pragma once
class E_Spinks : public Enemy
{
public:
	E_Spinks();
	~E_Spinks();

	void Update(float deltaTime);
	void Render();

	bool Init();

};

