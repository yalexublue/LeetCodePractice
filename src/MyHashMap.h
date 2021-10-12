#ifndef MyHashMap
#define MyHashMap
#include <iostream>
#include <list>

/*
class MyHashMap1 {
public:
    //vector<pair<int, int> > data;
    list< pair<int, int> > firstHash[50];
    MyHashMap1() {

    }

    void put(int key, int value) {
        int index = hashFunc(key);
        firstHash[index].push_back(pair<int, int>(key, value));
    }

    int get(int key) {
        int index = hashFunc(key);
        auto i = firstHash[index].begin();
        while (i != firstHash[index].end()){
            if (i->first == key)
                return i->second;
        }
    }

    void remove(int key) {
        int index = hashFunc(key);
        auto i = firstHash[index].begin();
        while (i != firstHash[index].end()){
            if (i->first == key){
                firstHash[index].erase(i);
            }
        }
    }
    int hashFunc(int key){
        return (7 * key + 3) % 10000007 % 50;
    }
};
 */

class MyHashMap_YX {
public:
    //vector<pair<int, int> > data;
    list< pair<int, int> > firstHash[50];
    MyHashMap_YX() {
    }

    void put(int key, int value) {
        int index = hashFunc(key);
        cout << "index is: " << index << endl;
        if (!firstHash[index].empty())
            firstHash[index].pop_back();
        firstHash[index].push_back(pair<int, int>(key, value));
    }

    int get(int key) {
        int index = hashFunc(key);
        auto i = firstHash[index].begin();
        return i->second;
    }

    void remove(int key) {
        int index = hashFunc(key);
        auto i = firstHash[index].begin();
        while (i != firstHash[index].end()){
            if (i->first == key){
                firstHash[index].erase(i);
            }
        }
    }
    int hashFunc(int key){
        return (7 * key + 3) % 10000007 % 50;
    }
};

class MyHashMap_YW {
    class MyHashMap {
    
private:
    vector<list<pair<int, int>>> arr;
    int hashfunction(int key){
        int ret = 3*key + 10;
        ret = ret % 10007;
        ret = ret %57;
        return ret;
    }
public:
    /** Initialize your data structure here. */
    MyHashMap(): arr(57) {}
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        
        int inx = hashfunction(key);
        list<pair<int, int>>& currList = arr[inx];
        bool isFound = false;
        for(auto i = currList.begin(); i != currList.end(); ++i){
            if(i->first == key){
                i->second = value;
                isFound = true;
            }
        }
      
        if(!isFound){
            currList.emplace_back(key,value);
                  
        }
       
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int inx = hashfunction(key);
        list<pair<int, int>>&  currList= arr[inx];
         for(auto i = currList.begin(); i != currList.end(); ++i){
            if(i->first == key){
                return i->second;
            }
            
        }
        return -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int inx = hashfunction(key);
        list<pair<int, int>>&  currList = arr[inx];
         for(auto i = currList.begin(); i != currList.end(); ++i){
            if(i->first == key){
                currList.erase(i);
                break;
            }
            
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
};

#endif
