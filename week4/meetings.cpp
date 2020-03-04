#include<bits/stdc++.h>

using namespace std;

struct meetings{
    int start;
    int end;
    int pos;
};
void isort(struct meetings m[],int n){
    int i,j;
    struct meetings item;
    for(i=1;i<n;i++){
        j=i-1;
        item=m[i];
        while(j>=0 && m[j].end>item.end){
            m[j+1]=m[j];
            j--;
        }
        m[j+1]=item;
    }
}

void maxMeetings(int s[],int f[],int n){
    struct meetings *m=new struct meetings[n];
    int i,limit,a[n],j=1,count=1;

    for(i=0;i<n;i++){
        m[i].start=s[i];
        m[i].end=f[i];
        m[i].pos=i+1;
    }
    isort(m,n);

    a[0]=m[0].pos;
    limit=m[0].end;
    for(i=1;i<n;i++){
        if(m[i].start>=limit){
            a[j]=m[i].pos;j++;count++;limit=m[i].end;
        }
    }
    for(i=0;i<count;i++){
        cout<<a[i]<<" ";
    }
    cout<<"Total number of meetings: "<<count;

}

int main(){
    int *s,*f,n,i;
    cout<<"Enter the number of meetings"<<endl;
    cin>>n;
    s=new int[n];f=new int[n];
    cout<<"Enter the starting times of the meetings\n";
    for(i=0;i<n;i++){
        cin>>s[i];
    }
    cout<<"Enter the ending times of the meeting in the same order\n";
    for(i=0;i<n;i++){
        cin>>f[i];
    }

    maxMeetings(s,f,n);
    return 0;
}
//output
/*
Enter the number of meetings
6
Enter the starting times of the meetings
1 3 0 5 8 5
Enter the ending times of the meeting in the same order
2 4 6 7 9 9
1 2 4 5 Total number of meetings: 4

Enter the number of meetings
8
Enter the starting times of the meetings
75250 50074 43659 8931 11273 27545 50879 77924
Enter the ending times of the meeting in the same order
112960 114515 81825 93424 54316 35533 73383 160252
6 7 1 Total number of meetings: 3
*/
