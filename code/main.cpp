#include <cstring>
#include <windows.h>
#include <conio.h>
#include <thread>

using namespace std;

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) 
#define edition "GHSL2FJDK 1.0"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

void KD_H()
{
	int press = 0;
	while (1)
	{
		if (KEY_DOWN('H'))
		{
			if (press == 0) keybd_event('J', 0, 0, 0);
			press = 1;
		}
		else
		{
			if (press == 1)
			{
				keybd_event('J', 0, KEYEVENTF_KEYUP, 0);
			}
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
			if (press == 0) keybd_event('F', 0, 0, 0);
			press = 1;
		}
		else
		{
			if (press == 1)
			{
				keybd_event('F', 0, KEYEVENTF_KEYUP, 0);
			}
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
			if (press == 0) keybd_event('K', 0, 0, 0);
			press = 1;
		}
		else
		{
			if (press == 1)
			{
				keybd_event('K', 0, KEYEVENTF_KEYUP, 0);
			}
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
			if (press == 0) keybd_event('D', 0, 0, 0);
			press = 1;
		}
		else
		{
			if (press == 1)
			{
				keybd_event('D', 0, KEYEVENTF_KEYUP, 0);
			}
			press = 0;

		}
		Sleep(1);
	}
}

void ask()
{
	if (MessageBoxA(0, "点击 \"确定\" 来退出本程序", edition, MB_OK) == 1) exit(0);
}

int main()
{
	thread task01(KD_H);
	thread task02(KD_G);
	thread task03(KD_L);
	thread task04(KD_S);
	thread task05(ask);
	task01.join();
	task02.join();
	task03.join();
	task04.join();
	task05.join();

	return 0;
}