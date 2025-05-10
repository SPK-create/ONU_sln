#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	vector<int> v1;
	cout << "Type elements of vector below (if you want to stop, write '/end'):" << endl << endl;
	int n;
	while (cin >> n) {
		if (n != int("/end")) {
			v1.push_back(n);
		}
		else { break; }
	}

	//При помощи оператора []
	cout << "Elements in vector are:" << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl << endl;

	//При помощи метода at()
	cout << "Elements in vector are:" << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";
	}
	cout << endl << endl;

	cout << "Taking out last element of vector:" << endl;
	v1.pop_back();
	for (int i = 0; i < v1.size(); i++) {
		cout << v1.at(i) << " ";
	}
	cout << endl << endl;

	cout << "First element: " << v1.front() << endl;
	cout << "Last element: " << v1.back() << endl << endl;

	cout << "Sorted vector: " << endl;
	sort(v1.begin(), v1.end());
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl << endl;

	cout << "Current size: " << v1.size() << endl;
	cout << "Current capacity: " << v1.capacity() << endl << endl;

	int k = 0;
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] == 3) {
			k++;
		}
	}
	if (k == 0) {
		cout << "Number 3 is not in vector.";
	}
	else {
		cout << "Number 3 is in vector";
	}
	return 0;
}