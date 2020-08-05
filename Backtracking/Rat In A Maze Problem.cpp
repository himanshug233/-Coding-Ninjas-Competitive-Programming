/*
Rat In A Maze Problem

You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
Input Format
Line 1 : Integer N
Next N Lines : Each line will contain ith row elements (separated by space)
Output Format :
One Line for every possible solution. 
Every line will have N*N maze elements printed row wise and are separated by space. Only cells that are part of solution path should be 1, rest all cells should be 0.
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Sample Output 1 Explanation :
Only 1 path is possible
Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Sample Output 2 Explanation :
4 paths are possible
*/

//Solution

#include<iostream>
using namespace std;
//#include "Solution.h"

void printsol(int** sol, int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<sol[i][j]<<" ";
        }
    }
    cout<<endl;
}

void helper(int maze[][20], int n, int** sol, int x, int y)
{
    if( x==n-1 && y == n-1)
    {
        sol[x][y] = 1;
        printsol(sol,n);
        //sol[x][y] = 0;
        return;
    }
    if (x<0 || y<0 || x>=n || y>=n || sol[x][y] ==1 || maze[x][y] == 0)
        return;
    sol[x][y] = 1;
    helper(maze,n,sol,x-1,y);
    helper(maze,n,sol,x+1,y);
    helper(maze,n,sol,x,y-1);
    helper(maze,n,sol,x,y+1);
    sol[x][y] = 0;
}

void ratInAMaze(int maze[][20], int n){

  /* Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Print output as specified in the question
  */
    int** sol = new int*[n];
    for( int i=0; i<n; i++)
    {
        sol[i] = new int[n];
    }
    
    helper(maze,n,sol,0,0);
}

int main(){

  int n; 
  cin >> n ;
  int maze[20][20];
  for(int i = 0; i < n ;i++){
	for(int j = 0; j < n; j++){
        	cin >> maze[i][j];
        }		
  }
  ratInAMaze(maze, n);
}