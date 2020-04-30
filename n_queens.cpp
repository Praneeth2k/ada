#include<iostream>
#include<stdbool.h>
using namespace std;

int count = 0, f;
void printSol(int board[][15], int n){
    
    for(int i = 1; i <=n; i++){
        for(int j = 1; j <= n; j++){
            if(board[i][j] == 1){
                cout<<j<<" " ;
            }
        }
    }
    cout<<"\n";

}

bool isSafe(int board[][15], int row, int col, int n){
    int i, j; 
    
  
    /* Check this row on left side */
    for (i = 1; i < col; i++) 
        if (board[row][i] == 1) 
            return false; 
  
    /* Check upper diagonal on left side */
    for (i = row - 1, j = col - 1; i >= 1 && j >= 1; i--, j--) 
        if (board[i][j] == 1) 
            return false; 
  
    /* Check lower diagonal on left side */
    for (i = row + 1, j = col - 1; j >= 1 && i <= n; i++, j--) 
        if (board[i][j] == 1) 
            return false; 
  
    return true; 
} 


bool func(int board[][15], int n, int col){
    int i;
    bool t;
    int flag = 0;

    for(i = 1; i <= n; i++){
        
        board[i][col] = 1;
        if(isSafe(board, i, col, n)){
            if(col == n){
                printSol(board, n);
                count++;f = 1;
                flag = 1;
            }
            t = func(board, n, col + 1);
            if(t == false){
                board[i][col] = 0;
            }

        }
        else board[i][col] = 0;
    }
    if(flag == 1)
        return true;
    return false;    
}



int main(){
    int n;
    cout<<"Enter the value of n for n - queen's problem\n";
    cin>>n;
    int board[n + 1][15] = {0};
    
    bool t = func(board, n, 1);
    if(f == 0){cout<<"Soution does not exist\n";}
    else{cout<<"Total number of solutions are: "<<count;}
}
/*
Enter the value of n for n - queen's problem
2
Soution does not exist

Enter the value of n for n - queen's problem
3
Soution does not exist

Enter the value of n for n - queen's problem
4
3 1 4 2
2 4 1 3
Total number of solutions are: 2

Enter the value of n for n - queen's problem
5
1 4 2 5 3
1 3 5 2 4
3 1 4 2 5
4 1 3 5 2
2 4 1 3 5
5 3 1 4 2
2 5 3 1 4
5 2 4 1 3
4 2 5 3 1
3 5 2 4 1
Total number of solutions are: 10
*/