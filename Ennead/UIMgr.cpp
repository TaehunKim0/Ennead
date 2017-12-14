#include "PrevHeader.h"
#include "UIMgr.h"


UIMgr::UIMgr()
{
}


UIMgr::~UIMgr()
{
}

void UIMgr::Update(float deltaTime)
{
	//UI Update
}

void UIMgr::Render()
{
	//UI Render
}

void UIMgr::AddUI(UI * ui)
{
	m_UIList.push_back(ui);

}
