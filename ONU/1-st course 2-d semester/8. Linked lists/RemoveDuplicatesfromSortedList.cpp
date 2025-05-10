struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == nullptr) {
			return nullptr;
		}
		else {
			int k = head->val; //Число, которое сравниваем на повторяемость (изначально равно значению первой ноды)
			ListNode* answ = new ListNode(k); //В первую ноду записываем значение первой ноды головы
			ListNode* tmp_answ = answ; 
			
			head = head->next; //Двигаем указатель головы на след. ноду

			while (head != nullptr) {

				if (head->val != k){
					k = head->val; //Новое значение для сравнения на повторяемость
					tmp_answ->next = new ListNode(k);

					tmp_answ = tmp_answ->next;
				}

				head = head->next; 
			}

			return answ;
		}
	}
};