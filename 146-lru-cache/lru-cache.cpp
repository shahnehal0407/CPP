class LRUCache {
public:

    unordered_map<int,int>cache;
    vector<int>recent;
    int c;
    LRUCache(int capacity) {
        c=capacity;
        
    }
    
    int get(int key) {
        if(cache.find(key)==cache.end())return -1;
        recent.erase(find(recent.begin(),recent.end(),key));
        recent.insert(recent.begin(),key);
        return cache[key];

        
    }
    
    void put(int key, int value) {
        
        if(cache.find(key)!=cache.end()){recent.erase(find(recent.begin(),recent.end(),key));}
        else if(recent.size()==c){
            int a= recent.back();
            recent.pop_back();
            cache.erase(a);
            
        }
        recent.insert(recent.begin(),key);
        cache[key]=value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */