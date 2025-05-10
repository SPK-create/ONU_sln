#include <iostream>
#include <stack>
using namespace std;

bool opened(char&);
bool true_pair(char&, char&);

int main() {
	string str;
	stack<char> stack;
	cin >> str;

	/*for (int i = 0; i < str.size(); i++) {
		cout << opened(str[i]) << endl;
	}*/

	//ASCII(dec): '(' = 40; ')' = 41; '[' = 91; ']' = 93; '{' = 123; '}' = 125

	int insertions = 0;

	for (int i = 0; i < str.size(); i++) {
		if (opened(str[i])) {
			stack.push(str[i]);
		}
		else {
			if (!stack.empty() && true_pair(stack.top(), str[i])) { //Если стек не пуст и закрывающая скобка подходит открывающей
				stack.pop();
			}
			else {
				insertions++;
				if (!stack.empty()) stack.pop();  // Если стек не пуст, удаляем верхнюю скобку, так как она не подходит
			}
		}
	}
	
	insertions += stack.size();//Размер стека это кол-во открытых скобок без пары, которые надо также удалить

	cout << insertions; 

	return 0;
}

bool opened(char& a) {
	return (a == '(' || a == '[' || a == '{'); //Является ли скобка в строке открытой?
}

bool true_pair(char& a, char& b) {
	return (a == '(' && b == ')') ||
		(a == '[' && b == ']') ||
		(a == '{' && b == '}'); //Будет ли закрытая скобка b из строки подходить открытой скобке из стека?
}

/*Example, why tests aer not accepted:

Input: {[)}
Expactation: 2
Output: 1
*/