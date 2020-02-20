#include<iostream>

using namespace std;

int main(){
	int n,m,i,j,f=0;
	string text,pattern;
	cout<<"Enter the text string"<<endl;
	cin>>text;
	cout<<"Enter the pattern string"<<endl;
	cin>>pattern;
	n=text.size();
	m=pattern.size();
	for(i=0;i<=n-m;i++){
		j=0;
		while(j<m&&text[i+j]==pattern[j]){j++;}
		if(j==m){
			cout<<"Pattern is found at position "<<i<<endl;
			f=1;
			break;
		}
	}
	if(f==0){cout<<"Not present"<<endl;}
}
	
