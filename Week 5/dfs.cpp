//DFS
#include<iostream>

using namespace std;
int ans[20],k=0,c=0,stack[20],topo[20],p=-1,s=-1;

void dfs(int g[20][20],int v,int n,int visited[],int cycle[]){
        int cy[n],i,j,f;
        cycle[v]=1;
        for(i=0;i<n;i++){cy[i]=cycle[i];}
        visited[v]=1;stack[++s]=v;
        cout<<v+1<<" ";ans[k]=v+1,k++;
        for(i=0;i<n;i++){
            
            for(j=0;j<n;j++){cycle[j]=cy[j];}
            if(g[v][i]==1){
                if(cycle[i]==1){
                    c=1;
                }
                if(visited[i]==0){
                    dfs(g,i,n,visited,cycle);
                    topo[++p]=stack[s];s--;
                }
                
                
            }
        }
        
        
}


void DFS(int arr[20][20],int n){
    int visited[n]={0},cycle[n]={0},i;
    for(i=0;i<n;i++){
        if(visited[i]==0){
            dfs(arr,i,n,visited,cycle);
            topo[++p]=stack[s];s--;
        }
    }
}
  
            
    
    

int main(){
	int *stack,n,arr[20][20],i,j,f,count=0;
	cout<<"Enter the number of vertices: ";
	cin>>n;
	
	cout<<"Enter the values for the adjecency matrix"<<endl;
	for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
	        cin>>arr[i][j];
	    }
	}
    

	cout<<"DFS order:-\n";
	DFS(arr,n);
    if(c==1){
        cout<<"\nCycle is present"<<endl;
    }
    else{cout<<"\nCycle not present"<<endl;}

    for(j=0;j<n;j++){
        f=0;
        for(i=0;i<n;i++){
            if(arr[i][j]==0){
                f=0;
            }
            else{f=1;break;}
        }
        if(f==0) count++;
    }
    if(count>=2){cout<<"Graph is disconnected\n";}
    else cout<<"Graph is connected\n";
    if(c==1){cout<<"Topological sorting is not possible since a cycle is present"<<endl;}
    else{
        cout<<"TOPOLOGICAL SORTING ORDER:-\n";
        for(i=n-1;i>=0;i--){cout<<topo[i]+1<<" ";}
    }
}

/*
Output 1:
Enter the number of vertices: 10
Enter the values for the adjecency matrix
0 1 1 1 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 0 0
0 0 0 0 0 0 0 1 0 1
0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0

1 2 5 8 9 3 6 4 7 10
Cycle not present
Graph is connected
TOPOLOGICAL SORTING ORDER:-
1 4 7 10 3 6 2 5 8 9

Cycle is present,connected
0 1 1 1 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1 0 0 
0 0 0 0 0 0 0 1 0 0 
0 0 0 1 0 0 0 1 0 1 
0 0 0 0 0 0 0 0 1 0 
0 0 0 0 0 0 0 0 0 0 
0 0 0 0 0 0 0 0 1 0


Disconnected 
0 1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0 0 0
0 0 0 0 0 0 1 0 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 1 0 0 0 0
0 0 0 0 0 0 0 1 0 1 0 0
0 0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 0 0 0 0 1
0 0 0 0 0 0 0 0 0 0 0 0 
*/