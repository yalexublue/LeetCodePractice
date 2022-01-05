//
// Created by Ye Xu on 1/4/22.
//

#include "HashPractice.h"
#include <map>
#include <vector>

using namespace std;

string HashPractice::createHash(string word){
    vector<int> freq(26,0);
    for(auto w:word){
        freq[w-'a']++;
    }
    string currfreq;
    string finalHash = "000000000000000000000000000000000000000000000000000000000000000000000000000000";
    for(char c='a';c<='z';c++){
        int index = c-'a';
        int ithfreq = freq[index];

        if(ithfreq <10) currfreq=("00"+to_string(ithfreq));
        else if(ithfreq <100) currfreq=("0"+to_string(ithfreq));
        else currfreq=(to_string(ithfreq));
        int letterStart = index*3;
        finalHash[letterStart]=currfreq[0];
        finalHash[letterStart+1]=currfreq[1];
        finalHash[letterStart+2]=currfreq[2];
    }
    return finalHash;
}

vector<vector<string> > HashPractice::groupAnagrams(vector<string>& strs){
    vector<vector<string> > ans;
    unordered_map<string,vector<string> > mymap;

    for(auto word:strs){
        string currHash = createHash(word);
        if(mymap.find(currHash) != mymap.end()){
            mymap[currHash].push_back(word);
        }
        else{
            mymap[currHash] = {word};
        }
    }

    for(auto mypair:mymap){
        ans.push_back(mypair.second);
    }

    return ans;

}