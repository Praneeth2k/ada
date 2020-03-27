#include<iostream>
using namespace std; 
#include<ctime>
  
// Merges two subarrays of arr[]. First subarray is arr[l..m], Second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = l; // Initial index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 


  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        
        int m = (l+r) / 2;
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        cout<<A[i]<<" "; 
    cout<<"\n"; 
} 

int main() 
{   
    clock_t t;
    int *arr,n,i;
    cout<<"Enter the number of elements"<<endl;
    cin>>n; 
    arr = new int[n];
    cout<<"Enter the elements"<<endl;
    for(i=0;i<n;i++){cin>>arr[i];} 
    t = clock();
    mergeSort(arr, 0, n - 1); 
    t = clock() - t;
  
    cout<<"The sorted array is"<<endl; 
    printArray(arr, n); 
    cout<<"The time taken to sort is "<<t;
    return 0; 
} 

/*
Enter the number of elements
5
Enter the elements
3 1 5 2 6
The sorted array is
1 2 3 5 6
The time taken to sort is 0


Enter the number of elements
20
Enter the elements
4 9 28 38 48 8 48 84 4032 0 0 20 939 9 32 4 2 9 8 111
The sorted array is
0 0 2 4 4 8 8 9 9 9 20 28 32 38 48 48 84 111 939 4032
The time taken to sort is 0
*/
