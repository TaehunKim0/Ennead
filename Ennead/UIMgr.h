#pragma once
class UIMgr : public Singleton<UIMgr> , public GameObject
{
private:
	std::vector<UI*> m_UIList;

	Sprite* Hp;
	int Score;

	LPD3DXFONT m_Font;
	std::wstring m_FontFace;
	std::wstring m_Text;

	bool draw;

public:
	UIMgr();
	~UIMgr();


	void Update(float deltaTime);
	void Render();

	void AddUI(UI* ui);

};

