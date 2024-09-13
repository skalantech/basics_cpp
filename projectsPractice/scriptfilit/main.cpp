#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <iostream>

void Input_key(const WORD& key, int ms);
void Press_key(INPUT& ip, const WORD& key, int ms);
void Release_key(INPUT& ip);
void minimize_all();
void exec_run();
void notepad();
void message();
void close_focus_nosave();
bool end_program();

int main()
{
    std::cout << "Welcome to the work from home program!" << '\n';
    for (int i = 5; i != 0; --i)
    {
        Sleep(750);
        std::cout << i << '\n';
        Sleep(500);
        if (i == 1)
        {
            std::cout << "LET'S WORK!";
            Sleep(80);
            std::cout << ".";
            Sleep(110);
            std::cout << ".";
            Sleep(150);
            std::cout << ".";
        }
    }
    minimize_all();
    Sleep(1000);
    exec_run();
    Sleep(1000);
    notepad();
    Sleep(2000);
    message();
    close_focus_nosave();
    std::cout << "GOOD BYE!!" << '\n';
}

void Press_key(INPUT& ip, const WORD& key, int ms)
{
    Sleep(ms);
    ip.type = INPUT_KEYBOARD;
    ip.ki.wScan = 0; // hardware scan code for key
    ip.ki.time = 0;
    ip.ki.dwExtraInfo = 0;

    // Press the key
    ip.ki.wVk = key; // virtual-key code for the key
    ip.ki.dwFlags = 0; // 0 for key press
    SendInput(1, &ip, sizeof(INPUT));
}

void Release_key(INPUT& ip)
{
    // Release the key
    ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
    SendInput(1, &ip, sizeof(INPUT));
}

void Input_key(const WORD& key, int ms)
{
    INPUT ip;
    Press_key(ip, key, ms);
    Release_key(ip);
}
// ATL+D
void minimize_all()
{
    INPUT ip1;
    INPUT ip2;
    Press_key(ip1, 0x5B, 1000);
    Press_key(ip2, 0x44, 100);
    Release_key(ip1);
    Release_key(ip2);
}
// ALT+R
void exec_run()
{
    INPUT ip1;
    INPUT ip2;
    Press_key(ip1, 0x5B, 1000);
    Press_key(ip2, 0x52, 100);
    Release_key(ip1);
    Release_key(ip2);
}
// writes "notepad"
void notepad()
{
    Input_key(0x4E, 100);
    Input_key(0x4F, 100);
    Input_key(0x54, 100);
    Input_key(0x45, 100);
    Input_key(0x50, 100);
    Input_key(0x41, 100);
    Input_key(0x44, 100);
    Input_key(0x0D, 100);
}
// Prints message in notepad and wait for end_program()
void message()
{
    srand(std::time(nullptr));   
    while(!end_program())
    {
        INPUT ip1;
        int t = rand() % 100 + 50;  
        Press_key(ip1, 0x10, t); // VK_SHIFT
        Input_key(0x50, t);    // p
        Release_key(ip1);
        Input_key(0x52, t);    // r
        Input_key(0x45, t);    // e
        Input_key(0x53, t);    // s
        Input_key(0x53, t);    // s
        if (end_program()) break;
        Input_key(0x20, t);    // VK_SPACE
        Input_key(0x45, t);    // e
        Input_key(0x53, t);    // s
        Input_key(0x43, t);    // c
        Input_key(0x41, t);    // a
        Input_key(0x50, t);    // p
        Input_key(0x45, t);    // e
        if (end_program()) break;
        Input_key(0x20, t);    // VK_SPACE
        Input_key(0x4F, t);    // o
        Input_key(0x4E, t);    // n
        Input_key(0x43, t);    // c
        Input_key(0x45, t);    // e
        if (end_program()) break;
        Input_key(0x20, t);    // VK_SPACE
        Input_key(0x54, t);    // t
        Input_key(0x4F, t);    // o
        if (end_program()) break;
        Input_key(0x20, t);    // VK_SPACE
        Input_key(0x53, t);    // s
        Input_key(0x54, t);    // t
        Input_key(0x4F, t);    // o
        Input_key(0x50, t);    // p
        if (end_program()) break;
        Input_key(0x20, t);    // VK_SPACE
        Input_key(0x4D, t);    // m
        Input_key(0x45, t);    // e
        Input_key(0x20, t);    // VK_SPACE
        Input_key(0x20, t);    // VK_SPACE
    }
}
// ALT+F4, then RIGHT_ARROW_key (VK_RIGHT)
void close_focus_nosave()
{
    INPUT ip1;
    INPUT ip2;
    Press_key(ip1, 0x12, 1000);
    Press_key(ip2, 0x73, 100);
    Release_key(ip1);
    Release_key(ip2);
    Input_key(0x27, 500);
    Input_key(0x0D, 500);    
}
// Wait for VK_ESCAPE to be pressed and returns a boolean
bool end_program()
{
    if (GetAsyncKeyState(VK_ESCAPE)) // GetAsyncKeyState(VK:Virtual key) Asynchronous function in winuser.h
    {
        INPUT ip1;
        int t = 10;
        Press_key(ip1, 0x10, t);
        Input_key(0x54, t);    // t
        Input_key(0x48, t);    // h
        Input_key(0x41, t);    // a
        Input_key(0x4E, t);    // n
        Input_key(0x4B, t);    // k
        Input_key(0x20, t);    // SPACE
        Input_key(0x59, t);    // y
        Input_key(0x4F, t);    // o
        Input_key(0x55, t);    // u
        Input_key(0x20, t);    // SPACE
        Input_key(0x47, t);    // g
        Input_key(0x4F, t);    // o
        Input_key(0x4F, t);    // o
        Input_key(0x44, t);    // d
        Input_key(0x20, t);    // SPACE
        Input_key(0x42, t);    // b
        Input_key(0x59, t);    // y
        Input_key(0x45, t);    // e
        Release_key(ip1);
        return true;
    }
    return false;
}
