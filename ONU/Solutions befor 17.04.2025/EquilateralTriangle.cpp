#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

class Triangle {
private:
	int n, perimeter, area;
public:
	Triangle(int n = 0) : n(n) {}

	int getPerimeter() {
		return 3 * n;
	}
	double getArea() {
		return (n * n * sqrt(3)) / 4;
	}
};

int main() {
	int n; //Длина стороны треуг.
	cin >> n;
	Triangle t(n);
	cout << fixed << setprecision(4) << t.getPerimeter() << " " << fixed << setprecision(4) << t.getArea();
	return 0;
}