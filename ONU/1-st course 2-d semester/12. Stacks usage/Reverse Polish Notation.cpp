#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int toINT(string&);
void calculate(const string&, stack<int>&);

int main() {
	stack<int> numbers;
	vector<char> operands;

	string str;

	while (cin >> str) {
		if (str == "+" || str == "-" || str == "*" || str == "/") {
			//cout << "Operand" << endl;
			calculate(str, numbers);
		}
		else {
			//cout << "Number" << endl;
			//Запишем число в стек, преобразуя из формата строки в целое число
			//cout << toINT(str) << endl;

			int number = toINT(str);
			numbers.push(number);

		}
	}

	cout << numbers.top();

	/*while (!numbers.empty()) {
		cout << numbers.top() << endl;
		numbers.pop();
	}*/

	return 0;

}

int toINT(string& s) {
	int length = s.size();
	int number = 0;
	for (int i = 0; i < s.size(); i++) { //Example: 158 = 1*10^2 + 5*10^1 + 8*10^0
		int digit = s[i] - '0'; //Перевод из строки в целое число, не изменяя цифру
		for (int j = 0; j < (length - 1); j++) {
			digit *= 10;
		}
		length--;
		number += digit;
	}
	return number;
}

void calculate(const string& str, stack<int>& numbers) {

	if (numbers.size() > 1) {
		int b = numbers.top();
		numbers.pop();
		int a = numbers.top();
		numbers.pop();

		if (str == "+") {
			numbers.push(a + b);
		}
		if (str == "-") {
			numbers.push(a - b);
		}
		if (str == "*") {
			numbers.push(a * b);
		}
		if (str == "/") {
			numbers.push(a / b);
		}
	}
	else {
		cout << "Operation with only one number is not declared!" << endl;
	}

	return;
}