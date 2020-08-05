/*
Extract Unique characters

Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

//Solution

#include<iostream>
using namespace std;
char* uniqueChar(char *str){
    int index = 0;   
    
      
   for (int i=0; str[i]!='\0'; i++) { 
         
     int j;   
     for (j=0; j<i; j++){  
        if (str[i] == str[j]){
            // cout<<j;
           break;
        }
         
     }
     if (j == i) 
        str[index++] = str[i]; 
   } 
     str[index] = '\0';
   return str; 
}

int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
