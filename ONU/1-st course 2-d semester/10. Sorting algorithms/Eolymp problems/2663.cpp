#include <iostream>
#include <vector>
using namespace std;

int answ[2]{};
template <typename T> int BubbleSort(vector<T>&);

int main() {
	vector<int> vector;
	int n, c;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> c;
		vector.push_back(c);
	}
	int answ = BubbleSort(vector);
	cout << answ;
	
	return 0;
}

template <typename T> int BubbleSort(vector<T>& v) {
	// �� ������� ������ ������ ������� �� 1 �������� � ������
	// ���� ������� ���-�� ������������ �� ����� ������ ���������
	int size = v.size();
	int true_position = 0; //�������� �� ��, ����� �� ������� � ���������� �����
	int permutations = 0; //���-�� ������������ �� ����� ����������

	if (size == 1) {
		return 1;
	}

	/* �.�. ���� �� ����� ������� �� ������� �� ������� ���� �� ���� ������������ ���������, ����� ����������� �������� � ���������� �������, ��
	* ��� ���������� �� �� ����� �����������, �.�. �������� �� ������ � ���������� ������
	* ���-�� ��������� ������ ����� �� 1 ������ ���-�� ��������� �������
	*/

	while (true_position != (size - 1)) {
		true_position = 0;
		for (int i = 0; i < (v.size() - 1); i++) {
			if (v[i] > v[i + 1]) {
				T tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
				permutations++;
			}
			else { true_position++; }
		}
	}

	return permutations;
}