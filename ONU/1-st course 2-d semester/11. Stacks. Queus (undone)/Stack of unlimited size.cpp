#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack {
private:
	vector<T> data;
public:
	Stack(const int& n) {
		data.push_back(n);
	}

	int pop() {
		int tmp = data.back();
		data.pop_back();
		return tmp;
	}

	int back() {
		return data.back();
	}

	int size() {
		return data.size();
	}

	void clear() {
		cout << "ok" << endl;
		data.clear();
	}
};

int main() {
	string command;

	while (cin >> command) {
		if (command == "push") {
			
		}
	}
}