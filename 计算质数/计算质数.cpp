/*
	判断 一个数是否为质数
	判断一个整数m是否是素数，只需把m被2~m-1之间的每一个整数去除，如果都不能被整除，那么m就是一个素数。
*/
#include <iostream>
#include <fstream>
#include <limits>
#include <string>
using namespace std;

void Judge_Prime(long long int num) {
		bool counter = 0;  // 素数判断
		for (long long int i = 2; i < num; i++) {
			if (num % i == 0) {
				counter=!counter;  // 不是素数
				break;
			}
		}

		if (counter == 0) {
			cout << "是质数" << endl;
		}
		else {
			cout << "不是质数" << endl;
		}
}
void Calculate_Prime() {
	long long int pri_Num = 0;
	bool counter = 0;       				//pri_Num为要判断的数，从2开始；counter为pri_Num的因数个数
	fstream pri_Num_log;
	pri_Num_log.open("质数.log", ios::in);
	pri_Num_log >> pri_Num;
	pri_Num_log.close();
	while (1) {
		for (long long int i = 2; i < pri_Num; i++) { 		//如果为2，则直接输出，不进入循环
			if (pri_Num % i == 0) {				//判断pri_Num是否有除本身之外大于2的因数
				counter=!counter;
				break;				//如果有则 因数个数不为0
			}
		}
		if (counter == 0 && pri_Num != 0 && pri_Num != 1) {
			cout << pri_Num << endl;		//当counter为0时，pri_Num为质数
			fstream pri_Num_log;
			pri_Num_log.open(".//质数.log", ios::out);
			pri_Num_log << pri_Num << endl;
			pri_Num_log.close();
		}
		pri_Num += 1;						
		counter = 0;						
	}
}
int main(int argc,char *argv[]) {
		if (argc == 1) {
			cout << "请输入参数\n参数格式：功能\t[数值]\npri\t数值\t判断输入的数是否为质数\ncal\t从零或之前的存档开始计算之后的质数\nexit\t退出程序" << endl;
		}
		else {
			string func = argv[1];
			if (func == "pri"&&argc==3) {
				try {
					long long int key = stoll(argv[2]);
					Judge_Prime(key);
				}
				catch(const invalid_argument &e){
					cout << "无效的数值：" << e.what() << endl;
					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				}
			}
			else if (func == "cal") {
				Calculate_Prime();
			}
			else {
				cout << "未定义的操作，请正确输入参数\n参数格式：功能\t[数值]\npri\t数值\t判断输入的数是否为质数\ncal\t从零或之前的存档开始计算之后的质数\nexit\t退出程序" << endl;
			}
		}
	return 0;
}
