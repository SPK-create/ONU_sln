#include <iostream>
#include <map>
using namespace std;

map<long long, unsigned int> m;

long long f(long long n) {
	if (m[n]) {
		return m[n];
	}
	else if (n <= 2){ //По условию
		m[n] = 1;
		return 1;
	}
	else if ((n % 2) == 1) {
		m[n] = (f(6 * n / 7) + f(2 * n / 3));
		return m[n];
	}
	else {
		m[n] = (f(n - 1) + f(n - 3));
		return m[n];
	}
}

int main() {
	long long n;
	cin >> n;
	cout << f(n);
	return 0;
}