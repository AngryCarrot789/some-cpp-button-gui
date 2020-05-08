#pragma once
#include <Windows.h>
class FrameworkElement
{
public:
	HWND Handle;
	HWND ParentWindow;
	int Width, Height, X, Y;

	FrameworkElement(
		int nWidth = 80,
		int nHeight = 24,
		int x = 10,
		int y = 10)
	{
		Width = nWidth;
		Height = nHeight;
		X = x;
		Y = y;
	}
};

