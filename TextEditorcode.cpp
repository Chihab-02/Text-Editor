#include <iostream>
#include "TheWindow.h"


int main()
{
    std::cout << "window creation\n";
    TheWindow* pWindow = new TheWindow();
    bool r = true;
    while (r) {
        if (!pWindow->ProcessMessage()) {
            std::cout << "Quitting";
            r = false;
        }
    
        Sleep(10);
    }
    delete pWindow;

    return 0;
}

