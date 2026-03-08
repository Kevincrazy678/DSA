class MyHashSet {
private:
    std::vector<int> data;
    int capacity;
    const int empty = -1;
    const int del = -2;

public:
    MyHashSet() {
        capacity = 2*10e5;
        data.assign(capacity, empty);
    }
    
    void add(int key) {
        if (contains(key)) return;
        int h = key % capacity;
        while (data[h] != empty && data[h] != del) {
            h = (h + 1) % capacity;
        }
        data[h] = key;
    }
    
    void remove(int key) {
        int h = key % capacity;
        int start_index = h;
        
        while (data[h] != empty) {
            if (data[h] == key) {
                data[h] = del;
                return;
            }
            h = (h + 1) % capacity;
            if (h == start_index) return; 
        }
    }
    
    bool contains(int key) {
        int h = key % capacity;
        int start_index = h;
        
        while (data[h] != empty) {
            if (data[h] == key) {
                return true;
            }
            h = (h + 1) % capacity;
            if (h == start_index) return false; 
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
