/*
N-Queen Problem

You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0 
*/

//Solution

#include<bits/stdc++.h>
using namespace std;
int board[11][11];

bool ispossible( int n, int row, int col)
{
    //Same Column
    for(int i = 0; i < n; i++)
    {
        if( board[i][col] == 1)
        {
            return 0;
        }
    }
    //upper left diagonal
    for(int i = row -1, j = col -1; j>=0 && i>=0; j--,i--)
    {
        if( board[i][j] == 1)
        {
            return 0;
        }
    }
    //upper right diagonal
     for(int i = row -1, j = col + 1; j<n && i>=0; j++,i--)
    {
        if( board[i][j] == 1)
        {
            return 0;
        }
    }
    return 1;
}

void nqueenhelper(int n, int row)
{
    if( n == row)
    {
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout<<board[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    
    for(int j = 0; j < n; j++)
    if( ispossible(n,row,j) )
    {
        board[row][j] = 1;
        nqueenhelper(n,row+1);
        board[row][j] = 0;
    }
    return;
}
void placeNQueens(int n){
    memset(board,0,11*11*sizeof(int));
    nqueenhelper(n,0);
	}
	
int main(){

  int n; 
  cin >> n ;
  placeNQueens(n);
}