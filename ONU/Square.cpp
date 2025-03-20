#include <iostream>
using namespace std;

class Square {
private: 
	int a, perimeter, area;
public: 
	Square(int a=0): a(a) {}

	int getPerimeter() {
		return 4 * a;
	}
	int getArea() {
		return a * a;
	}
};

int main() {
	int a;
	while (cin >> a) {
		Square s(a);
		cout << s.getPerimeter() << " " << s.getArea() << endl;
	}
	return 0;
}