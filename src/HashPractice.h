//
// Created by Ye Xu on 1/4/22.
//

#ifndef LEETCODEGRIND_HASHPRACTICE_H
#define LEETCODEGRIND_HASHPRACTICE_H
#include <map>
using namespace std;

//TODO: in C++, ordered map has an insert time of log n, since it is managed as a RB tree
//TODO: While in the same time the unordered version has a time of O(1) which is the same as a hash table
//TODO: though notice one thing that, the hash function is not defined, thus you will need to work that out on your own.

class HashPractice {
public:
    string createHash(string word);
    vector<vector<string>> groupAnagrams(vector<string>& strs);

};


#endif //LEETCODEGRIND_HASHPRACTICE_H
