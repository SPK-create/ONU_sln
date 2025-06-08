#include <iostream>
#include <map>
using namespace std;

map<long long, long long> m;
long long n, p, q;


long long A(long long n) {
	if (m[n]) {
		return m[n];
	}
	else if (n == 0) { //По условию
		m[n] = 1;
		return 1;
	}
	else {
		m[n] = A(n / p) + A(n / q);
		return m[n];
	}
}

int main() {
	cin >> n >> p >> q;
	cout << A(n);
	return 0;
}