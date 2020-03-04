#include<iostream>
#include<ctime>
#include<algorithm>
using namespace std;

int main(){
    clock_t t;
    int *a,n,j,temp,i;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    a=new int[n];
    
    for(i=0;i<n;i++){
        a[i]=rand()/10;
    }
    t=clock();
    for(i=1;i<n;i++){
        j=i-1;
        temp=a[i];
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];j--;
        }
        a[j+1]=temp;
    }
    t=clock()-t;
    cout<<"The sorted array is"<<endl;
    for(i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<"Time take to sort is: "<<t;
}