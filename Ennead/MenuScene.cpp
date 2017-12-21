#include"PrevHeader.h"
#include "MenuScene.h"
#include"Stage1.h"

MenuScene::MenuScene()
{
}

MenuScene::~MenuScene()
{
}

void MenuScene::Release()
{
	GameObject::Release();
}

bool MenuScene::Init()
{
	this->m_Position.x -= 13;
	this->m_Position.y -= 5;
	m_Background = Sprite::Create(L"Resources/Menu/Background.png");
	m_GameStart = Sprite::Create(L"Resources/Menu/GameStart.png");
	m_Setting = Sprite::Create(L"Resources/Menu/Setting.png");
	m_Exit = Sprite::Create(L"Resources/Menu/Exit.png");
	m_Loading = Sprite::Create(L"Resources/Menu/Loading.png");
	m_Loading->SetVisible(0);

	m_GameStart->SetPosition(730, 470);
	m_Setting->SetPosition(730, 670);
	m_Exit->SetPosition(730, 870);

	AddChild(m_Background);
	AddChild(m_GameStart);
	AddChild(m_Setting);
	AddChild(m_Exit);
	AddChild(m_Loading);

	return true;
}

void MenuScene::Update(float deltaTime)
{
	Scene::Update(deltaTime);

	if (CollisionMgr::GetInstance()->IsPointInBox(m_Exit->GetSize(), m_Exit->GetPosition()))
	{
		if (Input::GetInstance()->GetKeyState(VK_LBUTTON) == KeyState::Down)
		{
			exit(0);
		}
	}

	if (CollisionMgr::GetInstance()->IsPointInBox(m_GameStart->GetSize(), m_GameStart->GetPosition()))
	{

		if (Input::GetInstance()->GetKeyState(VK_LBUTTON) == KeyState::Down)
		{

			Director::GetInstance()->SetScene(Stage1::Create());
		}
	}




}

void MenuScene::Render()
{
	Scene::Render();
}
