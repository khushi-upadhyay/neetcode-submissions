class MyHashSet {
public:
    vector<int> v;

    MyHashSet() {
    
    }

    void add(int key) {
        if (!contains(key)) {
            v.push_back(key);
        }
    }

    void remove(int key) {
        for (auto it = v.begin(); it != v.end(); it++) {
            if (*it == key) {
                v.erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        for (int x : v) {
            if (x == key) {
                return true;
            }
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