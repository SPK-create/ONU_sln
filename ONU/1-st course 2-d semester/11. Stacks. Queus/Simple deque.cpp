#include <iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node* prev;
    Node(int val) : val(val), next(nullptr), prev(nullptr) {};
};

class Deck {
public:
    Node* head;
    Node* tail;
    int count = 0;
    Deck() {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
    void push_front(int n) {
        Node* new_node = new Node(n);
        new_node->next = head;
        if (head != nullptr) {
            head->prev = new_node;
        }
        head = new_node;
        if (!tail) {
            tail = head;
        }
        count++;
        cout << "ok" << endl;
    }
    void push_back(int n) {
        Node* new_node = new Node(n);
        new_node->prev = tail;
        if (tail != nullptr) {
            tail->next = new_node;
        }
        tail = new_node;
        if (!head) {
            head = tail;
        }
        count++;
        cout << "ok" << endl;
    }
    void pop_front() {
        cout << head->val << endl;
        Node* tmp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }
        delete tmp;
        count--;
    }
    void pop_back() {
        cout << tail->val << endl;
        Node* tmp = tail;
        tail = tail->prev;
        if (tail) {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        delete tmp;
        count--;
    }
    void front() { cout << head->val << endl; }
    void back() { cout << tail->val << endl; }
    void size() { cout << count << endl; }
    void clear() {
        while (head != nullptr) {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
        tail = nullptr;
        count = 0;
        cout << "ok" << endl;
    }
    void exit() { cout << "bye" << endl; }
};

int main() {
    Deck queue;
    string s;
    while (cin >> s) {
        if (s == "push_front") {
            int a;
            cin >> a;
            queue.push_front(a);
        }
        else if (s == "push_back") {
            int a;
            cin >> a;
            queue.push_back(a);
        }
        else if (s == "pop_front") {
            queue.pop_front();
        }
        else if (s == "pop_back") {
            queue.pop_back();
        }
        else if (s == "front") {
            queue.front();
        }
        else if (s == "back") {
            queue.back();
        }
        else if (s == "size") {
            queue.size();
        }
        else if (s == "clear") {
            queue.clear();
        }
        else if (s == "exit") {
            queue.exit();
            break;
        }
    }
    return 0;
}