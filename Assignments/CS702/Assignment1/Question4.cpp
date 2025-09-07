/*
Write a C program to read elements in two matrices and multiply them
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int rows1,cols1;
    cout << "enter first matrix dimensions" << endl;
    cin >> rows1 >> cols1;

    vector<vector<int>> nums1(rows1, vector<int>(cols1));
    // initiallising matrix 1
    for(int i=0; i<rows1; i++){
        for(int j=0; j<cols1; j++){
            cin >> nums1[i][j];
        }
    }

    int rows2, cols2;
    cout << "enter second matrix dimensions" << endl;
    cin >> rows2, cols2;

    vector<vector<int>> nums2(rows2, vector<int>(cols2));
    //initiallise matrix 2
    for(int i=0; i<rows2; i++){
        for(int j=0; j<cols2; j++){
            cin >> nums2[i][j];
        }
    }


    // if the cols of first is not same as row of 2, we cant make a matrix
    if(cols1 != rows2){  cout<< "Matrix multiplication not possible" << endl; return 0;}

    vector<vector<int>> res(rows1,vector<int>(cols2));
    // resultant matrix
    for(int i=0; i<rows1; i++){
        for(int j=0; j<cols2; j++){
            for(int k=0; k<rows2; k++){
                // k iterates row wise in matrix
                res[i][j] += nums1[i][k] * nums2[k][j];
            }
        }
    }

    // show matrix
    for(int i=0; i<rows1; i++){
        for(int j =0; j<cols2; j++){
            cout << res[i][j]<< " ";
        }
        cout << endl;
    }

    return 0;
}
