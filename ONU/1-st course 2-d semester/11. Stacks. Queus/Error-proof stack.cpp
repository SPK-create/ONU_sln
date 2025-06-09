#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
	string str;
	stack<int> stack;

	while (cin >> str) {
		if (str == "push") {
			int n;
			cin >> n;
			stack.push(n);
			cout << "ok" << endl;
		}
		else if (str == "back") {
			if (stack.size() == 0) {
				cout << "error" << endl;
			}
			else {
				cout << stack.top() << endl;
			}
		}
		else if (str == "pop") {
			if (stack.size() == 0) {
				cout << "error" << endl;
			}
			else {
				cout << stack.top() << endl;
				stack.pop();
			}
		}
		else if (str == "size") {
			cout << stack.size() << endl;
		}
		else if (str == "clear") {
			cout << "ok" << endl;
			while (!stack.empty()) {
				stack.pop();
			}
		}
		else if (str == "exit") {
			cout << "bye";
			break;
		}
	}
}