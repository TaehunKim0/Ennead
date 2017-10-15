#include"PCH.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
#if _DEBUG
	AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "wt", stdout);
#endif
	Application* app = Application::GetInstance();
	app->Init(L"Ennead", 1440, 900, false);

	app->GameLoop();

	app->Release();

#if _DEBUG
	FreeConsole();
#endif
}