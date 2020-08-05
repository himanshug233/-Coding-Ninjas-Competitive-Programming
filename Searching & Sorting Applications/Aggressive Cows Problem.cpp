/*
Aggressive Cows Problem
Send Feedback
Farmer John has built a new long barn, with N (2 <= N <= 100,000) stalls. The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. What is the largest minimum distance?
Input
t – the number of test cases, then t test cases follows. 
* Line 1: Two space-separated integers: N and C
* Lines 2..N+1: Line i+1 contains an integer stall location, xi
Output
For each test case output one integer: the largest minimum distance.
Sample Input :
1
5 3
1
2
8
4
9
Sample Output:
3 
Output details:
FJ can put his 3 cows in the stalls at positions 1, 4 and 8, 
resulting in a minimum distance of 3.
*/

//Solution

#include<bits/stdc++.h>
using namespace std;

bool check(long long p[], int n, int c, int d){
    int count = 1;
    long long last_p = p[0];
    for(int i=0; i<n; i++){
        if(p[i]-last_p >= d){
            count++;
            last_p = p[i];
        }
        if( count == c)
            return 1;
    }
    return 0;
}
int main() {
    int t;
    cin>>t;
    
    while( t-- ){
        int n,c;
        cin>>n>>c;
        long long p[n];
        int i;
        for(i=0; i<n; i++){
            cin>>p[i];
        }
        sort(p,p+n);
        long long ans, mid, start, end;
        start = 0;
        end = p[n-1] - p[0];
        
        while ( start <= end){
            mid = start + (end-start)/2;
            
            if(check(p,n,c,mid)){
                start = mid + 1;
                ans = mid;
            }
            else
                end = mid-1;
        }
        cout<<ans<<endl;
    }
}