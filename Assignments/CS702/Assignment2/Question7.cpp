/*
Qns 7. Median of Two Sorted Arrays. Given two sorted arrays, nums1 and nums2, of size
m and n, return the median of the two sorted arrays. The overall runtime complexity should
be O(log (m+n)).
Test Cases:
1. Input: nums1 = [1,3], nums2 = [2]
Output: 2.0
2. Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.5
*/

#include<bits/stdc++.h>
using namespace std;

double findMedian(vector<int>& nums1, vector<int>& nums2){
    if(nums1.size() > nums2.size()) return findMedian(nums2, nums1);
    // we need it so that first array is smaller than second array

    int m = nums1.size();
    int n = nums2.size();

    int left = 0, right = m;
    // from 0 to first nums legth
    while(left<=right){
        int cut1 = (left+right)/2;  // cut position in nums1
        int cut2 = (m+n+1)/2 - cut1;    // cut position in nums2
        // total length - cut position from first array


        // edge cases for cuts at boundaries
        int maxleft1 = (cut1 == 0) ? INT_MIN : nums1[cut1-1];
        int maxleft2 = (cut2 == 0) ? INT_MIN : nums2[cut2-1];

        int minright1 = (cut1 == m) ? INT_MAX : nums1[cut1];
        int minright2 = (cut2 == n) ? INT_MIN : nums2[cut2];

        if(maxleft1 <= minright2 && maxleft2 <= minright1){
            // perfect partition
            if((m+n)%2==0){
                // even
                return (max(maxleft1,maxleft2) + min(minright1,minright2))/2.0;
            }else{
                // odd
                return max(maxleft1,maxleft2);
            }
        }else if(maxleft1 > minright2){
            // adjust search space
            // we are too far right in nums1
            right = cut1 - 1;
        }else{
            // were too far left in nums1
            left = cut1 + 1;
        }
    }
    // if control reaches here, it did not find any solution.
    return 0.0;
}

int main(){
    vector<int> nums1 = {1,2,3};
    vector<int> nums2 = {4,5,6};

}