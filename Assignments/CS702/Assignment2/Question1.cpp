/*
Qns 1. Given an array of nums with n objects colored red, white, or blue, sort them in place
so that objects of the same color are adjacent, with the colors in red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
Test Cases:
1. Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
2. Input: nums = [2,0,1]
Output: [0,1,2]
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    // sorting 0s,1s,2s is dutch flag algorithm
    // maintain low, mid, high
    vector<int> nums = {2,0,2,1,1,0};
    int size = nums.size();

    int low = 0, mid = 0, high = size-1;
    // low is boundary for 0
    // hight is starting boundary for 2
    // mid is curent nnumber in processing

    while(mid <= high){
        if(nums[mid] == 0){
            //swap arr[low] and arr[mid]
            // move both pointer forward
            int temp = nums[mid];
            nums[mid] = nums[low];
            nums[low] = temp;

            mid++;  // move mid forward
            low++;  // increase boundary for 0
        }
        else if(nums[mid] == 1){
            mid++;  // move mid forward
        }
        else{   // nums[mid] == 2
            // swap elements
            // decrement high (expanding right boundary towards left)
            // we dont increment mid as we need to examine in next pass
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;

            high--;
        }
    }

    // sorted array is:
    for(int i=0; i<size; i++){
        cout << nums[i] <<" ";
    }

    return 0;
}