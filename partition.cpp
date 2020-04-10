#include<iostream>
using namespace std; 
  
bool isSubsetSum (int arr[], int n, int sum){  
    if (sum == 0)  
        return true;  
    if (n == 0 && sum != 0)  
        return false;  
    if (arr[n-1] > sum)  
       return isSubsetSum (arr, n-1, sum);  
  
    return isSubsetSum (arr, n-1, sum) ||  isSubsetSum (arr, n-1, sum-arr[n-1]);  
}  
  
 
bool findPartiion (int arr[], int n){
    int sum = 0;  
    for (int i = 0; i < n; i++)  
    sum += arr[i];  
    if (sum%2 != 0)  
    return false;  

    return isSubsetSum (arr, n, sum/2);  
}  
  

int main(){
    int *arr, n;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    arr = new int[n];
    cout<<"Enter the elements"<<endl;
    for(int i = 0; i<n ; i++){cin>>arr[i];}
    if (findPartiion(arr, n) == true)  
        cout << "Can be divided into two subsets "
                "of equal sum";  
    else
        cout << "Can not be divided into two subsets"
                " of equal sum";  
    return 0;  
} 
/*
Enter the number of elements
6
Enter the elements
3 1 0 3 4 2
Can not be divided into two subsets of equal sum

Enter the number of elements
7
Enter the elements
5 2 9 10 3 4 3
Can be divided into two subsets of equal sum   //5 + 10 + 3 = 2 + 9 + 4 + 3

*/ 