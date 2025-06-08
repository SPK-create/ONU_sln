//Первая строка содержит количество тестов t(t≤50).
//Первая строка каждого теста содержит количество поездок n, совершённых Алисой по работе.
//Следующие n строк описывают сами поездки : i - ая строка содержит название города, 
//который Алиса посетила во время i - ой поездки.
#include <iostream>
#include <set>
using namespace std;

int main() {
	int t, n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		set<string> cities;
		string city;
		for (int j = 0; j < n; j++) {
			cin >> city;
			cities.insert(city);
		}
		cout << cities.size() << endl;
	}
	return 0;
}