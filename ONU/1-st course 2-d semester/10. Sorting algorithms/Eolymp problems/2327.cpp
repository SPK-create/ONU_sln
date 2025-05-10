#include <iostream>
#include <vector>
using namespace std;

//���������� ���������:
int main() {
	int n;
	cin >> n; //���-�� ����. � �������
	vector<int> arr;

	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		arr.push_back(c);
	}

	int max_num = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] > max_num) {
			max_num = arr[i];
		}
	}

	vector<int> answ(max_num+1, 0);
	 
	// ������ ������� ������ ����� ������ ����� ��� ������ ������� ������� �����
	for (int i = 0; i < n; i++) {
		answ[arr[i]]++;
	}

	for (int i = 0; i < answ.size(); i++) {
		for (int j = 0; j < answ[i]; j++) {
			cout << i << " ";
		}
	}

	return 0;
}