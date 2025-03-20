#include <iostream>
using namespace std;

class Vector {
private:
	int x, y;
public:
	Vector() : x(0), y(0) {}
	Vector(const int x, const int y) : x(x), y(y) {}
	void Input() {
		cin >> x >> y;
	}
	void Out() {
		cout << x << " " << y << endl;
	}

	Vector& operator=(const Vector& v) {
		x = v.x;
		y = v.y;
		return *this;
	}

	Vector operator+(const Vector& v) {
		return Vector(x + v.x, y + v.y);
	}

	Vector operator-(const Vector& v) {
		return Vector(x - v.x, y - v.y);
	}

	Vector operator+=(const Vector& v) {
		x += v.x;
		y += v.y;
		return *this;
	}

	Vector operator-=(const Vector& v) {
		x -= v.x;
		y -= v.y;
		return *this;
	}

	int operator*(const Vector& v) {
		return ((x * v.x) + (y * v.y));
	}
};