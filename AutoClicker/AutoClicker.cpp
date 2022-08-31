#include <iostream>
#include <Windows.h>
#include <string>
#include "AutoClicker.h"

using namespace std;

const int wait_time = 5;

bool _autoClickEnabled = false;
bool _running = true;

void TurnOnAutoClicker()
{
    _running = true;
        
    cout << "AUTO CLICKER\n\n";
    cout << "Press '0' Number Pad key to pause Autoclicker.\n";
    cout << "Press '1' Number Pad key to start or resume Autoclicker.\n\n";
        
    cout << "Press 'Esc' key to close Autoclicker.\n\n";
        
    PrintAutoClickerStatus();

    while (_running)
    {
        if (GetAsyncKeyState(VK_NUMPAD0))
            ToggleAutoClicker(false);

        if (GetAsyncKeyState(VK_NUMPAD1))
            ToggleAutoClicker(true);

        if (GetAsyncKeyState(VK_ESCAPE))
            TurnOffAutoClicker();

        if (_autoClickEnabled)
        {
            mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
            mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
            Sleep(wait_time);
        }
    }

    cout << "Auto Clicker Closed";
}

void TurnOffAutoClicker()
{
    _running = false;
}

void ToggleAutoClicker(bool enable)
{
    if (_autoClickEnabled == enable)
        return;

    _autoClickEnabled = enable;
    PrintAutoClickerStatus();
}

void PrintAutoClickerStatus()
{
    if (_autoClickEnabled)
        cout << "Auto Clicking is Enabled\n";
    else
        cout << "Auto Clicking is Disabled\n";
}

int main()
{
TurnOnAutoClicker();
return 0;
}