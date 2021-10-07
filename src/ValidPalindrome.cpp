#include "ValidPalindrome.h"
#include <iostream>
using namespace std;

/*
mapping failure,
TODO: good lesson here, a failed algo always gonna suck
bool validPalindrome(string s) {
    int c = 0;
    int letter[200];
    for (int i=0; i < 200; i++){
        letter[i] = 0;
    }

    for (char l: s) {
        letter[(int) l]++;
    }
    int c_1 = 0;
    int c_1_index = 0;
    for (int i = 0; i < 200; i++) {
        if (letter[i] % 2 != 0) {
            c++;
        }
        if (letter[i] == 1) {
            c_1 += 1;
            c_1_index = i;
        }
    }
    cout << endl;
    cout << "c is: " << c << endl;
    bool clear = false;
    if (c == 1){
        string s_copy = s;
        string s_copy2 = s;
        s_copy.erase(s_copy.size()-1, 1);
        s_copy2.erase(0, 1);
        cout << "string copy 1 is: " << s_copy << endl;
        int count1 = 0;
        int count2 = 0;
        for (int i = 0; i < s_copy.size() / 2 ; i+= 1){
            cout << s_copy[i] << " " << s_copy[s_copy.size() - i - 1] << endl;
            if (s_copy[i] != s_copy[s_copy.size() - i - 1]) {
                cout << "case 1" << endl;
                count1 ++;
            }
        }
        cout << "count1 is: " << count1 << endl;
        cout << "string copy 2 is: " << s_copy2 << endl;
        for (int i = 0; i < s_copy2.size() / 2; i += 1) {
            if (s_copy2[i] != s_copy2[s_copy2.size() - i - 1]) {
                cout << "case 2" << endl;
                count2 ++;
            }
        }
        cout << "count2 is: " << count2 << endl;
        if ((count1 == 0 || count2 == 0)){
            return true;
        }
    }
    if (c > 2){
        return false;
    }
    cout << "c1 is: " << c_1 << endl;

    if (c_1 == 1 && c <= 2){
        int found = s.find((char) c_1_index);
        cout << "find is: " << found << endl;
        s.erase(found, 1);
    }
    else if (c_1 == 2 && c <= 2){
        int found = s.find((char) c_1_index);
        cout << "find is: " << found << endl;
        s.erase(found, 1);
    }
    cout << "new string is: " << s << endl;


    for (int i = 0; i < s.size(); i+= 1){
        if (s[i] != s[s.size() - i - 1])
            return false;
    }
    return true;
}
 */

bool validPalindrome(string s, int l, int r, int count){
    if (count == 2){
        return false;
    }
    else if(l == r){
        return true;
    }

    cout << "l and r are: " << s[l] << s[r] << endl;
    while (l < r){
        if (s[l] == s[r]) {
            l += 1;
            r -= 1;
        }
        else {
            count += 1;
            return validPalindrome(s, l + 1, r, count) ||
                   validPalindrome(s, l, r - 1, count);
        }
    }
    return true;

}
bool validPalindrome_YX(string s){
    //Recursive
    return validPalindrome(s, 0, s.size() - 1, 0);
}

bool validPalindrome_YW(string s){
    //Iterative
    //TODO: Yihan's code here
}