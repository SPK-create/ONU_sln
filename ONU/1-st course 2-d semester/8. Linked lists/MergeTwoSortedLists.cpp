#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* answ = new ListNode();
        ListNode* tmp_answ = answ;
        ListNode* tmp_list1 = list1;
        ListNode* tmp_list2 = list2;

        if (list1 == nullptr and list2 == nullptr) { //≈сли оба пустые
            return nullptr;
        }
        if (list1 == nullptr and list2 != nullptr) { //≈сли первый пустой, то заполн€ем в ответ второй
            while (tmp_list2 != nullptr) {
                tmp_answ->val = tmp_list2->val;
                tmp_list2->next == nullptr ? tmp_answ->next = nullptr : tmp_answ->next = new ListNode();
                tmp_answ = tmp_answ->next;
                tmp_list2 = tmp_list2->next;
            }

            return answ;
        }
        if (list1 != nullptr && list2 == nullptr) { //≈сли второй пустой, в ответ первый
            cout << "Second else if" << endl;
            while (tmp_list1 != nullptr) {
                tmp_answ->val = tmp_list1->val;
                tmp_list1->next == nullptr ? tmp_answ->next = nullptr : tmp_answ->next = new ListNode();
                tmp_answ = tmp_answ->next;
                tmp_list1 = tmp_list1->next;
            }
            return answ;
        }

        while (true) {
            if (tmp_list1->val >= tmp_list2->val) { //≈сли знач. ноды первого списка >= значени€ второго списка
                tmp_answ->val = tmp_list2->val;
                tmp_answ->next = new ListNode();
                tmp_answ = tmp_answ->next;
                if (tmp_list2->next != nullptr) { //ѕровер€ем достигли ли мы последней ноды второго списка
                    tmp_list2 = tmp_list2->next;
                }
                else {
                    //≈сли нельз€, то заполн€ем оставшиес€ ноды из первого списка и выходим из цикла
                    while (tmp_list1 != nullptr) {
                        tmp_answ->val = tmp_list1->val;
                        //≈сли мы достигли последней ноды первого списка, то в ответе ссылаемс€ также на нул. указатель
                        tmp_list1->next == nullptr ? tmp_answ->next = nullptr : tmp_answ->next = new ListNode();
                        tmp_answ = tmp_answ->next;
                        tmp_list1 = tmp_list1->next;
                    }
                    //tmp_answ = nullptr;
                    break;
                }
            }
            else if (tmp_list1->val <= tmp_list2->val) { //≈сли знач. ноды первого списка <= значени€ второго списка
                tmp_answ->val = tmp_list1->val;
                tmp_answ->next = new ListNode();
                tmp_answ = tmp_answ->next;
                // јналогично провер€ем достигли ли мы последней ноды первого списка
                if (tmp_list1->next != nullptr) {
                    tmp_list1 = tmp_list1->next;
                }
                else {
                    while (tmp_list2 != nullptr) {
                        tmp_answ->val = tmp_list2->val;
                        tmp_list2->next == nullptr ? tmp_answ->next = nullptr : tmp_answ->next = new ListNode();
                        tmp_answ = tmp_answ->next;
                        tmp_list2 = tmp_list2->next;
                    }
                    //tmp_answ = nullptr;
                    break;
                }

            }
        }
        return answ;
    }
};