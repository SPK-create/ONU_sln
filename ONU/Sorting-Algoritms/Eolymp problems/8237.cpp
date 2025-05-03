#include <iostream>
#include <vector>
using namespace std;

template <typename T> void BubbleSort(vector<T>&);

int main() {
	int n;
	cin >> n;
	vector <int> arr;
	for (int i = 0; i < n; i++) {
		int c;
		cin >> c;
		arr.push_back(c);
	}

	BubbleSort(arr);

	return 0;
}

template <typename T> void BubbleSort(vector<T>& v) {
	// �� ������� ������ ������ ������� �� 1 � ������
	int size = v.size();
	int true_position = 0; //�������� �� ��, ����� �� ������� � ���������� �����

	if (size == 1) {
		return;
	}

	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - 1 - i; j++) {
			if (v[j] > v[j + 1]) {
				swap(v[j], v[j + 1]);
			}
		}
		// ������ ������� ����� ������ ��������
		for (int k = 0; k < size; k++) {
			cout << v[k] << " ";
		}
		cout << endl;
	}

	return;
}