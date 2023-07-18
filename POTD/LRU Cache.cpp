//----------------Brute Approach-----------------//

class LRUCache {
public:
    vector<pair<int,int>>v;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    int get(int key) {
        for(int i=0;i<v.size();i++){
            if(v[i].first==key){
                int val=v[i].second;
                pair<int,int>temp=v[i];
                v.erase(v.begin()+i);
                v.push_back(temp);
                return val;
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        for(int i=0;i<v.size();i++){
            if(v[i].first==key){
                v.erase(v.begin()+i);
                v.push_back({key,value});
                return;
            }
        }
        if(v.size()==n){
          v.erase(v.begin());
          v.push_back({key,value});
        }
        else{
            v.push_back({key,value});
        }
    }
};

//----------------Optimal Approach -----------------//

class LRUCache {
public:
    list<int>dll;
    map<int,pair<list<int>::iterator,int>>mp;
    int n;
    LRUCache(int capacity) {
        n=capacity;
    }
    
    void makeRecentUsed(int key){
        dll.erase(mp[key].first);
        dll.push_front(key);
        mp[key].first=dll.begin();
    }
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;
        makeRecentUsed(key);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            mp[key].second=value;
            makeRecentUsed(key);
        }
        else{
            dll.push_front(key);
            mp[key]={dll.begin(),value};
            n--;
        }
        if(n<0){
            int last_element=dll.back();
            mp.erase(last_element);
            dll.pop_back();
            n++;
        }
    }
};
