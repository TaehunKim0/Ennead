#pragma once
class E_Spinks : public Enemy
{
public:
	E_Spinks();
	~E_Spinks();

	static E_Spinks* Create(Vector2 pos);

	void Update(float deltaTime);
	void Render();

	bool Init(Vector2 pos);


};