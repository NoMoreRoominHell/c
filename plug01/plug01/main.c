#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


void openIE() {
	ShellExecute(0, "open", "http://baidu.com", 0, 0, 1);
}

void click() {
	//光标移动到屏幕指定位置
	SetCursorPos(200, 250);

	//鼠标单击
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//左键按下
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//左键松开
}

void search()
{
	//键盘输入
	keybd_event('J', 0, 0, 0); //按下
	keybd_event('J', 0, 2, 0); //松开
	Sleep(500);
	keybd_event('A', 0, 0, 0); //按下
	keybd_event('A', 0, 2, 0); //松开
	Sleep(500);
	keybd_event('V', 0, 0, 0); //按下
	keybd_event('V', 0, 2, 0); //松开
	Sleep(500);
	keybd_event('A', 0, 0, 0); //按下
	keybd_event('A', 0, 2, 0); //松开
	Sleep(500);

	//回车
	keybd_event(0x0d, 0, 0, 0);
	keybd_event(0x0d, 0, 2, 0);
	Sleep(500);
}

int main() {

	/*
	//打开IE浏览器
	openIE();
	Sleep(3000);
	//输入要查询的关键字
	search();
	Sleep(1000);
	//设置位置点击查询
	click();
	Sleep(2000);
	*/

	int move_x = 0;
	int move_y = 0;

	POINT cursoPos;

	GetCursorPos(&cursoPos);//得到鼠标的位置
	printf("x:%ld y:%ld\n", cursoPos.x, cursoPos.y);

	SetCursorPos(move_x, move_y);


	system("pause");

	return 0;
}