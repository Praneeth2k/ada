#include<iostream>

using namespace std;

int fibonacci(int n){
	if(n==0) return 0;
	if(n==1) return 1;
	return fibonacci(n-1)+fibonacci(n-2);
}

int main(){
	int f,n;
	cout<<"Enter a number n to find nth fibonacci number\n"<<endl;
	cin>>n; 
	f=fibonacci(n);
	cout<<"\n"<<f<<endl;
}
