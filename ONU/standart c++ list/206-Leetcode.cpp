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

		ListNode* temp_head = head;

		while (temp_head->next != nullptr) { //till to the last node
			temp_head = temp_head->next;
		}
		ListNode* tail = temp_head;
		ListNode* temp_tail = tail;
		temp_head = head;

		
	}

}; //////////////////???????????????????????????