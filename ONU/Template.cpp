#include <iostream>
using namespace std;

template <typename T>
T findMin(const T& a, const T& b) {
	if (a > b) {
		return b;
	}
	else { return a; }
}

int main() {
	int a1 = 5, b1 = -3;
	float a2 = 8.12, b2 = 3.14;
	string a3 = "abc", b3 = "a";

	cout << findMin(a1, b1) << endl << endl;
	cout << findMin(a2, b2) << endl << endl;
	cout << findMin(a3, b3) << endl << endl;
	return 0;
}