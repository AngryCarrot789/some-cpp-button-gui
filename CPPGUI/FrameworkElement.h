#pragma once
#include <Windows.h>
class FrameworkElement
{
public:
	HWND Handle;
	HWND ParentWindow;
	int Width, Height, X, Y;
	//The id of a control, used for events. Default is 1, not 0.
	int ControlID = 2;

	FrameworkElement(
		int nWidth = 80,
		int nHeight = 24,
		int x = 10,
		int y = 10) : 
		Handle(NULL), 
		ParentWindow(NULL)
	{
		Width = nWidth;
		Height = nHeight;
		X = x;
		Y = y;
	}

	virtual void HandleMessage(WPARAM wParam, LPARAM lParam) {}

	~FrameworkElement()
	{
		//delete Handle;
		//delete ParentWindow;
	}
};

