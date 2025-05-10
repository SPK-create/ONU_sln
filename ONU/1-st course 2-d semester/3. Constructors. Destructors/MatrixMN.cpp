#include <iostream>
#include <string.h>
#include <string>
using namespace std;

class MatrixMN {
private:
	int m, n; //розмерность матрицы
	int** arr_ptr;
public:
	MatrixMN(int m, int n, int** arr) : m(m), n(n) {
		arr_ptr = new int* [m];
		for (int i = 0; i < m; i++) {
			arr_ptr[i] = new int[n];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				arr_ptr[i][j] = arr[i][j];
			}
		}
	}
	MatrixMN() : m(0), n(0), arr_ptr(NULL) {};
	~MatrixMN() {
		for (int i = 0; i < m; i++) {
			delete arr_ptr[i];
		}
		delete arr_ptr;
	};

	string isZero() { //Метод проверки, являются ли все элементы матрицы нулями
		int* k = 0; //Флаг, если найдется любое число, отличное от 0, то к числу k будет прибавляться 1
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr_ptr[i][j] != 0) {
					k++;
				}
			}
		}
		if (k == 0) { return "All elements of matrix - nulls."; }
		else { return "NOT all elements of matrix - nulls."; }
		delete k;
	}

	double getNorm() { //Норма Фробениуса
		long sum = 0; //Будет использоваться для нахождения суммы элементов матрицы
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				sum += arr_ptr[i][j] * arr_ptr[i][j]; //Находим сумму всех элем. в квадрате матрицы
			}
		}
		return sqrt(sum);
	}

	string toString() { //Вывод матрицы в форматированной строке
		string s = "";
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				s.append(to_string(arr_ptr[i][j]) + " ");
			}
			s.append("\n");
		}
		return s;
	}

	MatrixMN add(const MatrixMN& a) {
		int** new_arr = new int* [m];
		for (int j = 0; j < m; j++) { //Инициализация нового массива под новую матрицу
			new_arr[j] = new int[n];
		}

		for (int i = 0; i < this->m; i++) {
			for (int j = 0; j < this->n; j++) {
				new_arr[i][j] = arr_ptr[i][j] + a.arr_ptr[i][j]; //Заполняю новый массив для новой матрицы как сумму элементов двух матриц
			}
		}
		return MatrixMN(m, n, new_arr);
	}

	MatrixMN operator+(const MatrixMN& a) {
		int** new_arr = new int* [m];
		for (int j = 0; j < m; j++) { //Инициализация нового массива под новую матрицу
			new_arr[j] = new int[n];
		}

		for (int i = 0; i < this->m; i++) {
			for (int j = 0; j < this->n; j++) {
				new_arr[i][j] = arr_ptr[i][j] + a.arr_ptr[i][j]; //Заполняю новый массив для новой матрицы как сумму элементов двух матриц
			}
		}
		return MatrixMN(m, n, new_arr);
	};

	MatrixMN operator+(const int& a) {
		int** new_arr = new int* [m];
		for (int j = 0; j < m; j++) { //Инициализация нового массива под новую матрицу
			new_arr[j] = new int[n];
		}

		for (int i = 0; i < this->m; i++) {
			for (int j = 0; j < this->n; j++) {
				new_arr[i][j] = arr_ptr[i][j] + a; //Заполняю новый массив для новой матрицы как сумму элементов двух матриц
			}
		}
		return MatrixMN(m, n, new_arr);
	};

	MatrixMN operator-(const MatrixMN& a) {
		int** new_arr = new int* [m];
		for (int j = 0; j < m; j++) { //Инициализация нового массива под новую матрицу
			new_arr[j] = new int[n];
		}

		for (int i = 0; i < this->m; i++) {
			for (int j = 0; j < this->n; j++) {
				new_arr[i][j] = arr_ptr[i][j] - a.arr_ptr[i][j]; //Заполняю новый массив для новой матрицы как разницу элементов двух матриц
			}
		}
		return MatrixMN(m, n, new_arr);
	};

	MatrixMN operator-(const int& a) {
		int** new_arr = new int* [m];
		for (int j = 0; j < m; j++) { //Инициализация нового массива под новую матрицу
			new_arr[j] = new int[n];
		}

		for (int i = 0; i < this->m; i++) {
			for (int j = 0; j < this->n; j++) {
				new_arr[i][j] = arr_ptr[i][j] + a; //Заполняю новый массив для новой матрицы как разницу элементов двух матриц
			}
		}
		return MatrixMN(m, n, new_arr);
	};

	MatrixMN operator*(const int& a) {
		int** new_arr = new int* [m];
		for (int j = 0; j < m; j++) { //Инициализация нового массива под новую матрицу
			new_arr[j] = new int[n];
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				new_arr[i][j] = arr_ptr[i][j] * a; //Заполняю новый массив для новой матрицы как произведение элементов двух матриц
			}
		}
		return MatrixMN(m, n, new_arr);
	};

	int getM() {
		return m;
	};
	int getN() {
		return n;
	};
	int** getArr() {
		return arr_ptr;
	}
};

std::ostream& operator<<(std::ostream& out, MatrixMN& matrix) {
	for (int i = 0; i < matrix.getM(); i++) {
		for (int j = 0; j < matrix.getN(); j++) {
			out << matrix.getArr()[i][j] << " ";
		}
		out << endl;
	}
	return out;
}

int main() {
	int m, n;
	cin >> m >> n;
	//Инициализация и создание матрицы 1
	int** arr1 = new int* [m];
	for (int i = 0; i < m; i++) {
		arr1[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr1[i][j];
		}
	}
	//Инициализация и создание матрицы 2
	int** arr2 = new int* [m];
	for (int i = 0; i < m; i++) {
		arr2[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr2[i][j];
		}
	}
	MatrixMN m1(m, n, arr1), m2(m, n, arr2), m3;

	cout << "Matrix 1:" << endl;
	cout << m1 << endl << m1.isZero() << endl;
	cout << "Frobenius normalization = " << m1.getNorm() << endl << endl;
	cout << "Matrix 2:" << endl;
	cout << m2 << endl << m2.isZero() << endl;
	cout << "Frobenius normalization = " << m2.getNorm() << endl << endl;
	cout << "Matrix 3:" << endl;
	cout << m3 << endl << m3.isZero() << endl;
	cout << "Frobenius normalization = " << m3.getNorm() << endl << endl;

	cout << "Example of output via 'toString()' method of matrix m1:" << endl;
	cout << m1.toString() << endl;

	cout << "Example of adding matrix m1 with matrix m2 via method 'm1.add(m2)':" << endl;
	MatrixMN m4 = m1.add(m2);
	cout << m4 << endl;

	cout << "Example of adding matrix m1 with matrix m2 via overloaded operator '+' :" << endl;
	MatrixMN m6 = m1 + m2;
	cout << m6 << endl;
	cout << "And the example of adding matrix m1 with constant number 3 via overloaded operator '+' :" << endl;
	MatrixMN m7 = m1 + 3;
	cout << m7 << endl;

	cout << "Example of subtracting matrix m1 with matrix m2 via overloaded operator '-' :" << endl;
	MatrixMN m8 = m1 - m2;
	cout << m8 << endl;
	cout << "And the example of subtracting matrix m1 with constant number 3 via overloaded operator '-' :" << endl;
	MatrixMN m9 = m1 - 3;
	cout << m9 << endl;

	cout << "And the example of multiplication matrix m1 with constant number 3 via overloaded operator '*' :" << endl;
	MatrixMN m10 = m1 * 3;
	cout << m10 << endl;
}