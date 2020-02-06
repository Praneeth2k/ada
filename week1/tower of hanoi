#include<iostream>
#include<algorithm>
using namespace std;

void tower_of_hanoi(int n,char src,char temp,char dest){
	if(n==1){
		cout<<"mov disk 1 from "<<src<<" to "<<dest<<"\n";
		return;
	}
	tower_of_hanoi(n-1,src,dest,temp);
	cout<<"move disk "<<n<<" from "<<src<< " to "<<dest<<"\n";
	tower_of_hanoi(n-1,temp,src,dest);
} 	

int main(){
	int n;
	cout<<"Enter the number of disks\n";
	cin>>n;
	tower_of_hanoi(n,'A','B','C');
	return 0;
}	
	
