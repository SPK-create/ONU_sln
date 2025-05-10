#include <iostream>
#include <vector>
using namespace std;

int answ[2]{};
template <typename T> int BubbleSort(vector<T>&);

int main() {
	vector<int> vector;
	int n, c;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> c;
		vector.push_back(c);
	}
	int answ = BubbleSort(vector);
	cout << answ;
	
	return 0;
}

template <typename T> int BubbleSort(vector<T>& v) {
	// ѕо условию задачи массив состоит из 1 элемента и больше
	// Ќадо вернуть кол-во перестановок во врем€ работы алгоритма
	int size = v.size();
	int true_position = 0; //ќтвечает за то, стоит ли элемент в правильном месте
	int permutations = 0; // ол-во перестановок во врем€ сортировки

	if (size == 1) {
		return 1;
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
		}
	}

	return permutations;
}