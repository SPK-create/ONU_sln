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
			if (!stack.empty() && true_pair(stack.top(), str[i])) { //���� ���� �� ���� � ����������� ������ �������� �����������
				stack.pop();
			}
			else {
				insertions++;
				if (!stack.empty()) stack.pop();  // ���� ���� �� ����, ������� ������� ������, ��� ��� ��� �� ��������
			}
		}
	}
	
	insertions += stack.size();//������ ����� ��� ���-�� �������� ������ ��� ����, ������� ���� ����� �������

	cout << insertions; 

	return 0;
}

bool opened(char& a) {
	return (a == '(' || a == '[' || a == '{'); //�������� �� ������ � ������ ��������?
}

bool true_pair(char& a, char& b) {
	return (a == '(' && b == ')') ||
		(a == '[' && b == ']') ||
		(a == '{' && b == '}'); //����� �� �������� ������ b �� ������ ��������� �������� ������ �� �����?
}

/*Example, why tests aer not accepted:

Input: {[)}
Expactation: 2
Output: 1
*/