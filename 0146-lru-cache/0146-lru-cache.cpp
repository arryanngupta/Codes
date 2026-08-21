
class Node{
public:
    int data;
    Node* prev;
    Node* next;
    Node(int x){
        data = x;
        prev = next = NULL;
    }
};

class LRUCache {
public:
    int cap;
    Node* head;
    Node* tail;
    unordered_map<int,Node*> mpp;
    unordered_map<Node*,int> mpp2;
    LRUCache(int capacity) {
        cap = capacity;
        head = NULL;
        tail = NULL;
    }

    void deleteTail(){
        Node* node = tail;
        tail = tail->prev;
        if(!tail) head = tail;
        else tail->next = NULL;
        mpp.erase(mpp2[node]);
        mpp2.erase(node);
        delete node;
    }

    void insertAtHead(int key,int value){
        Node* newNode = new Node(value);
        mpp[key] = newNode;
        mpp2[newNode] = key;
        newNode->next = head;
        if(head) head->prev = newNode;
        else tail = newNode;
        head = newNode;
    }

    void putAtHead(int key){
        Node* node = mpp[key];
        if(node==head) return ;
        if(node==tail){
            tail = tail->prev;
            tail->next = NULL;
        }
        if(node->prev) node->prev->next = node->next;
        if(node->next) node->next->prev = node->prev;
        node->next = head;
        head->prev = node;
        head = node;
    }
    
    int get(int key) {
        if(!mpp.count(key)) return -1;
        putAtHead(key);
        return mpp[key]->data;
    }
    
    void put(int key, int value) {
        if(mpp.count(key)){
            mpp[key]->data = value;
            putAtHead(key);
        }
        else{
            if(cap==0){
                deleteTail();
                cap++;
            }
            insertAtHead(key,value);
            cap--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */