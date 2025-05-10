#include <iostream>
#include <stack>
using namespace std;

/*
Example via analysing the string
int main() {
	string str;
	cin >> str;

	int count_left = 0; //Amount of '(' brackets
	int count_right = 0; //Amount of ')' brackets
	int necessary = 0; //Amount of '(' brackets in string

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			count_left++;
		}
		if (str[i] == ')') {
			count_right++;
			if (count_left == 0) {
				necessary++;
			}
			else { count_left--; }
		}
	}

	cout << necessary + count_left; //count_Left is remainder of brackets without pair
	return 0;
}
*/

/*
Example via stack 
int main() {
	stack<char> s;
	string str;
	cin >> str;

	int necessary = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
		}
		else { //str[i] = ')'
			if (s.size() == 0) {
				necessary++;
			}
			else {
				s.pop();
			}
		}
	}

	cout << necessary + s.size(); //s.size() is a remainder of '(' brackets without pair
	return 0;
}
*/

int main() { return 0; }