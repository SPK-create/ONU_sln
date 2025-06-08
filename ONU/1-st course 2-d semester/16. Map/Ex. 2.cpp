#include <iostream>
#include <map>
using namespace std;

int main() {
	int n;
	cin >> n; //Кол-во слов

	map <string, int> m;
	string word;

	for (int i = 0; i < n; i++) {
		cin >> word;
		m[word]++; //Ключ - слово, при каждой встрече увеличивает кол-во встречаемых слов
	}

	int max_freq = (m.begin())->second;
	string max_word = (m.begin())->first;
	for (auto e : m) {
		if (e.second >= max_freq) {
			max_freq = e.second;
			max_word = e.first;
		}
	}
	cout << max_word << " " << m[max_word];
	return 0;
}