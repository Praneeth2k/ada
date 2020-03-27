#include<iostream>
using namespace std; 
  
 
void merge(int ans[], int arr1[], int arr2[], int n) 
{   
   
    int i = 0; // Initial index of first array 
    int j = 0; // Initial index of second array 
    int k = 0; // Initial index of merged array 
    while (i < n && j < n) 
    { 
        if (arr1[i] <= arr2[j]) 
        { 
            ans[k] = arr1[i]; 
            i++; 
        } 
        else
        { 
            ans[k] = arr2[j]; 
            j++; 
        } 
        k++; 
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n) 
    { 
        ans[k] = arr1[i]; 
        i++; 
        k++; 
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n) 
    { 
        ans[k] = arr2[j]; 
        j++; 
        k++; 
    } 
} 

int main(){
    int *arr1, *arr2,i,*ans,n;
    cout<<"Enter the size\n";
    cin>>n;
    arr1 = new int[n]; arr2= new int[n];
    ans = new int[2*n];
    cout<<"Enter the elements of the first array\n";
    for(i=0; i<n ;i++){
        cin>>arr1[i];
    }
    cout<<"Enter the elemetns of the second array\n";
    for(i=0; i<n ;i++){
        cin>>arr2[i];
    }
    merge(ans, arr1, arr2, n);
    cout<<"Merged array is\n";
    for( i = 0; i < 2*n ;i++){
        cout<<ans[i]<<" ";
    }


    cout<<"The median is "<<ans[n-1]<<endl;//size of the merged array is 2*n
                                         // median will be at 2*n/2 - 1 i.e at n - 1



}
//Output
/*
Enter the size
6
Enter the elements of the first array
3 11 23 100 203 333
Enter the elemetns of the second array
4 89 89 92 114 233
Merged array is
3 4 11 23 89 89 92 100 114 203 233 333 The median is 89


Enter the size
3
Enter the elements of the first array
2 10 22
Enter the elemetns of the second array
3 6 11
Merged array is
2 3 6 10 11 22 The median is 6
*/