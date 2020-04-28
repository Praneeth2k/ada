#include<iostream>
#include<stdbool.h>

using namespace std;
  
int V; 
  
void printSolution(int color[]); 
  


bool isSafe (int v, bool graph[10][10], int color[], int c) 
{ 
    for (int i = 0; i < V; i++) 
        if (graph[v][i] && c == color[i]) 
            return false; 
    return true; 
} 
  

bool graphColoringUtil(bool graph[10][10], int m, int color[], int v) 
{ 
    
    if (v == V) 
        return true; 
  
 
    for (int c = 1; c <= m; c++) 
    { 

        if (isSafe(v, graph, color, c)) 
        { 
           color[v] = c; 
  
          
           if (graphColoringUtil (graph, m, color, v+1) == true) 
             return true; 
  

           color[v] = 0; 
        } 
    } 

    return false; 
} 
  

bool graphColoring(bool graph[10][10], int m) 
{ 
     
    int color[V]; 
    for (int i = 0; i < V; i++) 
       color[i] = 0; 
  
    
    if (graphColoringUtil(graph, m, color, 0) == false) 
    { 
      printf("Solution does not exist"); 
      return false; 
    } 
  
    
    printSolution(color); 
    return true; 
} 
  

void printSolution(int color[]) 
{ 
    printf("Solution Exists:"
            " Following are the assigned colors \n"); 
    for (int i = 0; i < V; i++) 
      printf(" %d ", color[i]); 
    printf("\n"); 
} 
  

int main(){
    int m, i ,j;
    cout<<"Enter the number of vertices"<<endl;
    cin>>V;
    bool graph[10][10]; 
    cout<<"Enter the values of the adjacency matrix\n";
    for(i = 0; i < V; i++){
        for(j = 0; j < V; j++){
            cin>>graph[i][j];
        }
    }
    
    cout<<"Enter the number of colors\n";
    cin>>m;

    graphColoring (graph, m); 
    return 0; 
} 
/*
Enter the number of vertices
4
Enter the values of the adjacency matrix
0 1 1 1
1 0 1 0
1 1 0 1
1 0 1 0
Enter the number of colors
3
Solution Exists: Following are the assigned colors
 1  2  3  2
 */