#include <iostream> 
using namespace std; 
  
int min(int a,int b,int c){
    return min(min(a,b),c); 
} 
  
int editDist(string str1,string str2,int m,int n){
    if (m==0)
        return n; 
    if (n==0) 
        return m; 
  
    if (str1[m-1]==str2[n-1]) 
        return editDist(str1, str2, m - 1, n - 1); 
  
    return 1 + min(editDist(str1, str2, m, n - 1), // Insert 
                   editDist(str1, str2, m - 1, n), // Remove 
                   editDist(str1, str2, m - 1, n - 1) // Replace 
                   );
} 

int main(){
    string str1,str2;
    cout<<"Enter the first string\n";
    cin>>str1;
    cout<<"Enter the second string\n";
    cin>>str2;
  
    cout<<editDist(str1,str2,str1.length(),str2.length()); 
  
    return 0; 
} 

/*output 1:
Enter the first string
flat
Enter the second string
earth
4

output 2:
Enter the first string
black
Enter the second string
black
0

output 3:
Enter the first string
Praneeth
Enter the second string
Putin
7
*/