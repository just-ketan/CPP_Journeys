/*
Qns 2. Given an array of prices where prices[i] is the price of a given stock on the ith day.
You want to maximize your profit by choosing a single day to buy one stock and choosing a
different day in the future to sell that stock. Return the maximum profit you can achieve from
this transaction. If you cannot make a profit, return 0.
Test Cases:
1. Input: prices = [7,1,5,3,6,4]
Output: 5
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    vector<int> prices = {7,1,5,3,6,4};

    // to find the maximum profit,
        /*
            we take the element, find an element which is least in the rest and calculate profit
            if the calculated profit is greater than existing, then we update
        */
    // int profit = 0;
    // for(int i=0; i<prices.size(); i++){
    //     // int curr = prices[i];
    //     for(int j=i+1; j<prices.size(); j++){
    //         if(prices[i] - prices[j] > profit){
    //             profit = prices[j] - prices[i];
    //         }
    //     }
    // }

    // cout<<"Max profit" << profit;
    // return 0;

    if(prices.size() < 2){  cout<<"Max profit: 0" <<endl;  return 0;}

    int minprice = prices[0];   // smaleest price seen so far
    int maxprofit = 0;  // maximum possible profit

    for(int i = 1; i<prices.size(); i++){
        maxprofit = max(maxprofit, prices[i] - minprice);   //update the max profit so far

        minprice = min(minprice, prices[i]);   // the least price seen till now
    }

    cout<< "Max Profit" << maxprofit << endl;
    return 0;
}
