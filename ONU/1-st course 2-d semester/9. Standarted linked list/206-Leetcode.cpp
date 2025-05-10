struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) { //Каждая следующая нода находится на 2 байта дальше, будем двигать на это число указатели

		if (head == nullptr) {
			return nullptr;
		}

		ListNode* tmp_head = head;
		ListNode* list_answ = new ListNode();

		while (tmp_head->next != nullptr) {
			tmp_head = tmp_head->next;
		} //Доходим до последней актуальной ноды списка

		ListNode* last = tmp_head;

		while (last != head) {
			list_answ->val = last->val;
			list_answ->next = new ListNode();
			list_answ = list_answ->next;
			delete tmp_head;

			ListNode* tmp_head = head;
			while (tmp_head->next != nullptr) {
				tmp_head = tmp_head->next;
			} //Доходим до последней актуальной ноды списка
			last = tmp_head;
		}
		
		list_answ->val = head->val;
		return list_answ;
	}

}; 