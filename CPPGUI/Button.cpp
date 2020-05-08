#include "Button.h"
#include "Resource.h"
Button::Button(HWND window, LPCWSTR buttonText, int nWidth, int nHeight, int x, int y)
{
    Text = buttonText;
    Width = nWidth;
    Height = nHeight;
    X = x;
    Y = y;
    ParentWindow = window;
    Handle = CreateWindow(
        L"BUTTON",    // Predefined class; Unicode assumed 
        buttonText,   // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        X,               // x position 
        Y,               // y position 
        Width,           // Button width
        Height,          // Button height
        window,          // Parent window
        (HMENU)69420,
        (HINSTANCE)GetWindowLongPtr(window, GWLP_HINSTANCE),
        (void*)69420);
}

Button::Button(HWND window, Event* clickCallback, LPCWSTR buttonText, int nWidth, int nHeight, int x, int y)
{
    Text = buttonText;
    Width = nWidth;
    Height = nHeight;
    X = x;
    Y = y;
    ParentWindow = window;

    Handle = CreateWindowW(
        L"BUTTON",    // Predefined class; Unicode assumed 
        buttonText,   // Button text 
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,  // Styles 
        X,               // x position 
        Y,               // y position 
        Width,           // Button width
        Height,          // Button height
        ParentWindow,    // Parent window
        (HMENU)69420,
        (HINSTANCE)GetWindowLongPtr(ParentWindow, GWLP_HINSTANCE),
        (void*)69420);
    delete OnClick;
    OnClick = clickCallback;
}

LRESULT Button::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    return DefWindowProc(Handle, uMsg, wParam, lParam);
}
