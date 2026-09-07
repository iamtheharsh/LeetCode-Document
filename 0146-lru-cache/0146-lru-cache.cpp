class LRUCache {
public:
    struct Node {
        Node* prev;
        Node* next;
        int key, val;

        Node(int k, int v) {
            key = k;
            val = v;
            prev = nullptr;
            next = nullptr;
        }
    };

    unordered_map<int, int> mpp;
    unordered_map<int, Node*> mpp2;
    int cap, capacity;
    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        cap = 0;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node) {
        Node* temp = head->next;
        node->next = temp;
        node->prev = head;
        head->next = node;
        temp->prev = node;
    }

    void removeNode(Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void moveToFront(Node* node) {
        removeNode(node);
        addNode(node);
    }

    int get(int key) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp2[key];
            moveToFront(node);
            return mpp[key];
        }
        return -1;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp2[key];
            mpp[key] = value;
            node->val = value;
            moveToFront(node);
            return;
        }
        if (cap == capacity) {
            Node* node = tail->prev;
            mpp.erase(node->key);
            mpp2.erase(node->key);
            removeNode(node);
            delete node;
            cap--;
        }
        Node* node = new Node(key, value);
        mpp[key] = value;
        mpp2[key] = node;
        addNode(node);
        cap++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */