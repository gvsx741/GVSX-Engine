#include <core/app.h>

cMemoryManager MemoryManager;

void main()
{
	cApp* app = new cApp();

	app->Run();

	delete app;
}