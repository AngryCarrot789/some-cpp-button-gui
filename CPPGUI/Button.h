#pragma once
#include "FrameworkElement.h"
#include "Event.h"

class Button : public FrameworkElement
{
public:
	LPCWSTR Text;
	Button(HWND,
		LPCWSTR buttonText = L"Content",
		int nWidth = 80,
		int nHeight = 24,
		int x = 10,
		int y = 10,
		int controlID = 2);
	Button(HWND,
		Event* clickCallback,
		LPCWSTR buttonText = L"Content",
		int nWidth = 80,
		int nHeight = 24,
		int x = 10,
		int y = 10,
		int controlID = 2);
	~Button()
	{
		if (OnClick == nullptr) return;
		if (OnClick == (Event*)0x3) return;
		if (OnClick->Parameters == nullptr) return;
		delete OnClick->Parameters;
		delete OnClick;
	}

	void HandleMessage(WPARAM wParam, LPARAM lParam);

	Event* OnClick;
};