#include"PrevHeader.h"
#include"Stage1.h"

INT WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, INT)
{
#if _DEBUG
	AllocConsole();
	FILE* stream;
	freopen_s(&stream, "CONOUT$", "wt", stdout);

#endif
	Application* app = Application::GetInstance();

	app->Init(L"Ennead", 1980, 900, false);
	Director::GetInstance()->SetScene(Stage1::Create());
	
	app->GameLoop();

	app->Release();

#if _DEBUG
	FreeConsole();
#endif
}