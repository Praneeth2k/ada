#include<iostream>
using namespace std;
int binse(int arr[],int l,int h,int key){
    int mid=(l+h)/2,index;
    if(l>h){
        return -1;
    }
    if(arr[mid]==key){
        return mid;
    }
    if(arr[mid]<key){
        index=binse(arr,mid+1,h,key);
    }
    else
    {
        index=binse(arr,l,mid-1,key);
        
    }
    return index;
}
int find_pivot(int arr[],int l,int h){
    int mid;
    if(l>h){
        return -1;
    }
    mid=(l+h)/2;
    if(arr[mid]>arr[mid+1]){
        return mid;
    }
    if(arr[mid]<arr[mid-1]){
        return mid-1;
    }
    if(arr[0]>arr[mid]){
        return find_pivot(arr,0,mid-1);
    }
    return find_pivot(arr,mid+1,h);

}
int piv_binse(int arr[],int l,int h,int key){
    int pivot=find_pivot(arr,l,h);

    if(pivot==-1){
        return binse(arr,l,h,key);
    }
    if(arr[pivot]==key){
        return pivot;
    }
    if(arr[0]>key){
        return binse(arr,pivot+1,h,key);
    }
    return binse(arr,0,pivot-1,key);

}

int main(){
    int n,i,*arr,key,index;
    cout<<"Enter the number of elements"<<endl;
    cin>>n;
    arr=new int[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Key element?"<<endl;
    cin>>key;

    index=piv_binse(arr,0,n-1,key);
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
4 5 6 7 8 9 0 1 2 3
Key element?
6
Element found at position 3


Enter the number of elements
8
5 10 11 23 34 1 2 4
Key element?
1
Element found at position 6

Enter the number of elements
6
5 7 9 10 2 3
Key element?
6
Element not found
*/
