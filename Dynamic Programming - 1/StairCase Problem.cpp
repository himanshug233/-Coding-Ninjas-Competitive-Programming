/*
StairCase Problem

A child is running up a staircase with n steps and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return all possible number of ways.
Time complexity of your code should be O(n).
Input format :
Integer n (No. of steps)
Constraints :
n <= 70
Sample Input 1:
4
Sample Output 1:
7
*/

//Solution

#include <iostream>
using namespace std;

long staircase(int n,long *arr = new long[71]()){
	if(n==0 || n==1){
        return 1;
    }
    if(n==2){
        return 2;
    }
    if(arr[n]>0){
        return arr[n];
    }
    long total_ways = staircase(n-3, arr) + staircase(n-2, arr) + staircase(n-1, arr);
    arr[n] = total_ways;
    return total_ways;
}

int main()
{
	int n;
	cin >> n;
	cout << staircase(n);
}

