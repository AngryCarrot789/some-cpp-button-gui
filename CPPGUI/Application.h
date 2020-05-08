#pragma once
#include <Windows.h>
class Application
{
public:
	HINSTANCE hInstance;

	LPCWSTR ApplicationName;

	Application(HINSTANCE);
	Application(HINSTANCE, LPCWSTR appName);
};
