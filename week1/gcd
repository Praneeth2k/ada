#include<iostream>

using namespace std;

int gcd(int m,int n);
int main(){
	int m,n,r,a;
	cout<<"Enter the two numbers\n";
	cin>>m>>n;
	a=gcd(m,n);
	
	cout<<"The gcd is "<<a;
	return 0;
}
int gcd(int m,int n){
	if(n==0) 
		return m;
	else return gcd(n,m%n);
}
