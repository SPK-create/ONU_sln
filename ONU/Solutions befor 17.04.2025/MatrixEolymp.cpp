#include <iostream>
#include <string>
using namespace std;

class Matrix {
private:
	int n, m; //n-строк по m-чисел
	int** arr;

public:
	Matrix(int n, int m, int** arr_ptr) : n(n), m(m) {
		arr = new int* [n];
		for (int i = 0; i < n; i++) {
			arr[i] = new int[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = arr_ptr[i][j];
			}
		}
	};
	Matrix operator+(const Matrix& m_ref) {
		int** arr_sum = new int* [n];
		for (int i = 0; i < n; i++) {
			arr_sum[i] = new int[m];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr_sum[i][j] = arr[i][j] + m_ref.arr[i][j];
			}
		}
		return Matrix(n, m, arr_sum);
	}

	string printMatrix() {
		string str = "";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				str.append(to_string(arr[i][j]) + " ");
			}
			str.append("\n");
		}
		return str;
	}
};

int main() {
	int n, m;
	cin >> n >> m;
	
	int** arr_m1 = new int* [n];
	for (int i = 0; i < n; i++) { // »нициализаци€ массива значений матрицы м1
		arr_m1[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { // «аполнение массива значений матрицы м1
			cin >> arr_m1[i][j];
		}
	}

	int** arr_m2 = new int* [n];
	for (int i = 0; i < n; i++) { // »нициализаци€ массива значений матрицы м2
		arr_m2[i] = new int[m];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) { // «аполнение массива значений матрицы м2
			cin >> arr_m2[i][j];
		}
	}

	Matrix m1(n, m, arr_m1), m2(n, m, arr_m2);

	cout << (m1+m2).printMatrix();

	return 0;
}