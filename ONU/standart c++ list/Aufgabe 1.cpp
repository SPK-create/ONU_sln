#include <iostream>
#include <list>
using namespace std;

void printList(list<int>& list);
bool single_digit(const int& value);

int main() {
	list<int> my_list;

	for (int i = 0; i < 5; i++) {
		my_list.push_back(i);
	}
	cout << "Created my_list:" << endl;
	printList(my_list);

	for (int i = 0; i < 3; i++) {
		my_list.push_front(5 + i);
	}
	cout << "Added 7, 6, 5 at front:" << endl;
	printList(my_list);

	my_list.sort();
	cout << "Sorted my_list:" << endl;
	printList(my_list);

	my_list.pop_front();
	cout << "Deleted first element of sorted my_list:" << endl;
	cout << "New first element of my_list: " << *(my_list.begin()) << endl << endl;

	my_list.pop_back();
	cout << "Deleted last element of sorted my_list:" << endl;
	cout << "New last element of my_list: " << my_list.back() << endl << endl;

	cout << "Size of my_list: " << my_list.size() << endl << endl;

	my_list.remove(my_list.size());
	cout << "my_list without elements, that equals to the number of size:" << endl;
	printList(my_list);

	my_list.push_back(26);
	my_list.push_back(14);
	my_list.push_back(250);
	cout << "Added some extra numbers for example: " << endl;
	printList(my_list);

	my_list.remove_if(single_digit);
	cout << "my_list without all numbers, whose last digit bigger than 4:" << endl;
	printList(my_list);

	return 0;
}

void printList(list<int>& list) {
	for (std::list<int>::iterator iter = list.begin(); iter != list.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl << endl;
}

bool single_digit(const int& value) { return (value%10 > 4); } //Проверяет ли последняя цифра числа больше 4