#include <iostream>
using namespace std;
// 1) что не так с кодом с точки зрения инкапсуляции? как исправить?
// 2) добавьте возможность вызова конструктора без параметров, чтобы создавалась матрица размера 1Х1 
// 3) реализовать деструктор
// 4) перегрузить операцию ввода >>
// 5) перегрузить операцию вывода <<
// 6) обработать создание матрицы с отрицательной размерностью
// 7) перегрузить операцию + сложения 2х матриц 
// 8) перегрузить операцию * умножения матрицы на число
// 8) перегрузить операцию * умножения матрицы на матрицу
// 9) написать класс наследник квадратная матрица, с методом вычисляющим след матрицы(сумма элементов главной диаганали)
template <typename T>
class Matrix{
protected:
	T** a;
	int size1, size2;
public:
	Matrix(int n, int m) {
		while (n <= 0 or m <= 0) {
			cout << "Warning!" << endl;
			cin >> n >> m;
		}
		size1 = n; size2 = m;
		a = new T * [n];
		for (int i = 0; i < n; i++) {
			a[i] = new T[m];
		}
	}
	Matrix() : size1(1), size2(1) {
		a = new T * [1];
		a[0] = new T[1];
	}
	T* operator [](const int i) { return a[i]; }

	Matrix operator+(const Matrix& lhs) {
		Matrix c(size1, size2);
		for (int i = 0; i < size1; i++) {
			for (int j = 0; j < size2; j++) {
				c.a[i][j] = a[i][j] + lhs.a[i][j];
			}
		}
		return c;
	}

	Matrix operator*(const int c) {
		Matrix m(size1, size2);
		for (int i = 0; i < size1; i++) {
			for (int j = 0; j < size2; j++) {
				m.a[i][j] = a[i][j] * c;
			}
		}
		return m;
	}

	Matrix operator*(const Matrix& lhs) {
		if (size2 != lhs.size1) {
			cout << "Multiplication cannot be done.";
		}
		else {
			Matrix m(size1, lhs.size2);
			for (int i = 0; i < size1; i++)
			{
				for (int j = 0; j < lhs.size2; j++)
				{
					m[i][j] = 0;
					for (int k = 0; k < size2; k++)
					{
						m.a[i][j] += a[i][k] * lhs.a[k][j];
					}
				}
			}
			return m;
		}
	}

	friend	ostream& operator<< (ostream& os, const Matrix& a) {
		//	  countT++;
		for (int i = 0; i < a.size1; i++) { 
			for (int j = 0; j < a.size2; j++) {
				os << a.a[i][j] << " ";
			}
			os << endl;
		}
		return os;
	}
	friend	istream& operator>> (istream& is, const Matrix& a) {
		//	  countT++;
		for (int i = 0; i < a.size1; i++) {
			for (int j = 0; j < a.size2; j++) {
				is >> a.a[i][j];
			}
		}
		return is;
	}
};

template <typename T>
class SquareMatrix : public Matrix <T> {
public:
	SquareMatrix(int a) : Matrix<T>(a, a) {}
	SquareMatrix(): Matrix() {}
	T trace() {
		T p = 0;
		for (int i = 0, j = 0; i < this->size1; i++, j++) {
			p += this->a[i][j];
		}
		return p;
	}

	friend istream& operator>> (istream& is, const SquareMatrix& a) {
		//	  countT++;
		for (int i = 0; i < a.size1; i++) {
			for (int j = 0; j < a.size2; j++) {
				is >> a.a[i][j];
			}
		}
		return is;
	}
};

int main(void)
{
	Matrix<double> a(2, 2);
	cin >> a;
	Matrix<double> b(2, 2);
	cin >> b;
	Matrix<double> c(2, 2);
	cout << endl;
	c = a + b;
	cout << c;
	cout << endl;
	c = a * 4;
	cout << c;
	cout << endl;
	c = a * b;
	cout << c;
	cout << endl;
	SquareMatrix<int> d(3);
	cin >> d;
	cout << endl;
	cout << d.trace();
	return 0;
}