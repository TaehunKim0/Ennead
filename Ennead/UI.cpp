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
		//�� Vector �� ���콺 ����Ʈ�� �浹 �Ǿ����� ��
		return true;
	}

}

