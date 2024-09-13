#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

void Input_key(const WORD& key, int ms);

int main()
{
    std::srand(std::time(nullptr));   /* initialize random seed: */
    Sleep(10000);
    for (int i = 1; i < 10800; i++)
    {
        int t = std::rand() % 150 + 50;
        std::cout << "Wake up Fili " << i << " " << "t = " << t << '\n';
        Input_key(0x54, t);    // t
        Input_key(0x48, t);    // h
        Input_key(0x45, t);    // e
        Input_key(0x20, t);    // SPACE
        Input_key(0x4D, t);    // m
        Input_key(0x41, t);    // a
        Input_key(0x54, t);    // t
        Input_key(0x52, t);    // r
        Input_key(0x49, t);    // i
        Input_key(0x58, t);    // x
        Input_key(0x20, t);    // SPACE
        Input_key(0x48, t);    // h
        Input_key(0x41, t);    // a
        Input_key(0x53, t);    // s
        Input_key(0x20, t);    // SPACE
        Input_key(0x59, t);    // y
        Input_key(0x4F, t);    // o
        Input_key(0x55, t);    // u
        Input_key(0x20, t);    // SPACE
        Input_key(0x46, t);    // f
        Input_key(0x49, t);    // i
        Input_key(0x4C, t);    // l
        Input_key(0x49, t);    // i
        Input_key(0x0D, t);    // ENTER        
    }
	return 0;
}

void Input_key(const WORD& key, int ms)
{
    INPUT ip;
    Sleep(ms);

    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the key
    ip.ki.wVk = key; // virtual-key code for the key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));

    // Release the key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
}