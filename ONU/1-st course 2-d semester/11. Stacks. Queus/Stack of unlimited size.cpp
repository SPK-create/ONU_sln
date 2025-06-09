#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int val) {
        value = val;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;
public:
    Stack() {
        top = nullptr;
    }
    void push(int n) {
        Node* tmp = new Node(n);
        tmp->next = top;
        top = tmp;
    }

    int pop() {
        Node* tmp = top;
        top = top->next;
        int x = tmp->value;
        delete tmp;
        return x;
    }
    int back() {
        return top->value;
    }
    int size() {
        int x = 0;
        Node* tmp = top;
        while (tmp != nullptr) {
            x++;
            tmp = tmp->next;
        }
        return x;
    }
    void clear() {
        while (top != nullptr) {
            pop();
        }
    }
};


int main() {
    Stack stack;
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
                cout << "ok" << endl;
            }
            else {
                if (s == "back") {
                    if (stack.size() != 0) {
                        cout << stack.back() << endl;
                    }
                    else {
                        cout << "error" << endl;
                    }
                }

                else {
                    if (s == "size") {
                        cout << stack.size() << endl;
                    }
                    else {
                        if (s == "clear") {
                            stack.clear();
                            cout << "ok" << endl;
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