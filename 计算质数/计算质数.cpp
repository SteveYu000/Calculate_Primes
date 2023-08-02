/*
	判断 一个数是否为质数
	判断一个整数m是否是素数，只需把m被2~m-1之间的每一个整数去除，如果都不能被整除，那么m就是一个素数。
*/
#include <iostream>
#include <fstream>
#include <windows.h>
#include <limits>
using namespace std;

void Judge_Prime() {
		int counter = 0;  // 素数的个数
		long long int num = 0;  // 输入的整数
		cout << "输入一个整数：";
		while (1) {
			cin >> num;
			if (cin.fail()) {
				cout << "输入有误，必须为整数！\n请重新输入" << endl;
				cin.clear(); // 清除错误标志
				cin.ignore((numeric_limits<streamsize>::max)(), '\n'); // 忽略无效输入
			}
			else {
				break;
			}
		}
		
		for (long long int i = 2; i < num; i++) {
			if (num % i == 0) {
				counter++;  // 素数个数加1
				break;
			}
		}

		if (counter == 0) {
			MessageBox(NULL, TEXT("是质数"), TEXT("判断结果"), MB_OK);
		}
		else {
			MessageBox(NULL, TEXT("不是质数"), TEXT("判断结果"), MB_OK);
		}
		system("cls");
}
void Calculate_Prime() {
	long long int pri_Num = 0, counter = 0;       				//pri_Num为要判断的数，从2开始；counter为pri_Num的因数个数
	ifstream pri_Num_log("质数.log");
	pri_Num_log >> pri_Num;
	pri_Num_log.close();
	while (1) {
		for (long long int i = 2; i < pri_Num; i++) { 		//如果为2，则直接输出，不进入循环
			if (pri_Num % i == 0) {				//判断pri_Num是否有除本身之外大于2的因数
				counter++;
				continue;				//如果有则 因数个数 加1
			}
		}
		if (counter == 0 && pri_Num != 0 && pri_Num != 1) {
			cout << pri_Num << endl;		//当counter为0时，pri_Num为质数
			ofstream ouf(".\\质数.log");
			ofstream fout(".\\质数.log");
			fout << pri_Num << endl;
			fout.close();
		}
		pri_Num += 1;						/*(1)当a为质数，输出之后加1
									(2)当a为和数，直接加1*/
		counter = 0;						//注意!把b初始化
	}
}
int main() {
	while (1) {
		cout << "这是一个计算和判断质数的程序" << endl;
		cout << "现有2种功能：\n（1）判断一个数是否为质数\n（2）从零或之前的存档开始计算之后的质数\n请输入1或2以继续,输入exit退出程序：" << endl;
		string start;
		cin >> start;
		if (start == "1" || start == "2") {
			system("cls");
			if (start == "1") {
				Judge_Prime();
			}
			if (start == "2") {
				void Calculate_Prime();
			}
		}
		if (start == "exit") {
			break;
		}
		else {//错误输入处理
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			system("cls");
			cout << "输入无效，请重新输入" << endl;
		}
	}		
	return 0;
}
