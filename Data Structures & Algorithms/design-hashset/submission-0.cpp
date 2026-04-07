class MyHashSet {
    static const int SIZE = 1000;
    vector<list<int>>tables;

    int getSlot(int key) {
        return key % SIZE;
    }
public:
    MyHashSet() {
        tables.resize(SIZE);
    }
    
    void add(int key) {
        int slot = getSlot(key);
        for(auto &val:tables[slot]) {
            if(val==key) return;
        }
        tables[slot].push_back(key);
    }
    
    void remove(int key) {
        int slot = getSlot(key);
        tables[slot].remove(key);
    }
    
    bool contains(int key) {
        int slot = getSlot(key);
        for(auto &val:tables[slot]) {
            if(val==key) return true;
        }
        return false;
    }
};