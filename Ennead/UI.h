#pragma once
class UI : public GameObject
{
public:
	UI();
	~UI();

	//UI�� �׻� ������ ������ ������?
public:
	bool Init();
	void Update(float deltaTime);
	void Render();

public:
	bool OnClick();
	bool IsCollisionWithPoint();
};