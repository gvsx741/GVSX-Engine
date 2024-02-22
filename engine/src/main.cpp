#include <core/app.h>

void main()
{
	//cMemoryManager::Init();

	cApp* app = new cApp();

	app->Run();

	delete app;

	cMemoryManager::Release();
}