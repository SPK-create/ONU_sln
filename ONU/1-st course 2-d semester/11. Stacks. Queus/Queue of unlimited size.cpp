#include <iostream>
#include <string>
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

class Queue {
private:
    Node* front;
    Node* back;
    int count;

public:
    Queue() {
        front = nullptr;
        back = nullptr;
        count = 0;
    }

    void push(int n) {
        Node* tmp = new Node(n);
        if (back) {
            back->next = tmp;
        }
        else {
            front = tmp;
        }
        back = tmp;
        count++;
        cout << "ok" << endl;
    }

    string pop() {
        if (front) {
            int val = front->value;
            Node* tmp = front;
            front = front->next;
            delete tmp;
            count--;
            if (front == nullptr) {
                back = nullptr;
            }
            return to_string(val);
        }
        return "error";
    }

    string getFront() {
        if (front) {
            return to_string(front->value);
        }
        return "error";
    }

    int size() {
        return count;
    }

    void clear() {
        while (front) {
            pop();
        }
        cout << "ok" << endl;
    }
};

int main() {
    Queue queue;
    string command;

    while (cin >> command) {
        if (command == "exit") {
            cout << "bye" << endl;
            break;
        }
        else if (command == "push") {
            int value;
            cin >> value;
            queue.push(value);
        }
        else if (command == "pop") {
            cout << queue.pop() << endl;
        }
        else if (command == "front") {
            cout << queue.getFront() << endl;
        }
        else if (command == "size") {
            cout << queue.size() << endl;
        }
        else if (command == "clear") {
            queue.clear();
        }
    }

    return 0;
}