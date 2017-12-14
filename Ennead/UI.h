#pragma once
class UI : public GameObject
{
public:
	UI();
	~UI();

	//UI는 항상 무엇을 가지고 있을까?
public:
	bool Init();
	void Update(float deltaTime);
	void Render();

public:
	bool OnClick();
	bool IsCollisionWithPoint();
};