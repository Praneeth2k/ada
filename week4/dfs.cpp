//DFS
#include<iostream>

using namespace std;
int ans[10],k;
void dfs(int g[20][20],int v,int n,int visited[]){
        visited[v]=1;
        int i;
        cout<<v+1<<" ";ans[k]=v+1;
        for(i=0;i<n;i++){
            if(g[v][i]==1){
                if(visited[i]==0){
                    dfs(g,i,n,visited);
                }
            }
        }
}


void DFS(int arr[20][20],int n){
    int visited[n]={0},i;
    for(i=0;i<n;i++){
        if(visited[i]==0){
            dfs(arr,i,n,visited);
        }
    }
}
  
            
    
    

int main(){
	int *stack,n,arr[20][20],i,j;
	cout<<"Enter the number of vertices";
	cin>>n;
	
	cout<<"Enter the values for the adjecency matrix"<<endl;
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        cin>>arr[i][j];
	    }
	}
	
	DFS(arr,n);
	for(i=0;i<n;i++){
	    if(i
}
	
