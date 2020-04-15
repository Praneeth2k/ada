#include <iostream>
#include<algorithm> 
using namespace std; 

 
  
void findMin(int coins[], int amt, int n){
    int ans[n], k=0; 
  
    for (int i = n - 1; i >= 0; i--) { 
  
        while (amt >= coins[i]) { 
            amt -= coins[i]; 
            ans[k++] = coins[i];
        } 
    } 
  
    if(amt == 0){
        cout << "The coins required are \n";
        for (int i = 0; i < k; i++) 
            cout << ans[i] << "  "; 
        cout<<"\nThe number of coins required is : "<<k<<endl; 
    }
    else{
        cout<<"Not possible to get that sum using the given denominations"<<endl;
    }
} 
  

int main() 
{   int n, amt, *coins;
    cout<<"Enter the number of coins available\n";
    cin>>n;
    coins = new int[n];
    cout<<"Enter the values of the coins\n";
    for(int i=0; i<n; i++){
        cin>>coins[i];
    }
    
    cout<<"Enter the amount\n";
    cin>>amt;
    sort(coins, coins + n);
    
    findMin(coins, amt, n); 
    return 0; 
} 

/*
Enter the number of coins available
5
Enter the values of the coins
5 10 20 50 100
Enter the amount
174
Not possible to get that sum using the given denominations


Enter the number of coins available
6
Enter the values of the coins
1 5 10 20 50 100
Enter the amount
129
The coins required are
100  20  5  1  1  1  1
The number of coins required is : 7
*/