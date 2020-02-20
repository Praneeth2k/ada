#include<iostream>
#include<ctime>

using namespace std;

void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
int main(){
	int *a;
	int i,j,n,pos,small;
	cout<<"Enter the number of elements"<<endl;
	cin>>n;
	a=new int[n];
	cout<<"Enter the elements"<<endl;
	for(i=0;i<n;i++){
		a[i]=rand()%1000;
	}
	clock_t t=clock();
	
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
	t=clock()-t;
	cout<<"The sorted elements are"<<endl;
	for(i=0;i<n;i++){
		cout<<a[i]<<" ";
	}
	cout<<"The time taken to sort is "<<t;
}
