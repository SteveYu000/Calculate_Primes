/*
	�ж� һ�����Ƿ�Ϊ����
	�ж�һ������m�Ƿ���������ֻ���m��2~m-1֮���ÿһ������ȥ������������ܱ���������ôm����һ��������
*/
#include <iostream>
#include <fstream>
#include <windows.h>
#include <limits>
#include <string>
using namespace std;

void Judge_Prime(long long int num) {
		bool counter = 0;  // �����ж�
		for (long long int i = 2; i < num; i++) {
			if (num % i == 0) {
				counter=!counter;  // ��������
				break;
			}
		}

		if (counter == 0) {
			cout << "������" << endl;
		}
		else {
			cout << "��������" << endl;
		}
}
void Calculate_Prime() {
	long long int pri_Num = 0;
	bool counter = 0;       				//pri_NumΪҪ�жϵ�������2��ʼ��counterΪpri_Num����������
	fstream pri_Num_log;
	pri_Num_log.open("����.log", ios::in);
	pri_Num_log >> pri_Num;
	pri_Num_log.close();
	while (1) {
		for (long long int i = 2; i < pri_Num; i++) { 		//���Ϊ2����ֱ�������������ѭ��
			if (pri_Num % i == 0) {				//�ж�pri_Num�Ƿ��г�����֮�����2������
				counter=!counter;
				break;				//������� ����������Ϊ0
			}
		}
		if (counter == 0 && pri_Num != 0 && pri_Num != 1) {
			cout << pri_Num << endl;		//��counterΪ0ʱ��pri_NumΪ����
			fstream pri_Num_log;
			pri_Num_log.open(".//����.log", ios::out);
			pri_Num_log << pri_Num << endl;
			pri_Num_log.close();
		}
		pri_Num += 1;						
		counter = 0;						
	}
}
int main(int argc,char *argv[]) {
		if (argc == 1) {
			cout << "���������\n������ʽ������\t[��ֵ]\npri\t��ֵ\t�ж���������Ƿ�Ϊ����\ncal\t�����֮ǰ�Ĵ浵��ʼ����֮�������\nexit\t�˳�����" << endl;
		}
		else {
			string func = argv[1];
			if (func == "pri"&&argc==3) {
				try {
					long long int key = stoll(argv[2]);
					Judge_Prime(key);
				}
				catch(const invalid_argument &e){
					cout << "��Ч����ֵ��" << e.what() << endl;
					cin.clear();
					cin.ignore((numeric_limits<streamsize>::max)(), '\n');
				}
			}
			else if (func == "cal") {
				Calculate_Prime();
			}
			else {
				cout << "δ����Ĳ���������ȷ�������\n������ʽ������\t[��ֵ]\npri\t��ֵ\t�ж���������Ƿ�Ϊ����\ncal\t�����֮ǰ�Ĵ浵��ʼ����֮�������\nexit\t�˳�����" << endl;
			}
		}
	return 0;
}
