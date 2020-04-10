#include<iostream>
using namespace std;

int g[20][20], visited[20], n, sum = 0, c = 0;
void prims(int v){
    int i, j, indexi = 0, indexj = 0;
    visited[v] = 1;
    int min = 999999;
    
    for(i = 1; i <= n; i++){
        for(j = 1; j<=n; j++){
            if((visited[i] == 1) && (visited[j] == 0)){
                if(g[i][j] < min){
                    min = g[i][j];
                    indexi = i;
                    indexj = j;
                }
            }
        }
    }
    sum+= g[indexi][indexj];
    cout<<indexi <<" to "<<indexj<<", weight: "<<g[indexi][indexj]<<endl;
    c++;
    visited[indexj] = 1;
    if (c == n - 1){
        return;
    }
    prims(indexj);
}

int main(){
    int i, j, ele;
    cout<<"Enter the number of vertices"<<endl;
    cin>>n;
    cout<<"Enter the weighted matrix(Enter -1 if edge does not exist)"<<endl;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin>>ele;
            if(ele == -1){
                g[i][j] = 10000;
            }
            else g[i][j] = ele;
        }
        visited[i] = 0;
    }


    prims(1);
    cout<<"Minimum cost = "<<sum<<endl;
}
/*
output 1:
Enter the number of vertices
6
Enter the weighted matrix(Enter -1 if edge does not exist)
0 3 -1 -1 6 5
3 0 1 -1 -1 4
-1 1 0 6 -1 4
-1 -1 6 0 8 5
6 -1 -1 8 0 2
5 4 4 5 2 -1
1 to 2, weight: 3
2 to 3, weight: 1
2 to 6, weight: 4
6 to 5, weight: 2
6 to 4, weight: 5
Minimum cost = 15

output 2:
Enter the number of vertices
7
Enter the weighted matrix(Enter -1 if edge does not exist)
-1 28 -1 -1 -1 10 -1
28 -1 16 -1 -1 -1 14
-1 16 -1 12 -1 -1 -1
-1 -1 12 -1 22 -1 18
-1 -1 -1 22 -1 25 24
10 -1 -1 -1 25 -1 -1
-1 14 -1 18 24 -1 -1
1 to 6, weight: 10
6 to 5, weight: 25
5 to 4, weight: 22
4 to 3, weight: 12
3 to 2, weight: 16
2 to 7, weight: 14
Minimum cost = 99
*/