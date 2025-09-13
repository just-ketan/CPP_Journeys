#include<bits/stdc++.h>
using namespace std;

// insertion sort
void insertion_sort(vector<int>& arr){
    for(int i=2; i<arr.size(); i++){
        int key = arr[i];
        int j = i-1;
        while(j>0 && arr[j] > key){
            // the i-1th element from current i is greater
            // need to shift this right and find the place for current i
            arr[j+1] = arr[i];
            j--;    // bring j one step left 
        }
        arr[j+1] = key; // control reaches here, j is -1, thus offset by adding +1
    }
}