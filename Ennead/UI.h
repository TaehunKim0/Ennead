#pragma once
class UI : public GameObject
{
public:
	UI();
	~UI();

	LPD3DXFONT m_Font;
	std::wstring m_FontFace;
	std::wstring m_Text;

	bool draw;

	//UI�� �׻� ������ ������ ������?

public:
	bool Init();
	void Update(float deltaTime);
	void Render();

	void _CreateFont(int width, int height, std::wstring& fontface);

public:
	bool OnClick();
	bool IsCollisionWithPoint();

	void Draw()
	{
		draw = 1;
	}

};