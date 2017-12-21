#include "PrevHeader.h"
#include "UI.h"


UI::UI()
	:draw(0)
{
}


UI::~UI()
{
}

bool UI::Init()
{
	//Font
	


	return true;
}

void UI::Update(float deltaTime)
{
	GameObject::Update(deltaTime);
}

void UI::Render()
{
	GameObject::Render();

	if (draw)
	{
		RECT rect;
		SetRectEmpty(&rect);

		m_Font->DrawTextW(NULL, m_Text.c_str(), m_Text.size(), &rect, DT_CALCRECT, D3DCOLOR_XRGB(0, 0, 0));
	}
	

}

void UI::_CreateFont(int width, int height, std::wstring& fontface)
{
	HRESULT hr = D3DXCreateFont(
		Renderer::GetInstance()->m_Device
		, height
		, width
		, FW_NORMAL
		, D3DX_DEFAULT
		, false
		, DEFAULT_CHARSET
		, OUT_TT_ONLY_PRECIS
		, ANTIALIASED_QUALITY
		, NULL
		, fontface.c_str()
		, &m_Font);

	if FAILED(hr)
		return;

	m_FontFace = fontface;

}

bool UI::OnClick()
{
	
	return true;
}

bool UI::IsCollisionWithPoint()
{
	//UI¿Í mouse Collision
	return false;
}

