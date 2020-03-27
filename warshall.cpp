//Warshall algorithm

#include<iostream>
using namespace std;

void warshall(int g[10][10], int n){
    int graph[10][10][10];

    int i,j,k;
    for(i=1 ;i<=n;i++){
        for(j=1; j<=n; j++){
            graph[i][j][0] = g[i][j];
        }
    }
    for(k=1;k<=n+1; k++){
        for(i=1; i<=n; i++){
            for(j=1; j<=n; j++){
                graph[i][j][k] = graph[i][j][k-1] || (graph[i][k][k-1]&&graph[k][j][k-1]);
            }
        }
    }
    cout<<"Transitive closure of the graph is\n";
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cout<<graph[i][j][n]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int n,i,j;
    cout<<"Enter the number of vertices"<<endl;
    cin>>n;
    int graph[10][10];
    cout<<"Enter the values of the adjacency matrix"<<endl;
    for(i=1; i<=n; i++){
        for(j=1; j<=n; j++){
            cin>>graph[i][j];
        }
    }

    warshall(graph,n);

    

    
}

//Output
/*
Enter the number of vertices
4
Enter the values of the adjacency matrix
0 1 0 0
0 0 0 1
0 0 0 0
1 0 1 0
Transitive closure of the graph is
1 1 1 1
1 1 1 1
0 0 0 0
1 1 1 1

Enter the number of vertices
3
Enter the values of the adjacency matrix
0 1 0
0 0 1
1 0 0
Transitive closure of the graph is
1 1 1
1 1 1
1 1 1
*/