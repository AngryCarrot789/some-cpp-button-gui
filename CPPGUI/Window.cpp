#include "Window.h"

Window::Window(Application* app, LPCWSTR title, int x, int y, int nWidth, int nHeight)
{
    X = x;
    Y = y;
    Width = nWidth;
    Height = nHeight;

    this->RelativeApp = app;
    this->Title = title;
    this->Initialise();
    this->CreateWindowInstance();
    SetWindowLongPtr(this->Handle, GWLP_USERDATA, (long)this);
}

void Window::Initialise()
{
    wndClass.style = CS_HREDRAW | CS_VREDRAW;
    wndClass.lpfnWndProc = WndProc;
    wndClass.cbClsExtra = 0;
    wndClass.cbWndExtra = 0;
    wndClass.hInstance = RelativeApp->hInstance;
    wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
    wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wndClass.lpszMenuName = NULL;
    wndClass.lpszClassName = RelativeApp->ApplicationName;

    RegisterClass(&wndClass);
}

void Window::CreateWindowInstance()
{
    this->Handle =
        CreateWindowW(
            RelativeApp->ApplicationName,   // window class name
            Title,                          // window caption
            WS_OVERLAPPEDWINDOW,            // window style
            X,                              // initial x position
            Y,                              // initial y position
            Width,                          // initial x size
            Height,                         // initial y size
            NULL,                           // parent window handle
            NULL,                           // window menu handle
            RelativeApp->hInstance,         // program instance handle
            NULL);                          // creation parameters
}

void Window::Show(int nCmdShow)
{
    ShowWindow(Handle, nCmdShow);
    UpdateWindow(Handle);
}
void Window::Show()
{
    ShowWindow(Handle, 1);
    UpdateWindow(Handle);
}

LRESULT CALLBACK Window::CustomWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    HDC          hdc;
    PAINTSTRUCT  ps;
    switch (message) {
    case WM_PAINT:
        hdc = BeginPaint(hWnd, &ps);
        OnPaint(hdc);
        EndPaint(hWnd, &ps);
        return 0;
    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
}