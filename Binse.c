#include<stdio.h>
int main(){
    int i,t,n,ele,a[100],l,h,mid,j;
    printf("Enter the number of test cases\n");
    scanf("%d",&t);
    for(i=0;i<t;i++){
    	printf("Enter the number of elements and the element to search for\n");
    	scanf("%d%d",&n,&ele);
    	l=0;
    	h=n-1;
    	printf("Enter the elements\n");
    	for(j=0;j<n;j++){
    	    scanf("%d",&a[i]);
    	}
    	while(l<=h){
    	    mid=(l+h)/2;
    	    if (a[mid]==ele){
    	        printf(" 1 (Element is found) ");
    	        break;
    	    }
    	    else if(a[mid]<ele)
				l = mid+1;
			else
				h = mid-1;
		}
		if(l>h)
			printf(" -1 (Element is not present) ");
    }
    	
	return 0;
}
