/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* prev1 = NULL;
        ListNode* curr1 = head;

        for (int i = 1; i < left; i++) {
            prev1 = curr1;
            curr1 = curr1->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = curr1;
        for (int i = left; i <=right; i++) {
            ListNode* next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        if (prev1) {
            prev1->next = prev;
        }else {
            head=prev;
        }
        curr1->next = curr;
        return head;
    }
};