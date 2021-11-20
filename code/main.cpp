#include <cstring>
#include <fstream>
#include <windows.h>
#include <conio.h>
#include <thread>

using namespace std;

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) 
#define edition "GHSL2FJDK 2.0"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

int mode = 1;

void KD_H()
{
	int press = 0;
	while (1)
	{
		if (KEY_DOWN('H'))
		{
			if (press == 0 && mode == 0) keybd_event(VK_RIGHT, 0, 0, 0);
			if (press == 0 && mode == 1) keybd_event('J', 0, 0, 0);
			press = 1;
		}
		else
		{
			if (press == 1 && mode == 0) keybd_event(VK_RIGHT, 0, KEYEVENTF_KEYUP, 0);
			if (press == 1 && mode == 1) keybd_event('J', 0, KEYEVENTF_KEYUP, 0);
			press = 0;
		}
		Sleep(1);
	}
}

void KD_G()
{
	int press = 0;
	while (1)
	{
		if (KEY_DOWN('G'))
		{
			if (press == 0 && mode == 0) keybd_event(VK_DOWN, 0, 0, 0);
			if (press == 0 && mode == 1) keybd_event('F', 0, 0, 0);
			press = 1;
		}
		else
		{
			if (press == 1 && mode == 0) keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);
			if (press == 1 && mode == 1) keybd_event('F', 0, KEYEVENTF_KEYUP, 0);
			press = 0;
		}
		Sleep(1);
	}
}

void KD_L()
{
	int press = 0;
	while (1)
	{
		if (KEY_DOWN('L'))
		{
			if (press == 0 && mode == 0) keybd_event(VK_LEFT, 0, 0, 0);
			if (press == 0 && mode == 1) keybd_event('K', 0, 0, 0);
			press = 1;
		}
		else
		{
			if (press == 1 && mode == 0) keybd_event(VK_LEFT, 0, KEYEVENTF_KEYUP, 0);
			if (press == 1 && mode == 1) keybd_event('K', 0, KEYEVENTF_KEYUP, 0);
			press = 0;
		}
		Sleep(1);
	}
}
void KD_S()
{
	int press = 0;
	while (1)
	{
		if (KEY_DOWN('S'))
		{
			if (press == 0 && mode == 0) keybd_event(VK_UP, 0, 0, 0);
			if (press == 0 && mode == 1) keybd_event('D', 0, 0, 0);
			press = 1;
		}
		else
		{
			if (press == 1 && mode == 0) keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);
			if (press == 1 && mode == 1) keybd_event('D', 0, KEYEVENTF_KEYUP, 0);
			press = 0;
		}
		Sleep(1);
	}
}

void ask()
{
	if (MessageBoxA(0, "点击 \"确定\" 来退出本程序", edition, MB_OK) == 1) exit(0);
}

void switch_mode()
{
	while (1)
	{
		if (KEY_DOWN(VK_MENU))
		{
			mode = (mode + 1) % 2;
			Sleep(100);
		}
		Sleep(1);
	}
}

void save()
{
	ofstream out("D:\\Data\\GHSL2FJDK\\Mode.Ceh", ios::binary);
	out << mode;
}

int main()
{
	ifstream in("D:\\Data\\GHSL2FJDK\\Mode.Ceh", ios::binary);
	if (!in)
	{
		CreateDirectory("D:\\Data\\", NULL);
		SetFileAttributes("D:\\Data\\", FILE_ATTRIBUTE_HIDDEN);
		CreateDirectory("D:\\Data\\GHSL2FJDK\\", NULL);
		ofstream out("D:\\Data\\GHSL2FJDK\\Mode.Ceh", ios::binary);
		out << "1";
	}
	in >> mode;
	atexit(save);
	thread task01(KD_H);
	thread task02(KD_G);
	thread task03(KD_L);
	thread task04(KD_S);
	thread task05(ask);
	thread task06(switch_mode);
	task01.join();
	task02.join();
	task03.join();
	task04.join();
	task05.join();
	task06.join();

	return 0;
}