#include<iostream>
using namespace std;
int recbin(int arr[],int l,int h,int key){
    int mid=(l+h)/2,index;
    if(l>h){
        return -1;
    }
    if(arr[mid]==key){
        return mid;
    }
    if(arr[mid]<key){
        index=recbin(arr,mid+1,h,key);
    }
    else
    {
        index=recbin(arr,l,mid-1,key);
        
    }
    return index;
}
int main(){
    int n,i,*arr,key,l;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    arr=new int[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Key element?"<<endl;
    cin>>key;

    l=recbin(arr,0,n-1,key);
    if(l==-1){
        cout<<"Element not found"<<endl;
    }
    else 
        cout<<"Element found at position "<<l+1;
    
    return 0;
}
//output
/*

Enter the number of elements
5
1 2 3 4 5
Key element?
2
Element found at position 2

Enter the number of elements
6
1 3 5 9 10 11
Key element?
2
Element not found


Enter the number of elements
10
3 4 5 6 7 8 9 10 11 12
Key element?
12
Element found at position 10

Enter the number of elements
2
1 2
Key element?
1
Element found at position 1
*/