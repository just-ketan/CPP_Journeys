/*
Write a C program to read elements in a matrix and check whether the given matrix is
a symmetric matrix or not.
*/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int rows, cols;
    cout << "Rows and cols";
    cin >> rows >> cols;

    if(rows!=cols){ cout << "Invalid matrix dimensions, cant check for symmetry";   return 0; }

    vector<vector<int>> matrix(rows,vector<int>(cols));

    for(int i=0; i<rows; i++){
        for(int j=0; j <cols; j++){
            cin >> matrix[i][j];
        }
    }

    /*
    |1 2 3| is a symmetric matrix is a[i][j] == a[j][i]
    |2 4 5| we ignore the diagonal elements where i == j
    |3 5 6|
    */
    bool flag = true;

    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            if(i == j)  continue;
            if(matrix[i][j] != matrix[j][i]){
                flag = false;
                break;
            }
        }
        if(!flag)   break;
    }
    flag == true ? cout << "Symmetric"<< endl : cout << "not symmetric" << endl ;
    return 0;

}