#include <iostream>
#include <set>
#include <vector>
#include <string>
using namespace std;

//Ex. 1 - Данo слово. Правда ли, что оно не содержит повторяющихся букв?
bool NonRepeatingLetters(string word) {
	set<char> s(word.begin(), word.end());

	if (s.size() == word.size()) {
		return true;
	}
	else {
		return false;
	}
} 

//Ex. 2 - Дан текст, содержащий цифры(isdigit()).Сколько разных цифр содержит?
int AmountOfExclusiveDigits(string text) {
	set<int> digits;
	int number;
	for (int i = 0; i < text.size(); i++) {
		number = text[i] - 48;
		digits.insert(number);
	}

	return digits.size();
}

//Ex. 3 - Дан vector из 10 случайных натуральных чисел от 1 до 100. Вывести те из его элементов, которые представлены в виде суммы кубов натуральных чисел.
void OnlySumOfCubicNumbers(vector<int>& v) {
	set<int> cubic_numbers = { 1, 8, 9, 27, 28, 35, 36, 64, 65, 72, 73, 91, 99 }; //5^3 = 125, but numbers in vector cant be higher then 100

	vector<int>::iterator iter = v.begin();

	for (v.begin(); iter != v.end(); iter++) {
		int number = *iter;

		if (cubic_numbers.find(number) != cubic_numbers.end()) {
			cout << number << ", ";
		}
	}
	return;
}

//Ex. 4 - Дан vector натуральных чисел длины n. Удалить те из них, являющиеся числами Фибоначчи.
set<int> CreateSetFibonacciNumbers(int n) {
	set<int> fibonacci_numbers{ 0, 1 };

	int a = 0, b = 1;
	while (a + b < n) {
		int next = a + b;
		fibonacci_numbers.insert(next);
		a = b;
		b = next;
	}

	return fibonacci_numbers;
}
void DeleteAllFibonacciNumbersInVector(vector<int>& v) {
	if (!v.empty()) {
		int max_value = v.front(); //Первое значение вектора

		//Поиск макс. элемента в векторе
		vector<int>::iterator iter = v.begin();
		for (v.begin(); iter < v.end(); iter++) {
			if (*iter > max_value) {
				max_value = *iter;
			}
		}
		set<int> set_fibonacci = CreateSetFibonacciNumbers(max_value);

		iter = v.begin();
		while (iter != v.end()) {
			if (set_fibonacci.count(*iter)) {
				iter = v.erase(iter); //возвращает итератор на следующий элемент
			}
			else {
				iter++;
			}
		}
	}
}

int main() {
	//Ex. 1
	string word;
	cout << "Ex. 1:" << endl;
	cout << "Inputet word will be checked if repeating letters are in him" << endl;
	cin >> word;
	NonRepeatingLetters(word) ? cout << "No repeating letters" : cout << "In word are some repeating letters";
	cout << endl << endl;

	//Ex. 2
	string text;
	cout << "Ex. 2:" << endl;
	cout << "Type any combination of digits an we will see how many different digits there are" << endl;
	cin >> text;
	cout << "There are " << AmountOfExclusiveDigits(text) << " different digits" << endl << endl;

	//Ex. 3
	vector<int> vector_1_100;
	cout << "Ex. 3:" << endl;
	cout << "Type 10 random whole numbers from 1 to 100 and we will find numbers that we can represent by sum of cubic numbers" << endl;
	int* number_ptr = new int;
	for (int i = 0; i < 10; i++) {
		cin >> *number_ptr;
		vector_1_100.push_back(*number_ptr);
	}
	delete number_ptr;
	cout << "Numbers that we can represent by sum of cubic are: ";
	OnlySumOfCubicNumbers(vector_1_100);
	cout << endl << endl;

	//Ex. 4
	vector<int> vector_fibonacci;
	int n;
	cout << "Ex. 4:" << endl;
	cout << "Given a vector of natural numbers of length n (first number). Numbers that are Fibonacci numbers will be removed" << endl;
	cout << "Type 'n' (length of vector): ";
	cin >> n;
	cout << endl;
	cout << "Type whole numbers for vector: ";
	int num;
	for (int i = 0; i < n; i++) {
		cin >> num;
		vector_fibonacci.push_back(num);
	}
	cout << endl;
	cout << "Given vector is: ";
	vector<int>::iterator iter = vector_fibonacci.begin();
	for (vector_fibonacci.begin(); iter < vector_fibonacci.end(); iter++) {
		cout << *iter << ", ";
	}
	cout << endl;
	cout << "Same vector without Fibonacci numbers: ";
	DeleteAllFibonacciNumbersInVector(vector_fibonacci);
	iter = vector_fibonacci.begin();
	for (vector_fibonacci.begin(); iter < vector_fibonacci.end(); iter++) {
		cout << *iter << ", ";
	}
	cout << endl << endl;

	//Ex. 5
	string text_str, whole_text;
	set<char> s1, s2;
	cout << "Ex. 5:" << endl;
	cout << "Type any text below (to end typing, type '/end' in new line):" << endl;

	while (std::getline(cin, text_str)) {
		if (text_str != "/end") {
			whole_text += text_str + '\n'; //сохраняем каждую строку с переводом строки
		}
		else {
			break;
		}
	}

	for (int i = 0; i < whole_text.size(); i++) {
		if (s1.find(whole_text[i]) != s1.end()) s2.insert(whole_text[i]);
		else s1.insert(whole_text[i]);
	}

	s2.erase('\n');
	s2.erase(' ');

	cout << endl;
	cout << "Characters that occur in text at least twice: ";

	set<char>::iterator iter_s2_char = s2.begin();
	for (iter_s2_char; iter_s2_char != s2.end(); iter_s2_char++) {
		cout << *iter_s2_char << ", ";
	}

	cout << endl << endl;

	//Ex. 6
	int chislo;
	cout << "Type the number: ";
	cin >> chislo;
	cout << endl;

	cout << "All representations of number as a product of two natural numbers, if the symmetric representations a x b and b x a are considered:" << endl;

	//a) output a*b and b*a
	cout << "a) different:" << endl;
	for (int i = 1; i <= chislo; i++) {
		if ((chislo % i) == 0) {
			cout << i << "x" << chislo / i << " = " << chislo << endl;
		}
	}

	cout << endl << endl;

	//b) output only a*b or b*a
	cout << "b) the same (i.e., only one can be derived from two symmetric ones):" << endl;

	for (int i = 1; i <= sqrt(chislo); i++) {
		if ((chislo % i) == 0) {
			cout << i << "x" << chislo / i << " = " << chislo << endl;
		}
	}

	return 0;
}