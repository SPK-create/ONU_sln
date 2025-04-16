#include <iostream>
using namespace std;

class ListNode {
public:
	int data; // значення вершини
	ListNode* next; // вказівник на наступну вершину 
	ListNode(int data) {
		this->data = data;
		next = nullptr;
	}; // конструктор
};

class LinkedList {
public:
	ListNode *head, *tail;  // вказівники на голову і хвіст списку
	LinkedList() : head(nullptr), tail(nullptr) {}; // конструктор
	bool Empty(); // перевірка чи список порожній
	void addFirst(int val); // додати val на початок списку
	void addLast(int val); // додати val в кінець списку
	bool removeFirst(); // видалити перший елемент списку, повернути true якщо видалення пройшло успішно
	bool removeLast(); // видалити останній елемент списку, повернути true якщо видалення пройшло успішно
	int size(); // повернути розмір списку
	void Print(); // вивести значення списку в одному рядку
};

void LinkedList::Print() {
	ListNode* tmp = head;
	while (tmp != nullptr) {
		cout << tmp->data << " "; //Выводит значения всех нод (с первой по предпоследнюю), кроме последней
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
		int k = 1; //Изначально у нас есть одна нода
		ListNode* tmp = head; //Ссылается на первую ноду списка для подсчёта количества всех нод

		while (tmp->next != nullptr) {
			tmp = tmp->next;
			k++;
		} //При переходе на каждую след. ноду увеличиваем счётчик нод
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
	else { //Мы проходим по циклу весь список и доходим до предпоследнего элемента
		//penultimate - предпоследний (англ.)
		ListNode* pointer_on_penultimate = head; //По умолчанию указывает на первую ноду списка
		while (pointer_on_penultimate->next != tail) {
			pointer_on_penultimate = pointer_on_penultimate->next; //В этом цикле мы передвигаем указатель по всем нодам списка последовательно вплоть до предпоследнего
		} // Таким образом после этого цикла этот указатель будет ссылаться на предпоследний элемент

		ListNode* tmp = tail; //Временный указатель на последнюю ноду списка (чтобы при помощи него удалить эту уже ненужную ноду)
		tail = pointer_on_penultimate; //Связываем "конец, хвост" списка на предыдущий элемент
		tail->next = nullptr;
		delete tmp; //Удаляем последнюю ноду списка, которая уже не нужна
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