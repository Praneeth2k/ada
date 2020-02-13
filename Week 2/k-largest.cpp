#include<iostream>
#include<cstdlib>

using namespace std;

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void bubble_sort(int arr[],int n){
	int i=0,j=0;
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				swap(&arr[j],&arr[j+1]);
		   	}
		}
	}
	
}
			

int main(){
	int n,i,*a,k;

	
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	cout<<"Enter the elements"<<endl;
	a=new int[n];
	for(i=0;i<n;i++){
		cin>>a[i];
	}
	
	
	bubble_sort(a,n);
	cout<<"Enter the value of k to get k largest element"<<endl;
	cin>>k;
	for(i=n-1;i>=n-k;i--){
	    cout<<a[i]<<" ";
	}
	
	return 0;
}
