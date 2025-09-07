/*
Write a C program to delete an element from an array at a specified position or
element.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int len;
    cout << "Enter length " << endl;
    cin >> len;
    vector<int> nums(len);
    for(int i=0; i<len; i++)    cin >> nums[i];

    int pos;
    cout<<"Enter position of element to be removed"<<endl;
    cin>>pos;

    // if(pos >= 0 && pos <= nums.size()){
    //     nums.erase(nums.begin()+pos);   // remove element from position
    //     cout<< "Array after element deletion" << endl;
    //     for(int x:nums) cout<< x << " ";
    // }else{
    //     cout<< "Invalid position argument" << endl;
    // }
    int curr = 0;
    for(auto it = nums.begin(); it!=nums.end(); it++){
        if(curr = pos){
            nums.erase(it);
            break;
            // break away from loop
        }
        curr++; // increment curr till pos
    }
    
    //print after deletion
    for(int x : nums)   cout<< x <<" ";

    return 0;
}