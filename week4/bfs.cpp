#include<iostream>
using namespace std;
void bfs(int g[20][20],int s,int queue[],int visited[],int f,int r,int count,int n){
    int i;
    count++;
    visited[s]=1;
    queue[++r]=s;
    while(f!=r+1){
        for(i=0;i<n;i++){
            if(g[queue[f]][i]==1){
                if(visited[i]==0){
                    count++;queue[++r]=i;visited[i]=1;
                }
            }
        }
        if(f==0){f=1;}
        else{
            cout<<queue[f]+1<<" ";
            f++;
            
        }
    }
    
}

int main(){
    int n,s,i,j,*visited,*queue,f=0,r=-1,count=0;
    int g[20][20];
    cout<<"Enter the number of vertices"<<endl;
    cin>>n;
    visited=new int[n];queue=new int[n];
    cout<<"Enter the values from the adjacency matrix of the graph"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>g[i][j];
        }
    }
    for(i=0;i<n;i++){visited[i]=0;queue[i]=0;}
    cout<<"Enter the node to get all the nodes that are reachable from it"<<endl;
    cin>>s;
    bfs(g,s-1,queue,visited,f,r,count,n);
    return 0;
}
