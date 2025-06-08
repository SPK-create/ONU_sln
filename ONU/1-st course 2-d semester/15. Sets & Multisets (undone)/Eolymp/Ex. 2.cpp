// Первая строка содержит количество чисел n (1≤n≤10^6).
// Во второй строке заданы n чисел, каждое из которых по модулю не превышает 2*10^9
//Выведите количество различных чисел среди заданных.
#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	cin >> n;
	set<int> s;
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		s.insert(k);
	}
	cout << s.size();
	return 0;
}