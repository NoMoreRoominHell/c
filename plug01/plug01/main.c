#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void openIE() {
	ShellExecute(0, "open", "http://baidu.com", 0, 0, 1);
}
void library() {
	int move_x = 0;
	int move_y = 0;

	POINT cursoPos;
	GetCursorPos(&cursoPos);//得到鼠标的位置
	printf("x:%ld y:%ld\n", cursoPos.x, cursoPos.y);

	SetCursorPos(move_x, move_y);//设置鼠标位置

								 //鼠标单击
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//左键按下
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//左键松开

	keybd_event('A', 0, 0, 0);
	keybd_event('A', 0, KEYEVENTF_KEYUP, 0);
}

int main() {
	char ch;
	//循环监听，直到按Esc键退出
	while (ch = getch()) {
		if (ch == 27) {
			break;
		}
		if (ch == VK_F1) {
			printf("f1\n");
		}
		else {
			printf("%d", ch);
		}
	}

	system("pause");
	return 0;
}