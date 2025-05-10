#include <iostream>
#include <stack>
using namespace std;

int main() {
	string str;
	stack<char> s;

	cin >> str;

	int need_to_delete = 0;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			s.push(str[i]);
			//cout << "Added " << s.size() << endl;
		}
		else {
			if (s.size() == 0) {
				need_to_delete++;
				//cout << "Need to delete " << s.size() << endl;
			}
			else {
				s.pop();
				//cout << "Deleted " << s.size() << endl;
			}
		}
	}

	cout << need_to_delete + s.size();
	return 0;
}