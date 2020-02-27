#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;
void swap(int *a,int *b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int *arr,n,i,flag;
    clock_t t;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    cout<<"Enter the elements\n";
    arr=new int[n];
    
    for(i=0;i<n;i++){
        arr[i]=rand();
    }
    t=clock();
    for(i=0;i<n-2;i++){
        
        for(int j=0;j<n-2-i;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
    
    t=clock()-t;
    cout<<"Sorted array-->\n";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"Time taken: "<<t;
}
