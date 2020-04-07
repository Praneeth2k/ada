#include<iostream>
#include<string.h>
using namespace std; 


int longest_pali(string str){ 
   int n = str.length(); 
   int i, j, cl; 
   int L[n][n];  
  
  

   for (i = 0; i < n; i++) 
      L[i][i] = 1; 
  
    for (cl=2; cl<=n; cl++){
        for (i=0; i<n-cl+1; i++){ 
            j = i+cl-1; 
            if (str[i] == str[j] && cl == 2) 
               L[i][j] = 2; 
            else if (str[i] == str[j]) 
               L[i][j] = L[i+1][j-1] + 2; 
            else
               L[i][j] = max(L[i][j-1], L[i+1][j]); 
        } 
    } 
  
    return L[0][n-1]; 
} 
  

int main(){
    string seq;
    cout<<"Enter the string\n";
    cin>>seq;
    
    int n = seq.length(); 
    cout<<"The length of the longest palindromic subsequence is "<< longest_pali(seq); 
    return 0; 
} 
/*
Enter the string
afdsmalayalampll
The length of the longest palindromic subsequence is 9
*/