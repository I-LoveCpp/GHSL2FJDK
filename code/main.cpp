#include <cstring>
#include <vector>
#include <thread> 
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

#pragma comment( linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"" ) 
#define edition "GHSL2FJDK 2.1"
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0)

vector<thread> threads;
int mode = 1, codes[6] = { 1, 2, 0, 0, 0, 0 };
char xs[6] = { ' ', ' ', 'G', 'H', 'S', 'L' }, ys[6][2] = { { ' ', ' '}, { ' ', ' '}, {VK_DOWN, 'F'}, {VK_RIGHT, 'J'}, {VK_UP, 'D'}, {VK_LEFT, 'K'} };

void task(char x, char y[2], int code) noexcept
{
	if (code == 0)
	{
		int press = 0;
		while (1)
		{
			if (KEY_DOWN(x))
			{
				if (press == 0 && mode == 0) keybd_event(y[0], 0, 0, 0);
				if (press == 0 && mode == 1) keybd_event(y[1], 0, 0, 0);
				press = 1;
			}
			else
			{
				if (press == 1 && mode == 0) keybd_event(y[0], 0, KEYEVENTF_KEYUP, 0);
				if (press == 1 && mode == 1) keybd_event(y[1], 0, KEYEVENTF_KEYUP, 0);
				press = 0;
			}
			Sleep(1);
		}
	}
	else if (code == 1)
	{
		if (MessageBoxA(0, "点击 \"确定\" 来退出本程序", edition, MB_OK) == 1) exit(0);
	}
	else if (code == 2)
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
}

void init()
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
	atexit([]() {ofstream out("D:\\Data\\GHSL2FJDK\\Mode.Ceh", ios::binary); out << mode; });
}

int main()
{
	init();
	for (int i = 0; i < 6; i++)
		threads.push_back(thread(task, xs[i], ys[i], codes[i]));
	for (auto it = threads.begin(); it != threads.end(); it++)
		it->join();
	return 0;
}