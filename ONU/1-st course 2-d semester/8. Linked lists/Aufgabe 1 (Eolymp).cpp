#include <iostream>
using namespace std;

class ListNode {
public:
	int data; // �������� �������
	ListNode* next; // �������� �� �������� ������� 
	ListNode(int data) {
		this->data = data;
		next = nullptr;
	}; // �����������
};

class LinkedList {
public:
	ListNode *head, *tail;  // ��������� �� ������ � ���� ������
	LinkedList() : head(nullptr), tail(nullptr) {}; // �����������
	bool Empty(); // �������� �� ������ �������
	void addFirst(int val); // ������ val �� ������� ������
	void addLast(int val); // ������ val � ����� ������
	bool removeFirst(); // �������� ������ ������� ������, ��������� true ���� ��������� ������� ������
	bool removeLast(); // �������� ������� ������� ������, ��������� true ���� ��������� ������� ������
	int size(); // ��������� ����� ������
	void Print(); // ������� �������� ������ � ������ �����
};

void LinkedList::Print() {
	ListNode* tmp = head;
	while (tmp != nullptr) {
		cout << tmp->data << " "; //������� �������� ���� ��� (� ������ �� �������������), ����� ���������
		tmp = tmp->next;
	}
	cout << endl;
}

int LinkedList::size(){
	if (Empty()) {
		return 0;
	}
	if (head == tail) {
		return 1;
	}
	else {
		int k = 1; //���������� � ��� ���� ���� ����
		ListNode* tmp = head; //��������� �� ������ ���� ������ ��� �������� ���������� ���� ���

		while (tmp->next != nullptr) {
			tmp = tmp->next;
			k++;
		} //��� �������� �� ������ ����. ���� ����������� ������� ���
		return k;
	}
}

bool LinkedList::removeLast(){
	if (Empty()) {
		return false;
	}
	if (head == tail) {
		delete tail;
		head = nullptr;
		tail = nullptr;
		return true;
	}
	else { //�� �������� �� ����� ���� ������ � ������� �� �������������� ��������
		//penultimate - ������������� (����.)
		ListNode* pointer_on_penultimate = head; //�� ��������� ��������� �� ������ ���� ������
		while (pointer_on_penultimate->next != tail) {
			pointer_on_penultimate = pointer_on_penultimate->next; //� ���� ����� �� ����������� ��������� �� ���� ����� ������ ��������������� ������ �� ��������������
		} // ����� ������� ����� ����� ����� ���� ��������� ����� ��������� �� ������������� �������

		ListNode* tmp = tail; //��������� ��������� �� ��������� ���� ������ (����� ��� ������ ���� ������� ��� ��� �������� ����)
		tail = pointer_on_penultimate; //��������� "�����, �����" ������ �� ���������� �������
		tail->next = nullptr;
		delete tmp; //������� ��������� ���� ������, ������� ��� �� �����
		return true;
	}
}

bool LinkedList::removeFirst() {
	if (Empty()) {
		return false;
	}
	if (head == tail) {
		delete head;
		head = nullptr;
		tail = nullptr;
		return true;
	}
	else {
		ListNode* tmp = head;
		head = head->next; //Perestavili
		delete tmp;
		return true;
	}
}

void LinkedList::addLast(int val) {
	ListNode* tmp = new ListNode(val);
	if (Empty()) {
		head = tmp;
		tail = tmp;
	}
	else {
		tail->next = tmp;
		tail = tmp;
	}
}

void LinkedList::addFirst(int val) {
	ListNode* tmp = new ListNode(val);
	if (Empty()) {
		head = tmp;
		tail = tmp;
	}
	else {
		tmp->next = head;
		head = tmp;
	}
}

bool LinkedList::Empty() {
	if (head == nullptr) {
		return true;
	}
	else { return false; }
}

int main() {
	LinkedList list;
	list.addFirst(1);
	list.addLast(2);
	list.addLast(3);
	list.addLast(4);

	cout << list.size() << endl << endl;
	list.Print();
	//list.removeFirst();
	list.removeLast();
	cout << list.size() << " ";
	list.Print();
	return 0;
}