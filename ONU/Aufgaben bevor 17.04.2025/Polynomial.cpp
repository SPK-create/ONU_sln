#include <iostream>
using namespace std;

class Polynomial {
private:
	int a, b, c;
public:
	Polynomial() : a(0), b(0), c(0) {}
	Polynomial(int a, int b, int c): a(a), b(b), c(c) {}

	Polynomial operator+(const Polynomial& p) {
		return Polynomial((a + p.a), (b + p.b), (c + p.c));
	}

	Polynomial operator-(const Polynomial& p) {
		return Polynomial((a - p.a), (b - p.b), (c - p.c));
	}

	Polynomial operator*(const int z) { //z = const
		return Polynomial((a * z), (b * z), (c * z));
	}

	void operator*(const Polynomial& p) {
		cout << (a * p.a) << "x^4 + " << ((a * p.b) + (b * p.a)) << "x^3 + " << ((a * p.c) + (b * p.b) + (c * p.a)) << "x^2 + " << ((b * p.c) + (c * p.b)) << "x + " << (c*p.c);
	}

	Polynomial operator/(const int z) { //z = const
		return Polynomial((a / z), (b / z), (c / z));
	}

	int getA() {
		return a;
	}
	int getB() {
		return b;
	}
	int getC() {
		return c;
	}
};

ostream& operator<<(ostream& out, Polynomial& p) {
	out << p.getA() << "x^2 + " << p.getB() << "x + " << p.getC();
	return out;
}

int main() {
	Polynomial p1(2, 4, 6), p2(3, 6, 9);
	Polynomial p3 = p1 + p2;
	cout << "Sum of two polynomials p1 + p2:" << endl << p3 << endl << endl;

	Polynomial p4 = p1 - p2;
	cout << "Substraction of two polynomials p1 - p2:" << endl << p4 << endl << endl;

	Polynomial p5 = p1 * 3;
	cout << "Multiplication of polynomial p1 with number '3':" << endl << p5 << endl << endl;

	cout << "Multiplication of two polynomials p1 * p2:" << endl; 
	p1* p2;
	cout << endl << endl;

	Polynomial p6 = p1 / 2;
	cout << "Division of polynomial p1 with number '2':" << endl << p6 << endl << endl;
	return 0;
}