class MyHashMap {
public:
vector<int> mn;
    MyHashMap() {
        mn.resize(1000001,-1);
    }
    
    void put(int key, int value) {
        mn[key]=value;
    }
    
    int get(int key) {
        return mn[key];
    }
    
    void remove(int key) {
        mn[key]=-1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */