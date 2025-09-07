// Qns 3. Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
// Test Cases:
// 1. Input: nums = [3,2,3]
// Output: [3]
// 2. Input: nums = [1]
// Output: [1]
// 3. Input: nums = [1,2]
// Output: [1,2]


#include<bits/stdc++.h>
using namespace std;

int main(){
    // we can take frequency of all elements in a map
    // we can then check the values >= n/3

    map<int, int> mp;
    vector<int> nums = {2,3,2,32,4,4,435,3,2,2,1,23,2,3,3};

    for(int i=0 ;i <nums.size(); i++){
        mp[nums[i]]++;
    }

    vector<int> res;

    // for(auto& pair : mp){
    //     if(pair.second > nums.size()/3) res.push_back(pair.first);
    // }
    for(auto it = mp.begin(); it != mp.end(); it++){
        if(it->second > nums.size()/3){
            res.push_back(it->first);
        }
    }

    // print result
    for(int i=0; i<res.size(); i++) cout<< res[i] << " ";

    return 0;
}