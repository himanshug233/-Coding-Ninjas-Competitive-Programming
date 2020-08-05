/*
Different Names

In Little Flowers Public School, there are many students with same first names. You are given a task to find the students with same names. You will be given a string comprising of all the names of students and you have to tell the name and count of those students having same. If all the names are unique, print -1 instead.
Note: We don't have to mention names whose frequency is 1.
Input Format:
The only line of input will have a string ‘str’ with space separated first names of students.
Output Format:
Print the names of students along with their count if they are repeating. If no name is repeating, print -1
Constraints:
1 <= |str| <= 10^5
Time Limit: 1 second
Sample Input 1:
Abhishek harshit Ayush harshit Ayush Iti Deepak Ayush Iti
Sample Output 1:
harshit 2
Ayush 3
Iti 2
Sample Input 2:
Abhishek Harshit Ayush Iti
Sample Output:
-1
*/

//Solution

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    getline(cin, str);
    
    //cout<<str;
    map<string,int> mp;
    
    string stemp="";
    
    int i;
    
    // cout<<str.length()<<endl;
    //cout<<(int)str[57]<<endl;
    //cout<<int( '\n' );
    
    for (i = 0; i < str.length(); i++){
        if(str[i] != ' ' && (int)str[i] != 13 )
        stemp = stemp + str[i];
        
        //cout<<str[57];
        
         if(str[i] == ' ' || i+1 == str.length() ){
         //if(str[i] == ' ' || i){
        // if(str[i] == ' ' || str[i] == '\0'){
        // if(str[i] == ' '){
            mp[stemp]++;
     //   cout<<stemp<<" "<<mp[stemp]<<endl;
            stemp = "";
        }
            
    }
    
    map<string,int>::iterator itr;
    
    int count=0;
    
    for(itr = mp.begin(); itr != mp.end(); itr++){
       //cout<<itr->first<<" "<<itr->second<<endl;
        if( itr->second >= 2 ){
           cout<<itr->first<<" "<<itr->second<<endl;
            count = 1;
        }
    }
    if(count == 0){
        cout<<-1;
    }
    
	return 0;
}