/*
Even and Odd Indexes

Given an array of integers, print two integer values:
First, the sum of all numbers which are even as well as whose index are even.
Second, the sum of all numbers which are odd as well as whose index are odd.
Print the two integers space separated. (Arrays is 0-indexed)
Input:
Given an integer denoting the size of array.
Next line will have a line containing ‘n’ space separated integers.
Constraints:
1<=n<=10^5
1 <= Ai <= 10^6 
Output:
Two space separated integers denoting even and odd sums respectively.
Sample Input:
5
2 3 5 1 4
Sample Output:
6 4
*/

//Solution 1

#include<stdio.h>
int main()
{
    int i,n;
    scanf("%d",&n);
    int A[n];
    int sum1=0,sum2=0;
    for(i=0;i<n;i++)
    { scanf("%d",&A[i]);
    }
    for(i=0;i<n;i++)
    { if(A[i]%2==0 && i%2==0)
            sum1+=A[i];
    }
    for(i=0;i<n;i++)
    { if(A[i]%2!=0 && i%2!=0)
            sum2+=A[i];
    }
   printf("%d %d",sum1,sum2);
    
    return 0;
}