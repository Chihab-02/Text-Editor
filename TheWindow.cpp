#include "TheWindow.h"

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
			// Handle menu and toolbar commands
		}
		break;

	case WM_CHAR:
		// Handle character input (typing)
		// wParam contains the character code
		SendMessage(hwnd, uMsg, wParam, lParam);
		break;


	case WM_KEYDOWN:
		// Handle keyboard input (e.g., arrow keys, backspace)
		// wParam contains the virtual-key code
		SendMessage(hwnd, uMsg, wParam, lParam);
		break;

	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}

TheWindow::TheWindow()
	:h_Instance(GetModuleHandle(nullptr))
{
	//class definition
	const wchar_t* CLASS_NAME = L"THE WINDOW IS HERE";
	WNDCLASS wnd_class = {};
	wnd_class.lpszClassName = CLASS_NAME;
	wnd_class.hInstance = h_Instance;
	wnd_class.hCursor = LoadCursor(NULL, IDC_ARROW);
	wnd_class.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wnd_class.lpfnWndProc = WindowProc;


	//register the window class
	RegisterClass(&wnd_class);
    //dimensionnig~~~~styling 
	DWORD styleWindow = WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU;
	int width = 550;
	int height = 400;

	RECT rect;
	rect.left = 250;
	rect.right = rect.left + width;
	rect.top = 250;
	rect.bottom = rect.top + height;
	AdjustWindowRect(&rect, styleWindow, false);

	//window creation
	h_wnd = CreateWindowEx(
		0,
		CLASS_NAME,
		L"HELLO_WORLD",
		styleWindow,
		rect.left,
		rect.top,
		rect.right - rect.left,
		rect.bottom - rect.top,
		NULL,
		NULL,
		h_Instance,
		NULL
	);
	ShowWindow(h_wnd, SW_SHOW);
	//creating edit control 
	// Inside TheWindow::TheWindow() constructor
	h_Edit = CreateWindowEx(
		0,
		L"EDIT",
		L"",
		WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_MULTILINE | ES_AUTOVSCROLL | ES_AUTOHSCROLL,
		0, // X position
		0, // Y position
		rect.right - rect.left, // Width
		rect.bottom - rect.top, // Height
		h_wnd,
		NULL,
		h_Instance,
		NULL
	);

}

TheWindow::~TheWindow()
{
	const wchar_t* CLASS_NAME = L"THE WINDOW IS HERE";
	UnregisterClass(CLASS_NAME, h_Instance);

}

bool TheWindow::ProcessMessage()
{
	MSG msg = {};
	/*BOOL PeekMessageA(
		[out]          LPMSG lpMsg,
		[in, optional] HWND  hWnd,
		[in]           UINT  wMsgFilterMin,
		[in]           UINT  wMsgFilterMax,
		[in]           UINT  wRemoveMsg
	);*/
	while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
	{
		if (msg.message == WM_QUIT) {
			return false;
		}			
	    TranslateMessage(&msg);
		DispatchMessage(&msg);

	}
	return true;



}
