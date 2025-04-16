/*Реализовать класс вектор. Сделать функцию вычесления среднего значения вектора и функцию поиска минимального значения вектора*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<float> v;
	cout << "Type elements of vector below (if you want to stop, write '/end'):" << endl << endl;
	float n;
	while (cin >> n) {
		if (n != int("/end")) {
			v.push_back(n);
		}
		else { break; }
	}
	
	cout << endl << "Average value of vector = ";
	float average_value = 0.0;
	float sum_of_elements = 0.0;
	for (int i = 0; i < v.size(); i++) {
		sum_of_elements += v[i];
	}
	average_value = float(sum_of_elements / v.size());
	cout << average_value << endl << endl;

	cout << "Minimum value in vector = ";
	sort(v.begin(), v.end());
	cout << v[0];

	return 0;
}