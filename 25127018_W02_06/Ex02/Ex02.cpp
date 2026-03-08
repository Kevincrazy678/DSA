class MyHashSet {
private:
    int size;
   	vector<list<int>>res
    int hash(int key) {
        return key % size;
    }

public:
    MyHashSet() {
        size = 1009; 
        buckets.resize(size);
    }
    
    void add(int key) {
        int index = hash(key);
        for (int x : res[index]) {
            if (x == key) return;
        }
        res[index].push_back(key);
    }
    
    void remove(int key) {
        int index = hash(key);
        res[index].remove(key);
    }
    
    bool contains(int key) {
        int index = hash(key);
        for (int x : res[index]) {
            if (x == key) return true;
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
