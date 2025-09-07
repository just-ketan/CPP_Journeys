// Qns 5. Given an array of integers nums sorted in non-decreasing order, find the starting and
// ending position of a given target value. If the target is not found in the array, return [-1, -1].
// The algorithm must have an O(log n) runtime complexity.
// Test Cases:
// 1. Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
// 2. Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
// 3. Input: nums = [], target = 0
// Output: [-1,-1]


#include<bits/stdc++.h>
using namespace std;


int main(){

    vector<int> nums = {5,7,7,8,8,10};

    // now as the nums is sorted
    // we can do binary search, where we drop one halh in one iteration
    // we can treat indexes as boundaries
    // one pass to find left boundary
    // one pass to find right boundary
    // will work in 2*O(logN) --> asymptotically will run in O(lgN)

    if(nums.empty()){
        cout<<"[-1,-1]"<<endl;
        return 0;
    }

    int left = 0;
    int right = nums.size()-1;

    int key;
    cout<<"enter search key"<<endl;
    cin>>key;

    int first=-1,second=-1;
    //find left boundary
    while(left<=right){
        int mid = left + (right-left)/2;
        if(nums[mid] == key){
            first = mid;    //store
            right = mid-1;  // need to go left
        }else if(nums[mid] < key){
            left = mid+1;
            // we are away from number need to move forward
        }else{
            right = mid - 1;
            // we overshot the number, need to come back
        }
    }
    if(first == -1){    cout << "[-1,-1]"<<endl; return;}


    // reset pointers for right boundary search
    left = 0;
    right = nums.size()-1;

    // find right boundary
        while(left<=right){
        int mid = left + (right-left)/2;
        if(nums[mid] == key){
            second = mid;
            left = mid + 1;
        }else if(nums[mid] < key){
            left = mid+1;   // find index on right hand size
        }else{
            right = mid - 1;    // too small, shrink from right till mid-1
        }
    }


    cout<<"["<<first<<","<<second<<"]"<<endl;
    return 0;
}

