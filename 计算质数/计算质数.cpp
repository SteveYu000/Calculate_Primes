/*
	�ж� һ�����Ƿ�Ϊ����
	�ж�һ������m�Ƿ���������ֻ���m��2~m-1֮���ÿһ������ȥ������������ܱ���������ôm����һ��������
*/
#include <iostream>
#include<fstream>
#include <windows.h>
using namespace std;
int main() {
	cout<<"����һ��������ж������ĳ���"<< endl;
	cout<<"����2�ֹ��ܣ�\n��1���ж�һ�����Ƿ�Ϊ����\n��2�������֮ǰ�Ĵ浵��ʼ����֮�������\n������1��2�Լ�����"<<endl;
	int start=0;
	cin >> start;
	if(start==1||start==2) {
		system("cls");
			if(start==1) {
				while(1) {
					int a=0;  // �����ĸ���
					long long int num=0;  // ���������
					cout<<"����һ��������";
					cin >> num;
					for(long long int i=2; i<num; i++) {
						if(num%i==0) {
							a++;  // ����������1
							break;
						}
					}

					if(a==0) {
						MessageBox(NULL,TEXT("������"),TEXT("�жϽ��"),MB_OK);
					} 
					else {
						MessageBox(NULL,TEXT("��������"),TEXT("�жϽ��"),MB_OK);
					}
					system("cls");
				}
			}
			if(start==2) {
				long int a=0,b=0;       				//aΪҪ�жϵ�������2��ʼ��bΪa����������
				ifstream fin ("����.inf");
				fin>>a;
				fin.close();
				while(1) {
					for(long long int i=2; i<a; i++) { 		//���Ϊ2����ֱ�������������ѭ��
						if(a%i==0) {				//�ж�a�Ƿ��г�����֮�����2������
							b++;
							continue;				//������� �������� ��1
						}
					}
					if(b==0&&a!=0&&a!=1) {
						cout << a << endl;		//��bΪ0ʱ��aΪ����
						ofstream ouf( ".\\����.inf" );
						ofstream fout( ".\\����.inf" );
						fout << a << endl;
						fout.close();
					}
					a+=1;						/*(1)��aΪ���������֮���1
											  	(2)��aΪ������ֱ�Ӽ�1*/
					b=0;						//#ע��!# ��b��ʼ��
				}
			}
		} else {
			cin.clear();
			cin.sync();
			cout<<"������Ч������������" <<endl;
		}			
	return 0;
}
