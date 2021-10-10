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
    //TODO: Yihan's code here.
};

#endif