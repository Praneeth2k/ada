 #include<iostream>
 using namespace std;
  


  
int minDistance(int dist[], bool sptSet[], int V) 
{ 
   
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
} 
  

int printSolution(int dist[], int prevVertex[], int V) 
{   int s, k = 0;
    int path[V];
    for(int k = 0; k<V;k++){
        printf("%d ",prevVertex[k]);
    }
    printf("\n");
    printf("Vertex \t\t Distance from Source \t\t\t Path\n"); 
    for (int i = 0; i < V; i++){
        k = 0;
        path[k++] = i;
        s = i;
        while(s != 0){
            path[k++] = prevVertex[s];
            s = prevVertex[s];
        }
        printf("\n%d \t\t %d\t\t\t\t\t", i, dist[i]);
        for(int j = k-1; j>=0; j--){
            if(j == k-1){
                printf("%d",path[j]);
            }
            else
                printf(" - >%d", path[j]);
        }
    }
} 

void dijkstra(int graph[][20], int src, int V) 
{ 
    int dist[V]; 

    int prevVertex[V]; 
  
    bool sptSet[V];
   
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  

    dist[src] = 0; 
  
    
    for (int count = 0; count < V - 1; count++) { 
      
        int u = minDistance(dist, sptSet, V); 
  
       
        sptSet[u] = true; 
        prevVertex[0] = 0;
        
        for (int v = 0; v < V; v++)  
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v]; 
                prevVertex[v] = u;
            }
    } 
  
     
    printSolution(dist, prevVertex, V); 
} 
  
int main() 
{   int V, i ,j;
    cout<<"Enter the number of vertices"<<endl;
    cin>>V;
    int graph[V][20];
    cout<<"Enter the weighted adjecency matrix values\n";
    for(i = 0; i < V; i++){
        for(j = 0; j < V; j++){
            cin>>graph[i][j];
        }
    }

   
    
  
    dijkstra(graph, 0, V); 
  
    return 0; 
} 
/*
Enter the number of vertices
9
Enter the weighted adjecency matrix values
0 4 0 0 0 0 0 8 0
4 0 8 0 0 0 0 11 0
0 8 0 7 0 4 0 0 2
0 0 7 0 9 14 0 0 0
0 0 0 9 0 10 0 0 0
0 0 4 14 10 0 2 0 0
0 0 0 0 0 2 0 1 6
8 11 0 0 0 0 1 0 7
0 0 2 0 0 0 6 7 0
0 0 1 2 5 6 7 0 2
Vertex           Distance from Source                    Path

0                0                                      0
1                4                                      0 - >1
2                12                                     0 - >1 - >2
3                19                                     0 - >1 - >2 - >3
4                21                                     0 - >7 - >6 - >5 - >4
5                11                                     0 - >7 - >6 - >5
6                9                                      0 - >7 - >6
7                8                                      0 - >7
8                14                                     0 - >1 - >2 - >8
*/

