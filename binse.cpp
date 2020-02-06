#include<iostream>

using namespace std;

int main(){
    int k,n,i,a[100],l=0,h,m,p,q;
    cout<<"Enter the number of elements\n";
    cin>>n;
    cout<<"Enter the elements in sorted order\n";
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    
    cout<<"Enter the key";
    cin>>k;
    h=n-1;
    
    while(l<=h){
    	m=(l+h)/2;
    	if(a[m]==k){
    	    p=m;
    	    q=m;
    	    while(a[p]==k){
    	    	p--;
    	    }
    	    
    	    while(a[q]==k){
    	        q++;
    	    }
    	    break;
    	}
    	if(k>a[m])
    	    l=m+1;
    	if(k<a[m])
    	    h=m-1;    
     }
     
    if(l>h)
        cout<<"Element not found ";
        
    else
        cout<<"\nElement found ";
        cout<<"\nFirst occurence at position: "<<p+2;
        cout<<"\nLast occurence at position: "<<q;
        cout<<"\nNumber of occurences: "<<q-p-1;  
        return 0;
}  
    
    	
