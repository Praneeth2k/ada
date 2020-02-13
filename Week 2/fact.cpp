#include<iostream>

using namespace std;
int factorial(int f){
	if(f==0) return 1;
	return f*factorial(f-1);
}
int main(){
	int f,ans;
	cout<<"Enter a number to find it's factorial"<<endl;
	cin>>f;
	ans=factorial(f);
	cout<<"\n"<<ans<<endl;
}
