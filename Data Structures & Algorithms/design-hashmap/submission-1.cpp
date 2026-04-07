class LL {
public:
    int key, value;
    LL* next;
    LL(int k, int v): key(k), value(v), next(nullptr) {}
};

class MyHashMap {
    static const int SIZE = 1000;
    vector<LL*>tables;
    int getSlot(int key) {
        return key % SIZE;
    }
public:
    MyHashMap() {
        tables.resize(SIZE);
        for(auto &table:tables) {
            // dummy head for each slot
            table = new LL(0,0);
        }
    }
    
    void put(int key, int value) {
        int slot = getSlot(key);
        LL* node = tables[slot];
        while(node->next) {
            if(node->next->key==key) {
                node->next->value = value;
                return;
            }
            node = node->next;
        }
        // the key was not present
        node->next = new LL(key,value); 
    }
    
    int get(int key) {
        int slot = getSlot(key);
        LL* node = tables[slot];
        while(node->next) {
            if(node->next->key==key) return node->next->value;
            node = node->next;
        }
        return -1;
    }
    
    void remove(int key) {
        int slot = getSlot(key);
        LL* curr = tables[slot];

        while(curr->next) {
            if(curr->next->key==key) {
                LL* temp = curr->next;
                curr->next = temp->next;
                delete temp;
                return;
            }
            curr = curr->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */