/*
	判断 一个数是否为质数
	判断一个整数m是否是素数，只需把m被2~m-1之间的每一个整数去除，如果都不能被整除，那么m就是一个素数。
*/
#include <iostream>
#include<fstream>
#include <windows.h>
using namespace std;
int main() {
	cout<<"这是一个计算和判断质数的程序"<< endl;
	cout<<"现有2种功能：\n（1）判断一个数是否为质数\n（2）从零或之前的存档开始计算之后的质数\n请输入1或2以继续："<<endl;
	int start=0;
	cin >> start;
	if(start==1||start==2) {
		system("cls");
			if(start==1) {
				while(1) {
					int a=0;  // 素数的个数
					long long int num=0;  // 输入的整数
					cout<<"输入一个整数：";
					cin >> num;
					for(long long int i=2; i<num; i++) {
						if(num%i==0) {
							a++;  // 素数个数加1
							break;
						}
					}

					if(a==0) {
						MessageBox(NULL,TEXT("是质数"),TEXT("判断结果"),MB_OK);
					} 
					else {
						MessageBox(NULL,TEXT("不是质数"),TEXT("判断结果"),MB_OK);
					}
					system("cls");
				}
			}
			if(start==2) {
				long int a=0,b=0;       				//a为要判断的数，从2开始；b为a的因数个数
				ifstream fin ("质数.inf");
				fin>>a;
				fin.close();
				while(1) {
					for(long long int i=2; i<a; i++) { 		//如果为2，则直接输出，不进入循环
						if(a%i==0) {				//判断a是否有除本身之外大于2的因数
							b++;
							continue;				//如果有则 因数个数 加1
						}
					}
					if(b==0&&a!=0&&a!=1) {
						cout << a << endl;		//当b为0时，a为质数
						ofstream ouf( ".\\质数.inf" );
						ofstream fout( ".\\质数.inf" );
						fout << a << endl;
						fout.close();
					}
					a+=1;						/*(1)当a为质数，输出之后加1
											  	(2)当a为和数，直接加1*/
					b=0;						//#注意!# 把b初始化
				}
			}
		} else {
			cin.clear();
			cin.sync();
			cout<<"输入无效，请重新输入" <<endl;
		}			
	return 0;
}
