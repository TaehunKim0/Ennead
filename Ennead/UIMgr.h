#pragma once
class UIMgr : public Singleton<UIMgr>
{
private:
	std::vector<UI*> m_UIList;

public:
	UIMgr();
	~UIMgr();

	void Update(float deltaTime);
	void Render();

	void AddUI(UI* ui);

};

