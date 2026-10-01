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
    int getLen(ListNode* head){
        if(head==NULL) return 0;
        return  1 + getLen(head->next);
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || getLen(head)<k) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;  
        int cnt = 0;

        while(cnt<k){
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr= next;
            cnt++;
        }

        head->next = reverseKGroup(curr,k);
        return prev;
    }
};
