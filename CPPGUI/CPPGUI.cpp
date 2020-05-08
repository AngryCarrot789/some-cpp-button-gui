// CPPGUI.cpp : Defines the entry point for the application.
//
#define _CRT_SECURE_NO_WARNINGS
#include "framework.h"
#include "CPPGUI.h"
#include "Button.h"
#include "Event.h"
#include "Application.h"
#include "someWindow.h"
// Global Variables:
someWindow* mainWindow = nullptr;
Application* app = nullptr;

// Forward declarations of functions included in this code module:
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);
void owo();

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR    lpCmdLine,
    _In_ int       nCmdShow)
{
#ifdef _DEBUG
    AllocConsole();
    //SetWindowPos(GetConsoleWindow(), 0, 1920, 200, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
    AttachConsole(GetCurrentProcessId());
    freopen("CON", "w", stdout);
#endif

    MSG msg;

    app = new Application(hInstance, L"MyProgramThingy");
    mainWindow = new someWindow(app, L"oWo lOl");
    mainWindow->Show();
    Event* evn = new Event(owo);

    Button button(mainWindow->Handle, evn);

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    delete mainWindow;
    delete app;

    return (int)msg.wParam;
}

void owo()
{
    MessageBoxW(mainWindow->Handle, L"button clicked", L"owow", MB_OK);
}