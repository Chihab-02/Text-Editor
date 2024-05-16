#pragma once
#include <Windows.h>
#include <WinUser.h>
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

class TheWindow
{
public:
    TheWindow();
    TheWindow(const TheWindow&) = delete;
    TheWindow& operator =(const TheWindow&) = delete;
    ~TheWindow();

    bool ProcessMessage();
private:
    HINSTANCE h_Instance;
    HWND h_wnd;
    HWND h_Edit;

};

