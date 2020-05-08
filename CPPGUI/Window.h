#pragma once
#include <Windows.h>
#include "Application.h"
class Window
{
public:
	HWND Handle;
	HINSTANCE hInstance;
	int Width = 1280;
	int Height = 720;
	int X = 100;
	int Y = 100;
	LPCWSTR Title;
	//Initialise a new window
	Window(Application* app, LPCWSTR title = L"Window Here", int x = 100, int y = 100, int nWidth = 1280, int nHeight = 720);
	//Show the window
	void Show(int nCmdShow);
	//Show the window
	void Show();
	//Called when the window is painted
	void OnPaint(HDC hdc) {}
	virtual LRESULT CALLBACK CustomWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
private:
	Application* RelativeApp{};
	Window(Application app);
	void Initialise();
	void CreateWindowInstance();
	WNDCLASS wndClass;
	static LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
	{
		Window* me = reinterpret_cast<Window*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
		if (me) return me->CustomWndProc(hWnd, message, wParam, lParam);
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
};