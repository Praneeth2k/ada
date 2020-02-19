#include<iostream>
#include<ctime>

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
	int n,i,*a;
	clock_t t;
	
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	cout<<"Enter the elements"<<endl;
	a=new int[n];
	for(i=0;i<n;i++){
		a[i]=rand()/10000000;
	}
	t=clock();
	bubble_sort(a,n);
	t=clock()-t;
	for(i=0;i<n;i++){
	    cout<<a[i]<<" ";
	}
	cout<<"\nTime required to perform bubble sort is " <<t<<endl;
	
	return 0;
}
