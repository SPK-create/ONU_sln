struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {

		if (head == nullptr) {
			return nullptr;
		}

		ListNode* temp_curr = head;
		ListNode* fictive = new ListNode(0, head); //Фиктивный указатель (перед началом списка) для правильной работы алгоритма
		ListNode* temp_prev = fictive;

		while (temp_curr != nullptr) {
			if (temp_curr->val == val) {
				temp_prev->next = temp_curr->next;
				temp_curr = temp_prev->next;
			}
			else {
				temp_curr = temp_curr->next;
				temp_prev = temp_prev->next;
			}
		}
		
		ListNode* new_head = fictive->next;
		delete fictive;
		return new_head;

	}
};