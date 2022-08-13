#include <windows.h>

int main()
{
    INPUT input[1];
    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = VK_NUMLOCK;
    input[0].ki.wScan = MapVirtualKey(input[0].ki.wVk, 0);
    input[0].ki.time = 0;
    input[0].ki.dwExtraInfo = GetMessageExtraInfo();

    input[0].ki.dwFlags = KEYEVENTF_EXTENDEDKEY;
    SendInput(1, input, sizeof(INPUT));

    input[0].ki.dwFlags = KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP;
    SendInput(1, input, sizeof(INPUT));

    return 0;
}
