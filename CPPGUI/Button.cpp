#include "Button.h"
#include "Resource.h"
Button::Button(HWND window, 
    LPCWSTR buttonText,
    int nWidth, int nHeight, 
    int x, int y,
    int controlID)
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
        ParentWindow,    // Parent window
        (HMENU)controlID,
        (HINSTANCE)GetWindowLongPtr(ParentWindow, GWLP_HINSTANCE),
        NULL);
    LONG_PTR owo = (LONG_PTR)this;
    SetWindowLongPtrW(Handle, GWLP_USERDATA, owo);
}

Button::Button(HWND window, 
    Event* clickCallback,
    LPCWSTR buttonText, 
    int nWidth, int nHeight, 
    int x, int y, 
    int controlID)
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
        (HMENU)controlID,
        (HINSTANCE)GetWindowLongPtr(ParentWindow, GWLP_HINSTANCE),
        NULL);
    LONG_PTR owo = (LONG_PTR)this;
    SetWindowLongPtrW(Handle, GWLP_USERDATA, owo);
    //delete OnClick;
    OnClick = clickCallback;
}

void Button::HandleMessage(WPARAM wParam, LPARAM lParam)
{
    if (LOWORD(wParam) == ControlID) {
        if (OnClick != nullptr) {
            //OnClick->Parameters = (void*)this;
            OnClick->Call();
        }
    }
}
