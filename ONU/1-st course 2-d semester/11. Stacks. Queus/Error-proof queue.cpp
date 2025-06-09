#include <iostream>
using namespace std;

class Queue {
private:
    int x[101];
    int endQ;
public:
    Queue() {
        endQ = -1;
    }
    void push(int n) {
        x[endQ + 1] = n;
        endQ++;
        cout << "ok" << endl;
    }
    int pop() {
        int tmp = x[0];
        for (int i = 0; i < endQ; i++) {
            x[i] = x[i + 1];
        }
        endQ--;
        return tmp;
    }
    void front() {
        cout << x[0] << endl;
    }
    int size() {
        return endQ + 1;
    }
    void clear() {
        endQ = -1;
        cout << "ok" << endl;
    }
};

int main() {
    Queue stack;
    string s;
    while (cin >> s) {
        if (s == "exit") {
            cout << "bye";
            return 0;
        }
        else {
            if (s == "push") {
                int a;
                cin >> a;
                stack.push(a);
            }
            else {
                if (s == "front") {
                    if (stack.size() == 0) {
                        cout << "error" << endl;
                    }
                    else {
                        stack.front();
                    }
                }
                else {
                    if (s == "size") {
                        cout << stack.size() << endl;
                    }
                    else {
                        if (s == "clear") {
                            stack.clear();
                        }
                        else {
                            if (s == "pop") {
                                if (stack.size() == 0) {
                                    cout << "error" << endl;
                                }
                                else {
                                    cout << stack.pop() << endl;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}