/*
Write a C program to find the largest and the second largest element in an array.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int len;
    cin >> len;

    vector<int> nums(len);
    for(int i=0; i<len; i++)    cin >> nums[i];

    int max1 = nums[0], max2 = nums[0];
    for(int x : nums){
        if(x > max1){ 
            max2 = max1;    // save current largest to second largest
            max1 = x;   // update largest
        }
        else if( x > max2 && x != max1 ){ max2 = x; }   // duplicate handling
    }

    cout << max1 << " " << max2 << endl;
    return 0;
}
