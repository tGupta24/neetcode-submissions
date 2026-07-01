class Node {
   public:
    int key;
    int value;

    Node *prev;
    Node *next;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
   public:
    Node* head  = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    int n;
    unordered_map<int,Node*>mp;
    LRUCache(int capacity) {
        head->next = tail;
        tail->prev = head; 
        n = capacity;
    }
    void deleteNode(Node *node){
    Node *p = node->prev;
    Node *n = node->next;

    p->next = n;
    n->prev = p;
}

void insertAtHead(Node *node){
    node->next = head->next;
    node->prev = head;

    head->next->prev = node;
    head->next = node;
}

    int get(int key) {
        // is it present
        if(!mp.count(key)) return -1;

        Node* address = mp[key];
        int val = mp[key]->value;

        deleteNode(address);
        insertAtHead(address);
        mp[key] = address;
        return val;
    }

    void put(int key, int value) {
        if(mp.count(key)){
            Node* address  = mp[key];
            mp.erase(key);
            deleteNode(address);
        }

        if(mp.size()==n){ // full
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node * newNode = new Node(key,value);
        mp[key] = newNode;
        insertAtHead(newNode);
    }
};
