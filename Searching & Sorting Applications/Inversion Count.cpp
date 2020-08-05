/*
Inversion Count
Send Feedback
Let A[0 ... n-1] be an array of n distinct positive integers. If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). Given an integer array A, your task is to find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4
*/

//Solution

#include <iostream>
using namespace std;

long long merge(int A[], int l, int mid, int r){
    int i = l, j = mid, k = 0;
    
    int temp[r-l+1];
    long long count = 0;
    while(i<mid && j<=r){
        if( A[i] <= A[j] ){
            temp[k++] = A[i++];
        }
        else{
            temp[k++] = A[j++];
            count+=mid-i; 
        }
    }
    while ( i<mid ){
        temp[k++] = A[i++];
    }
    while ( j<=r ){
        temp[k++] = A[j++];
    }
    
    for( i=l, k=0; i<=r; i++, k++){
        A[i] = temp[k]; 
    }
    return count;
    
}
long long merge_sort( int A[], int l, int r){
    long long count = 0;
    if( l<r ){
      int mid = (l+r)/2; 
        
        long long leftcount = merge_sort(A,l,mid);
        long long rightcount = merge_sort(A,mid+1,r);
        long long mergecount = merge(A,l,mid+1,r);
        return leftcount + rightcount + mergecount;
    }
    return count;
}
long long solve(int A[], int n)
{
    long long ans = merge_sort(A,0,n-1);
	return ans;
}

int main()
{
    int n;
    cin >> n;

    long long* arr = new long long[n];

    for(int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    cout << getInversions(arr, n);

    delete arr;
}