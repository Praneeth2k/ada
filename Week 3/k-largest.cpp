#include<iostream>


using namespace std;

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main(){
	int *a;
	int i,j,n,k,pos,small;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	a=new int[n];
	cout<<"Enter the elements"<<endl;
	for(i=0;i<n;i++){
		a[i]=rand()%1000;
	}
	
	
	for(i=0;i<n-1;i++){
		small=a[i];
		pos=i;
		for(j=i+1;j<n;j++){
			if(a[j]<small){
				small=a[j];
				pos=j;
			}
		}
		swap(&a[i],&a[pos]);
	}
	cout<<"Enter the value of k to get k largest elements"<<endl;
	cin>>k;
	
	cout<<"The k largest elements are"<<endl;
	for(i=n-1;i>=n-k;i--){
		cout<<a[i]<<" ";
	}
	
}
