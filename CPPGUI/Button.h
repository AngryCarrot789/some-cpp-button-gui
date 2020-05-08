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
		int y = 10);
	Button(HWND,
		Event* clickCallback,
		LPCWSTR buttonText = L"Content",
		int nWidth = 80,
		int nHeight = 24,
		int x = 10,
		int y = 10);
	~Button()
	{
		delete OnClick;
		delete this->Handle;
		delete this->Text;
	}

	virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

	Event* OnClick;
};