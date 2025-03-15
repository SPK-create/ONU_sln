#include <iostream>
#include <iomanip>
using namespace std;

/*class Triangle {
private:
	float a1, a2, a3;
public:
	Triangle() : a1(0), a2(0), a3(0) {};
	void getSide(float x, float y, float z) {
		a1 = x;
		a2 = y;
		a3 = z;
	}
	void perimetr() {
		cout << fixed << setprecision(4) << (a1 + a2 + a3) << endl;
	}
};*/

class Rectangle {
private:
	long a1, a2;
public:
	Rectangle(long a1, long a2) : a1(a1), a2(a2) {}
	long perimetr() {
		return (a1 + a2) * 2;
	}
	long square() {
		return a1 * a2;
	}
};

int main() {
	//float a, b, c;
	/*while (cin >> a >> b >> c) {
		Triangle t1;
		t1.getSide(a, b, c);
		t1.perimetr();
	}*/
	long a, b;
	while (cin >> a >> b) {
		Rectangle r1(a, b);
		cout << r1.perimetr() << endl;
		cout << r1.square() << endl;
	}
	return 0;
}