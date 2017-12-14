#include "PrevHeader.h"
#include "UI.h"


UI::UI()
{
}


UI::~UI()
{
}

bool UI::Init()
{

	return true;
}

void UI::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void UI::Render()
{
	GameObject::Render();
}

bool UI::OnClick()
{
	
	return true;
}

bool UI::IsCollisionWithPoint()
{
	if (Input::GetInstance()->GetMouseState(VK_LBUTTON) == KeyState::Up)
	{
		//내 Vector 와 마우스 포인트가 충돌 되었는지 비교
		return true;
	}

}

