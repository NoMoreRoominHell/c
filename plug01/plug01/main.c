#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>


void openIE() {
	ShellExecute(0, "open", "http://baidu.com", 0, 0, 1);
}

void click() {
	//����ƶ�����Ļָ��λ��
	SetCursorPos(200, 250);

	//��굥��
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);//�������
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);//����ɿ�
}

void search()
{
	//��������
	keybd_event('J', 0, 0, 0); //����
	keybd_event('J', 0, 2, 0); //�ɿ�
	Sleep(500);
	keybd_event('A', 0, 0, 0); //����
	keybd_event('A', 0, 2, 0); //�ɿ�
	Sleep(500);
	keybd_event('V', 0, 0, 0); //����
	keybd_event('V', 0, 2, 0); //�ɿ�
	Sleep(500);
	keybd_event('A', 0, 0, 0); //����
	keybd_event('A', 0, 2, 0); //�ɿ�
	Sleep(500);

	//�س�
	keybd_event(0x0d, 0, 0, 0);
	keybd_event(0x0d, 0, 2, 0);
	Sleep(500);
}

int main() {

	/*
	//��IE�����
	openIE();
	Sleep(3000);
	//����Ҫ��ѯ�Ĺؼ���
	search();
	Sleep(1000);
	//����λ�õ����ѯ
	click();
	Sleep(2000);
	*/

	int move_x = 0;
	int move_y = 0;

	POINT cursoPos;

	GetCursorPos(&cursoPos);//�õ�����λ��
	printf("x:%ld y:%ld\n", cursoPos.x, cursoPos.y);

	SetCursorPos(move_x, move_y);


	system("pause");

	return 0;
}