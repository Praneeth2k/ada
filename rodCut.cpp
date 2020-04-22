#include<limits.h>
#include<iostream>
using namespace std;
  
int maximum(int a, int b){
    if(a > b) return a;
    else return b;
}
  

int cutRod(int price[], int n) 
{ 
    if (n <= 0) 
       return 0; 
    int max = INT_MIN; 

    for (int i = 0; i<n; i++) 
        max = maximum(max, price[i] + cutRod(price, n-i-1)); 
  
   return max; 
} 

int main() 
{ 
    int n;
    cout<<"Enter the size of the rod"<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter the prices of rod of length 1, 2, 3 ... "<<n<<endl;
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }
    cout<<"Maximum Obtainable Value is "<<cutRod(arr, n)<<endl;  
    return 0; 
}
/* OUTPUT
Enter the size of the rod
8
Enter the prices of rod of length 1, 2, 3 ... 8
1 5 8 9 10 17 17 20
Maximum Obtainable Value is 22

Enter the size of the rod
8
Enter the prices of rod of length 1, 2, 3 ... 8
3 1 5 8 9 10 17 17 20
Maximum Obtainable Value is 24
*/
