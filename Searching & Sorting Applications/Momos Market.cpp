/*
Momos Market

Shreya loves to eat momos. Her mother gives her money to buy vegetables but she manages to save some money out of it daily. After buying vegetables, she goes to "Momos Market", where there are ‘n’ number of shops of momos. Each of the shops of momos has a rate per momo. She visits the market and starts buying momos (one from each shop) starting from the first shop. She will visit the market for ‘q’ days. You have to tell that how many momos she can buy each day if she starts buying from the first shop daily. She cannot use the remaining money of one day on some other day. But she will save them for other expenses in the future, so, you also need to tell the sum of money left with her at the end of each day.
Input Format:
First line will have an integer ‘n’ denoting the number of shops in market.
Next line will have ‘n’ numbers denoting the price of one momo of each shop.
Next line will have an integer ‘q’ denoting the number of days she will visit the market.
Next ‘q’ lines will have one integer ‘X’ denoting the money she saved after buying vegetables.
Constraints:
1 <= n <= 10^5
1 <= q <= 10^5
1 <= X <= 10^9
Output:
There will be ‘q’ lines of output each having two space separated integers denoting number of momos she can buy and amount of money she saved each day.
Sample Input:
4
2 1 6 3
1
11
Sample Output:
3 2
Explanation:
Shreya visits the "Momos Market" for only one day. She has 11 INR to spend. She can buy 3 momos, each from the first 3 shops. She would 9 INR (2 + 1 + 6) for the same and hence, she will save 2 INR.
*/

//Solution

#include<bits/stdc++.h>
using namespace std;

bool checker( long long arr[], int mid, long long target)
{
   if( arr[mid] <= target  &&  arr[mid+1] > target )
   {
       return 1;
   }
    return 0;
}

void momos(long long arr[], int n, long long target)
{
     int start = 0;
       int end = n-1;
       int mid, ans = 0;
       while( start <= end)
       {
           int mid = (start + end)/2;
           if ( checker(arr,mid,target) )
           {
               ans = mid;
           }
           
           if ( arr[mid] < target)
               start = mid+1;
           else
               end = mid-1;
           
       }
    if(target < arr[0])
    {
        cout<<0<<" "<<target;
    cout<<endl;
    }
    else
    {
        cout<<ans+1<<" "<<target-arr[ans];
    cout<<endl;
     }
}

int main(){
    int n;
    cin>>n;
    int p[n];
    long long prefix[n];
    long long sum = 0;
    for( int i=0; i<n; i++){
        cin>>p[i];
        sum+=p[i];
        prefix[i] = sum;
    }
    
    int q;
    cin>>q;
    long long save[q];
    
    for( int i=0; i<q; i++){
        cin>>save[i];
    }
    
   for( int i = 0; i<q; i++){
       
       momos(prefix,n,save[i]);
   }
    return 0;
}