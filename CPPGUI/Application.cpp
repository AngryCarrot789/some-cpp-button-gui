#include "Application.h"

Application::Application(HINSTANCE hInst)
{
	hInstance = hInst;
}

Application::Application(HINSTANCE hInst, LPCWSTR appName)
{
	hInstance = hInst;
	ApplicationName = appName;
}
