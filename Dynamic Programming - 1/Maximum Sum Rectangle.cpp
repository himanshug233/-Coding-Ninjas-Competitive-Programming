/*
Maximum Sum Rectangle

Given a 2D array, find the maximum sum rectangle in it. In other words find maximum sum over all rectangles in the matrix.
Input
First line contains 2 numbers n and m denoting number of rows and number of columns. Next n lines contain m space separated integers denoting elements of matrix nxm.
Output
Output a single integer, maximum sum rectangle.
Constraints
1<=n,m<=100
Sample Input
4 5
1 2 -1 -4 -20
-8 -3 4 2 1
3 8 10 1 3
-4 -1 1 7 -6
Sample Output
29
*/

//Solution

#include <bits/stdc++.h>
using namespace std;

int kadane_sum(int* temp, int n){
    int best_sum = INT_MIN;
    int curr_sum = 0;
    for(int i = 0; i<n; i++){
        curr_sum += temp[i];
        if(best_sum < curr_sum)
            best_sum = curr_sum;
        if(curr_sum < 0)
            curr_sum = 0;
    }
    return best_sum;
}

int max_rect_sum(int** input, int r, int c){
    int sum = INT_MIN;
    for(int left = 0; left<c; left++){
        int *temp = new int[r]();
        for(int right = left; right<c; right++){
            for(int i = 0; i<r; i++){
                temp[i] += input[i][right];
            }
            sum = max(sum, kadane_sum(temp, r));
        }
        delete[] temp;
    }
    return sum;
}

int main()
{
    int r, c;
    cin>>r>>c;
    int **input = new int*[r];
    for(int i = 0; i<r; i++){
        input[i] = new int[c];
        for(int j = 0; j<c; j++){
            cin>>input[i][j];
        }
    }
    cout<<max_rect_sum(input, r, c);
    for(int i = 0; i<r; i++){
        delete[] input[i];
    }
    delete[] input;
    return 0;
}
