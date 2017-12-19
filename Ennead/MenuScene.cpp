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
}

bool MenuScene::Init()
{
	m_Background = Sprite::Create(L"Resources/Menu/Background.png");
	m_GameStart = Sprite::Create(L"Resources/Menu/GameStart.png");
	m_Setting = Sprite::Create(L"Resources/Menu/Setting.png");
	m_Exit = Sprite::Create(L"Resources/Menu/Exit.png");
	m_Loading = Sprite::Create(L"Resources/Menu/Loading.png");
	m_Loading->SetVisible(0);

	m_GameStart->SetPosition(700, 470);
	m_Setting->SetPosition(700, 670);
	m_Exit->SetPosition(700, 870);

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

	if (Input::GetInstance()->GetKeyState(VK_RBUTTON) == KeyState::Down)
	{
		m_Loading->SetVisible(1);
	}

	if (Input::GetInstance()->GetKeyState(VK_LBUTTON) == KeyState::Down)
	{
		Director::GetInstance()->SetScene(Stage1::Create());
	}

}

void MenuScene::Render()
{
	Scene::Render();
}
