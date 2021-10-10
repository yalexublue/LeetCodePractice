#include <iostream>
#include <vector>
#include "ValidPalindrome.h"
#include "MyHashMap.h"
#include "WkContest1.h"
#include <list>

using namespace std;



int main(){
    /*
    //validPalindrome check II
    string s = "BBCCCB";
    cout << "test for valid palindrome\n"; 
    cout << "YX result: " << validPalindrome_YX(s) << endl;
    cout << "YW reuslt: " << validPalindrome_YW(s) << endl;
     */

    //706. Design HashMap
    MyHashMap map;
    map.put(6000, 25);
    map.put(6000, 30);
    cout << map.get(6000) << endl;
    map.put(60000002, 40);
    cout << map.get(60000002);

    return 0;
}