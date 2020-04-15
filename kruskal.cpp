#include<iostream>
using namespace std;

int parent[20];

int find(int i){
	while (parent[i]!=i)
	        i = parent[i];
	return i;
}
void unionv(int i, int j){
	int a = find(i);
	int b = find(j);
   	parent[a] = b;
}
void kruskals(int g[][20], int n){
	int mincost = 0,c = 0,i,j;
	for(i=1;i<n;i++)
        	parent[i] = i;
	while(c<n-1)
	{
	        int min = 10000,it = -1,jt = -1;
	        for(i=1;i<=n;i++)
		{
	        	for(j=1;j<=n;j++)
			{
		                if(find(i)!=find(j) && g[i][j]<min)
				{
                    			min = g[i][j];
                    			it = i;
                    			jt = j;
                		}
            		}
        	}
  		unionv(it,jt);
		c++;
        	cout<<it<<" - "<<jt<<"  :  "<<min<<endl;
        	mincost += min;
    	}
    	printf("\nMinimum cost = %d",mincost);
}






int main(){
    int i, j, ele, n;
    int g[20][20];
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
    }
    cout<<"Edge     Weight"<<endl;


    kruskals(g, n);
    return 0;
}
/*
output
Enter the number of vertices
9
Enter the weighted matrix(Enter -1 if edge does not exist)
-1 4 -1 -1 -1 -1 -1 8 -1
4 -1 8 -1 -1 -1 -1 11 -1
-1 8 -1 7 -1 4 -1 -1 2
-1 -1 7 -1 9 14 -1 -1 -1
-1 -1 -1 9 -1 10 -1 -1 -1
-1 -1 4 14 10 -1 2 -1 -1
-1 -1 -1 -1 -1 2 -1 1 6
8 11 -1 -1 -1 -1 1 -1 7
-1 -1 2 -1 -1 -1 6 7 -1

Edge     Weight
7 - 8  :  1
3 - 9  :  2
6 - 7  :  2
1 - 2  :  4
3 - 6  :  4
3 - 4  :  7
1 - 8  :  8
4 - 5  :  9

Minimum cost = 37
*/