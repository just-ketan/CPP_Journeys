/*
Qns 4. Given a sorted array consisting of only integers where every element appears exactly
twice, except for one element which appears exactly once. Return the single element that
occurs only once. The solution must run in O(log n) time and O(1) space.
Test Cases:
1. Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
2. Input: nums = [3,3,7,7,10,11,11]
Output: 10
*/

#include<bits/stdc++.h>
using namespace std;

// int bs(vector<int>& nums, int low, int high){
//     int mid = (low+high)/2;
// }
int main(){
    vector<int> nums = {1,1,2,3,3,4,4,8,8};

    // as nums is sorted
    // we can consider the pairs at once
    // if nums[mid] == nums[mid+1] or nums[mid-1] == nums[mid], means the pair is complete
    // we half the search space

    int left = 0, right = nums.size()-1;
    while (left < right){   // loop breaks when l >= right
        int mid = (left+right)/2;

        if(mid%2 == 1) mid--;   // keeping mid even for consistent checking

        if(nums[mid] == nums[mid+1]){
            // the pair is complete, we half the search space.
            left = mid+2;
        }else{
            // pair is broken, single element in left half (including mid)
            right = mid;
        }
    }

    cout << "single element" << nums[right] << endl;
    return 0;
    
}