#include<iostream>
#include<ctime>

using namespace std;
int reclin(int arr[],int front,int rear,int key){
    if(front>rear){
        return -1;
    }
    if(arr[front]==key)
        return front;
    if(arr[rear]==key)
        return rear;
    return reclin(arr,front+1,rear-1,key);

}
int main(){
    clock_t t;
    int n,i,*arr,key,index;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    arr=new int[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Key element?"<<endl;
    cin>>key;
    t=clock();
    index=reclin(arr,0,n-1,key);
    t=clock()-t;
    if(index==-1){
        cout<<"Element not found"<<endl;
    }
    else 
        cout<<"Element found at position "<<index+1;
    
    return 0;
}
//output
/*

Enter the number of elements
10
2 3 1 4 5 8 10 22 11 12
Key element?
4
Element found at position 4

Enter the number of elements
6
1 6 4 2 9 0
Key element?
3
Element not found
*/