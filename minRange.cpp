#include<bits/stdc++.h> 
using namespace std; 


//Find 3 closest elements one from each of the three arrays.
//Range will be (min of these 3 elements, max of these three elements)
void findClosest(int A[], int B[], int C[], int p, int q, int r) 
{ 
  
    int diff = INT_MAX;  // Initialize min diff 
  
    // Initialize result 
    int res_i =0, res_j = 0, res_k = 0; 
  
    // Traverse arrays 
    int i=0,j=0,k=0; 
    while (i < p && j < q && k < r) 
    { 
        // Find minimum and maximum of current three elements 
        int minimum = min(A[i], min(B[j], C[k])); 
        int maximum = max(A[i], max(B[j], C[k])); 
  
        // Update result if current diff is less than the min 
        // diff so far 
        if (maximum-minimum < diff) 
        { 
             res_i = i, res_j = j, res_k = k; 
             diff = maximum - minimum; 
        } 
  
        // We can't get less than 0 as values are absolute 
        if (diff == 0) break; 
  
        // Increment index of array with smallest value 
        if (A[i] == minimum) i++; 
        else if (B[j] == minimum) j++; 
        else k++; 
    } 
  
    // Print result 
    cout<<"The smallest range is\n[";
    int l = min(min(A[res_i],B[res_j]), C[res_k]);
    int h = max(max(A[res_i],B[res_j]), C[res_k]);
    cout << l << " " << h<<"]"; 
} 
   
int main() 
{   int a, b, c, i;
    cout<<"Enter the sizes of the 3 arrays\n";
    cin>>a>>b>>c;
    int A[a]; 
    int B[b]; 
    int C[c];
    cout<<"Enter the first array\n";
    for(i = 0 ; i < a ; i++){
        cin>>A[i];
    }
    cout<<"Enter the second array\n";
    for(i = 0 ; i < b ; i++){
        cin>>B[i];
    }
    cout<<"Enter the third array\n";
    for(i = 0 ; i < a ; i++){
        cin>>C[i];
    }
  
    findClosest(A, B, C, a, b, c); 
    return 0; 
} 
/*
Enter the sizes of the 3 arrays
5
5
5
Enter the first array
4 7 9 12 15
Enter the second array
0 8 10 14 20
Enter the third array
6 12 16 30 50
The smallest range is
[6 8]
*/