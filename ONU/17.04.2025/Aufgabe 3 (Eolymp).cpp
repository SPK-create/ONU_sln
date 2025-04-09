#include <iostream>
#include <vector>
#include <string>
using namespace std;
//� ������� ������� ����������� ��������� ���� �������� ������������� ����� (������ ������������ �� ������) 

int main() {
	vector<char> v1, v2;
	string n1, n2; //�����, ������� ����� ������ ��� ������
	cin >> n1 >> n2;

	v1.resize(n1.size());
	v2.resize(n2.size());

	for (int i = 0; i < n1.size(); i++) {
		v1[i] = n1[i];
	}
	for (int j = 0; j < n2.size(); j++) {
		v2[j] = n2[j];
	}

	if (v1.size() > v2.size()) {
		cout << ">";
	}
	else if (v1.size() < v2.size()) {
		cout << "<";
	}
	else { //v1.size == v2.size
		int flag = 0;
		for (int i = 0; i < v1.size(); i++) {
			if (int(v1[i]) < int(v2[i])) {
				cout << "<";
				flag++;
				break;
			}
			else if (int(v1[i]) > int(v2[i])) {
				cout << ">";
				flag++;
				break; 
			}
		}
		if (flag == 0) {
			cout << "=";
		}
	}

	return 0;
}