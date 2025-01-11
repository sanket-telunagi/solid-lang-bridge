/*
    place n queens in the n x n chess board 
    such that all queens are safe 

*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std ;

bool isSafe(vector<bool> * board, int row, int col) {
    // if (row < 0 || col < 0 || row >= board->size() || col >= board->size()) {
    //     return true ;
    // }
    // if (board[row][col]) return false ;
    // // right
    // isSafe(board, row + 1, col) ;
    // // left
    // isSafe(board, row - 1, col) ;

    // //
    int ct = 0 ;
    for (int i = 0; i < count; i++)
    {
        /* code */
    }
     
}

bool n_Queen(vector<bool> * board, int row) {
    if(row >= board->size()) return true ;
    for (int col = 0; col < board->size(); col++)
    {
        if (isSafe(board, row, col)) {

        }
    }
    
}

int main()
{
    int n ;
    cin >> n ;
    vector<bool> board[n] ;
    cout << n_Queen(board, 0) ;
    return 0 ;
}