#include <iostream>
#include <vector>
using namespace std;

int answ[2] {};
template <typename T> void SelectionSort(vector<T>&);
template <typename T> void SelectionSort(T*, const int);


int main() {
	//Example 1:
	vector<int> vector;
	vector.push_back(10);
	vector.push_back(22);
	vector.push_back(5);
	vector.push_back(7);
	vector.push_back(0);
	SelectionSort(vector);
	cout << "Example 1:" << endl;
	for (int i = 0; i < vector.size(); i++) {
		cout << vector[i] << " ";
	}
	cout << endl;
	cout << "Permutations: " << answ[0] << endl;
	cout << "Comparisons: " << answ[1];

	cout << endl << endl;

	//Example 2:
	cout << "Example 2:" << endl;
	float array[5] = { -7, 10, 0, 24.2, 5.3 };
	SelectionSort(array, 5);
	for (int i = 0; i < 5; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	cout << "Permutations: " << answ[0] << endl;
	cout << "Comparisons: " << answ[1];
	return 0;
}

template <typename T> void SelectionSort(vector<T>& v) {
	int size = v.size();
	if (size == 0) {
		cout << "You tried to sort an empty vector!";
		return;
	}

	if (size == 1) {
		cout << "You tried to sort an unity-vector!";
		return;
	}

	int permutations = 0;
	int comparisons = 0;

	for (int i = 0; i < (size - 1); i++) {
		int min = i; //Индекс минимального знач. (по умолч. первый элем. послед-ти)
		for (int j = i + 1; j < size; j++) { //Проходимся по всему вектору в поисках минимального знач. и если находим, переставляем его местами последовательно
			comparisons++;
			if (v[j] < v[i]) {
				T tmp = v[i];
				v[i] = v[j];
				v[j] = tmp;
				permutations++;
			}
		}
	}

	answ[0] = permutations;
	answ[1] = comparisons;

	return;
}

template <typename T> void SelectionSort(T* arr, const int size) {
	if (size == 0) {
		cout << "You tried to sort an empty array!";
		return;
	}

	if (size == 1) {
		cout << "You tried to sort an unity-array!";
		return;
	}

	int permutations = 0;
	int comparisons = 0;

	for (int i = 0; i < (size - 1); i++) {
		int min = i; //Индекс минимального знач. (по умолч. первый элем. послед-ти)
		for (int j = i + 1; j < size; j++) { //Проходимся по всему вектору в поисках минимального знач. и если находим, переставляем его местами последовательно
			comparisons++;
			if (arr[j] < arr[i]) {
				T tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
				permutations++;
			}
		}
	}

	answ[0] = permutations;
	answ[1] = comparisons;

	return;
}