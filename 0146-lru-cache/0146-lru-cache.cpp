class LRUCache {
public:
typedef pair<int,int> p;
// Here we will use doubly linked as it has an erase operation in constant time if we know the node adress and so to get the node address in constant time we will use a unordered map . so these two combined will provide constant time acess and delete :)
// list is stl for doubly linked list
    list<p> dll;
    unordered_map<int, list<p> :: iterator> mp;
// syntax to declare an iterator -> data_type :: iterator  iterator name
    int capacity;
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end())
            return -1;
        int value = mp[key]->second;
        dll.erase(mp[key]);
        dll.push_front({key, value});
        mp[key] = dll.begin();
        return value;
           
    }
    
    void put(int key, int value) {
        // element does not exist
        if(mp.find(key) == mp.end())
        { 
            // if size is full then we pop LRU i.e back element and also erase it from map
            if(mp.size() == capacity)
            {
                mp.erase(dll.back().first);
                dll.pop_back();
            }
            // pushing element at front and also putting it in map   
            dll.push_front({key, value});
            mp[key] = dll.begin();
        }
        // element exist
        else
        {
            // remove it from its posi and put it at front
            dll.erase(mp[key]);
            dll.push_front({key, value});
            mp[key] = dll.begin();
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */