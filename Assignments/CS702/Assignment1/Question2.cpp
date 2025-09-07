/*
Write a C program to input elements into an array and find the reverse of the array.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int len;
    cout<<"Enter length"<<endl;
    cin >> len;

    vector<int> nums(len);
    for(int i=0; i<len; i++)    cin >> nums[i];

    // print reverse
    for(int i=len-1; i>0; i--)  cout<< nums[i] << " ";

    return 0;
}