/*
	�ж� һ�����Ƿ�Ϊ����
	�ж�һ������m�Ƿ���������ֻ���m��2~m-1֮���ÿһ������ȥ������������ܱ���������ôm����һ��������
*/
#include <iostream>
#include <fstream>
#include <windows.h>
#include <limits>
using namespace std;

void Judge_Prime() {
		int counter = 0;  // �����ĸ���
		long long int num = 0;  // ���������
		cout << "����һ��������";
		while (1) {
			cin >> num;
			if (cin.fail()) {
				cout << "�������󣬱���Ϊ������\n����������" << endl;
				cin.clear(); // ��������־
				cin.ignore((numeric_limits<streamsize>::max)(), '\n'); // ������Ч����
			}
			else {
				break;
			}
		}
		
		for (long long int i = 2; i < num; i++) {
			if (num % i == 0) {
				counter++;  // ����������1
				break;
			}
		}

		if (counter == 0) {
			MessageBox(NULL, TEXT("������"), TEXT("�жϽ��"), MB_OK);
		}
		else {
			MessageBox(NULL, TEXT("��������"), TEXT("�жϽ��"), MB_OK);
		}
		system("cls");
}
void Calculate_Prime() {
	long long int pri_Num = 0, counter = 0;       				//pri_NumΪҪ�жϵ�������2��ʼ��counterΪpri_Num����������
	ifstream pri_Num_log("����.log");
	pri_Num_log >> pri_Num;
	pri_Num_log.close();
	while (1) {
		for (long long int i = 2; i < pri_Num; i++) { 		//���Ϊ2����ֱ�������������ѭ��
			if (pri_Num % i == 0) {				//�ж�pri_Num�Ƿ��г�����֮�����2������
				counter++;
				continue;				//������� �������� ��1
			}
		}
		if (counter == 0 && pri_Num != 0 && pri_Num != 1) {
			cout << pri_Num << endl;		//��counterΪ0ʱ��pri_NumΪ����
			ofstream ouf(".\\����.log");
			ofstream fout(".\\����.log");
			fout << pri_Num << endl;
			fout.close();
		}
		pri_Num += 1;						/*(1)��aΪ���������֮���1
									(2)��aΪ������ֱ�Ӽ�1*/
		counter = 0;						//ע��!��b��ʼ��
	}
}
int main() {
	while (1) {
		cout << "����һ��������ж������ĳ���" << endl;
		cout << "����2�ֹ��ܣ�\n��1���ж�һ�����Ƿ�Ϊ����\n��2�������֮ǰ�Ĵ浵��ʼ����֮�������\n������1��2�Լ���,����exit�˳�����" << endl;
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
		else {//�������봦��
			cin.clear();
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			system("cls");
			cout << "������Ч������������" << endl;
		}
	}		
	return 0;
}
