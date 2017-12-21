#include "PrevHeader.h"
#include "UIMgr.h"


UIMgr::UIMgr()
{
	Hp = Sprite::Create(L"Resources/UI/Hp.png");
	AddChild(Hp);
}

UIMgr::~UIMgr()
{
}

void UIMgr::Update(float deltaTime)
{
	//UI Update
	for (int i = 0; i < m_UIList.size(); i++)
	{
		m_UIList[i]->Update(deltaTime);
	}

}

void UIMgr::Render()
{
	//UI Render
	for (int i = 0; i < m_UIList.size(); i++)
	{
		m_UIList[i]->Render();
	}
}

void UIMgr::AddUI(UI * ui)
{
	m_UIList.push_back(ui);

}
