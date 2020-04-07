#include<iostream>
using namespace std; 
  
int max(int a, int b){
    if(a>b)
        return a;
    else
        return b;
} 
  

int knapSack(int W, int wt[], int val[], int n){
   int i, w; 
   int K[n+1][W+1]; 
  
   // Build table K[][] in bottom up manner 
   for (i = 0; i <= n; i++) 
   { 
       for (w = 0; w <= W; w++){
           if (i==0 || w==0) 
               K[i][w] = 0; 
           else if (wt[i-1] <= w) 
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]); 
           else
                 K[i][w] = K[i-1][w]; 
       } 
   } 
  
   return K[n][W]; 
} 
  
int main() 
{ 
    int *val, *wt, n, i, W;
    cout<<"Enter the number of items"<<endl;
    cin>>n;
    val = new int[n];
    wt = new int[n];
    cout<<"Enter the weights of the items"<<endl;
    for(i=0; i<n; i++){
        cin>>wt[i];
    }
    cout<<"Enter the values of the items"<<endl;
    for(i=0; i<n; i++){
        cin>>val[i];
    }
    cout<<"Enter the maximum capacity"<<endl;
    cin>>W; 
     
    printf("%d", knapSack(W, wt, val, n)); 
    return 0; 
}
/* 
Enter the number of items
4
Enter the weights of the items
2 1 3 2
Enter the values of the items
12 10 20 15
Enter the maximum capacity
5
37
*/