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
			int k = head->val; //�����, ������� ���������� �� ������������� (���������� ����� �������� ������ ����)
			ListNode* answ = new ListNode(k); //� ������ ���� ���������� �������� ������ ���� ������
			ListNode* tmp_answ = answ; 
			
			head = head->next; //������� ��������� ������ �� ����. ����

			while (head != nullptr) {

				if (head->val != k){
					k = head->val; //����� �������� ��� ��������� �� �������������
					tmp_answ->next = new ListNode(k);

					tmp_answ = tmp_answ->next;
				}

				head = head->next; 
			}

			return answ;
		}
	}
};