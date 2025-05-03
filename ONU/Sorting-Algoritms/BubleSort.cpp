#include <iostream>
#include <vector>
using namespace std;

int answ[2] {};
template <typename T> void BubbleSort(vector<T>&);
template <typename T> void BubbleSort(T*, const int);

int main() {
	//Example 1:
	vector<float> vector;
	vector.push_back(10.3);
	vector.push_back(22.6);
	vector.push_back(5.1);
	vector.push_back(-7);
	vector.push_back(0);
	BubbleSort(vector);
	cout << "Example 1:" << endl;
	for (int i = 0; i < vector.size(); i++) {
		cout << vector[i] << " ";
	}
	cout << endl;
	cout << "Permutations: " << answ[0] << endl;
	cout << "Comparisons: " << answ[1] << endl;

	cout << endl << endl;

	cout << "Example 2:" << endl;
	float array[6] = { 0, -3.1, 5.2, 7.8, 7.3, 3.1 };
	BubbleSort(array, 6);
	for (int i = 0; i < 6; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
	cout << "Permutations: " << answ[0] << endl;
	cout << "Comparisons: " << answ[1] << endl;
	
	return 0;
}

template <typename T> void BubbleSort(vector<T>& v) {
	int size = v.size();
	int true_position = 0; //ќтвечает за то, стоит ли элемент в правильном месте
	int comparisons = 0; // ол-во сравнений во врем€ сортировки
	int permutations = 0; // ол-во перестановок во врем€ сортировки

	if (size == 0) {
		cout << "You tried to sort an empty vector!";
		return;
	}

	if (size == 1) {
		cout << "You tried to sort an unity vector!";
		return;
	}

	/* “.е. если во врем€ прохода по вектору мы сделаем хот€ бы одну перестановку элементов, чтобы переставить элементы в правильном пор€дке, то
	* эту переменную мы не будем увеличивать, т.к. элементы не сто€ли в правильных местах
	*  ол-во сравнений всегда будет на 1 меньше кол-ва элементов вектора
	*/

	while (true_position != (size - 1)) {
		true_position = 0;
		for (int i = 0; i < (v.size() - 1); i++) {
			if (v[i] > v[i + 1]) {
				T tmp = v[i];
				v[i] = v[i + 1];
				v[i + 1] = tmp;
				permutations++;
			}
			else { true_position++; }
			comparisons++;
		}
	}

	answ[0] = permutations;
	answ[1] = comparisons;

	return;
}

template <typename T> void BubbleSort(T* arr, const int size) {
	int true_position = 0; //ќтвечает за то, стоит ли элемент в правильном месте
	int comparisons = 0; // ол-во сравнений во врем€ сортировки
	int permutations = 0; // ол-во перестановок во врем€ сортировки

	if (size == 0) {
		cout << "You tried to sort an empty array!";
		return;
	}

	if (size == 1) {
		cout << "You tried to sort an unity-array!";
		return;
	}

	while (true_position != (size - 1)) {
		true_position = 0;
		for (int i = 0; i < (size - 1); i++) {
			if (arr[i] > arr[i + 1]) {
				T tmp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = tmp;
				permutations++;
			}
			else { true_position++; }
			comparisons++;
		}
	}

	answ[0] = permutations;
	answ[1] = comparisons;

	return;
}