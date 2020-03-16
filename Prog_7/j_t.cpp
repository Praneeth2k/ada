#include<iostream>

using namespace std;

int find_mobile_pos(int arr[],int dir[],int n){
    int mobile_pos=-1,mob_ele=0,x;
    for(int i=0;i<n;i++){
        x=i+dir[i];
        if(x==-1 || x==n){
            continue;
        }
        if(arr[x]<arr[i]){
            if(arr[i]>mob_ele){
                mobile_pos=i;mob_ele=arr[i];
            }
        }
    }
    return mobile_pos;
}

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void johnson_trotter(int n){
    int arr[n],dir[n],i,d,mob;
    for(i=0;i<n;i++){arr[i]=i+1;dir[i]=-1;}
    for(i=0;i<n;i++){cout<<arr[i]<<" ";}cout<<"    ";
    d=find_mobile_pos(arr,dir,n);
    while(d!=-1){
        mob=arr[d];
        swap(&arr[d],&arr[d+dir[d]]);
        swap(&dir[d],&dir[d+dir[d]]);
        for(i=0;i<n;i++){cout<<arr[i]<<" ";}
        cout<<"     ";

        for(i=0;i<n;i++){
            if(arr[i]>mob){
                dir[i]*=-1;
            }
        }
        d=find_mobile_pos(arr,dir,n);
    }


    

}

int main(){
    int n;
    cout<<"Enter n"<<endl;
    cin>>n;
    johnson_trotter(n);
}

/*
Output 1:
Enter n
3
1 2 3      1 3 2      3 1 2      3 2 1      2 3 1      2 1 3

Output 2:
Enter n
4
1 2 3 4      1 2 4 3      1 4 2 3      4 1 2 3      4 1 3 2      1 4 3 2      
1 3 4 2      1 3 2 4      3 1 2 4      3 1 4 2      3 4 1 2      4 3 1 2      
4 3 2 1      3 4 2 1      3 2 4 1      3 2 1 4      2 3 1 4      2 3 4 1      
2 4 3 1      4 2 3 1      4 2 1 3      2 4 1 3      2 1 4 3      2 1 3 4

*/
