/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>old_new;
        old_new[NULL] = NULL;

        Node* curr = head;

        while(curr!=NULL){
            Node* copy = new Node(curr->val);
            old_new[curr] = copy; 
            curr = curr->next;
        }

        curr = head;

        while(curr!=NULL){
            Node* copy = old_new[curr];
            copy->next = old_new[curr->next];
            copy->random = old_new[curr->random];
            curr = curr->next;
        }

        return old_new[head];

    }
};
