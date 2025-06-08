#include <iostream>
#include <map>
using namespace std;

int main() {
	int n; //Amount of answers of 2 systems
	cin >> n;

	map<string, int> m1, m2;
	string answer;

	for (int i = 0; i < n; i++) {
		cin >> answer;
		m1[answer]++;
	}
	for (int i = 0; i < n; i++) {
		cin >> answer;
		m2[answer]++;
	}

	map<string, int>::iterator iter1 = m1.begin();
	map<string, int>::iterator iter2 = m2.begin();
	int sum_of_equal_answers = 0;

	//ѕровер€ем относительно 1-го мапа, т.к. если есть элементы во втором, которых нет в первом - нет общего совпадени€
	for (iter1; iter1 != m1.end(); iter1++) {
		string answer_tmp = iter1->first;
		int min_amount = iter1->second;

		iter2 = m2.find(answer_tmp);
		if (iter2 != m2.end()) {
			if (min_amount > iter2->second) {
				min_amount = iter2->second;
			}
		}
		else {
			min_amount = 0; //“. к. нет совпадений
		}
		sum_of_equal_answers += min_amount;
	}

	cout << sum_of_equal_answers;

	return 0;
}

//For debug
	/*cout << "Map 1:" << endl;
	for (auto e : m1) {
		cout << e.first << " " << e.second << "; ";
	}
	cout << endl << endl;
	cout << "Map 2:" << endl;
	for (auto e : m2) {
		cout << e.first << " " << e.second << "; ";
	}*/