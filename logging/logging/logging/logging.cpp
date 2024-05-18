#include <iostream>
#include <string>
#include<fstream>
#include <streambuf>
#include<conio.h>
#include<windows.h>
#pragma warning(disable : 4996)
#define fn "logging.csv"
using namespace std;

int main()
{
start:
	system("cls");
	cout << "logging!Powered by sweetpeach.\n";
	cout << "日志将会保存在" << fn << "中\n";

	cout << "选择一个选项：\n1,写入文件；\n2,读取文件；\n3,格式化日志；\n4,退出；\n";
	char i;
	i = getch();
	if (i == '1') {
		fstream f;
		f.open(fn, ios::app);
		system("cls");

		while (true)
		{
			string log;

			cout << "在这里键入你的内容(指令/help...）：\n";
			cin >> log;
			if (log.c_str()[0] != '/') {
				time_t t = time(0);
				char s[32];
				strftime(s, sizeof(s), "%Y-%m-%d %H:%M:%S", localtime(&t));
				string time = s;
				time = "[" + time + "]";
				string end = time + "," + log + "\n";
				f.write(end.c_str(), strlen(end.c_str()));
				for (int j = 2; j >= 0; j--) {
					system("cls");
					cout << "已经记录，记录为：" << end.c_str();
					cout << "目视倒计时：" << j << endl;
					Sleep(1000);
					system("cls");
				}

			}
			else {
				if (log._Equal("/q")) {
					f.close();
					system("cls");
					goto start;
					break;
				}
				else if (log._Equal("/help")) {
					system("cls");
					cout << "------------------\n";
					cout << "指令列表：\n";
					cout << "/help 帮助\n";
					cout << "/q    退出\n";
					cout << "------------------\n";
				}
				else {
					cout << "无效的指令！\n";
				}

			}
		}

	}
	else if (i == '2') {
		system("cls");
		std::ifstream t(fn);
		std::string str((std::istreambuf_iterator<char>(t)),
			std::istreambuf_iterator<char>());
		cout << "读取到的日志为：\n";
		cout << str;
		cout << "\n按下任意键返回...\n";
		system("pause >nul");
		system("cls");
		goto start;
	}
	else if (i == '3') {
		system("cls");
		cout << "真的要格式化日志吗？(y)" << endl;
		char c;
		c = getch();
		if (c == 'y') {
			fstream f;
			f.open(fn, ios::out);
			string end = "time                 ,note\n";
			f.write(end.c_str(), strlen(end.c_str()));
		}
		else {
			cout << "\n按下任意键返回...\n";
			system("pause >nul");
			system("cls");
			goto start;
		}
		cout << "\n按下任意键返回...\n";
		system("pause >nul");
		system("cls");
		goto start;
	}
	else if (i == '4') {
		return 0;
	}
	else {
		cout << "\n\n无效选择！\n";
		goto start;
	}
	return 0;
}
